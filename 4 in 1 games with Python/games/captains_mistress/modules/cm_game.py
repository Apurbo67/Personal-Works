import pygame
import os

from .draw_menu import CMMenu
from .draw_graphics import GameGraphics
from .game_mechanics import GameMechanics
from .cm_ai import CMAIPlayer
from .draw_end import CMEndScreen


# Colors
BLUE = (28, 107, 160)
BLACK = (0, 0, 0)
RED = (200, 30, 30)       # Player (human)
YELLOW = (240, 230, 70)   # AI


# Image file
IMAGE_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "images")


class CMGame:

    def __init__(self, surf):
        self.surface = surf
        self.state = "menu"
        self.turn = 0 # Current player's turn
        self.n_players = 0 # Number of players

        self.menu = CMMenu(surf)
        self.graphics = None
        self.end_screen = None
        self.mechanics = None
        self.ai_player = None


    def step(self):
        """
        self.step()
        performs next step in Captain's Mistress loop
        """
        match self.state:
            case "menu": # Menu screen
                self.step_menu()
            case "start1": # Start 1 player (human vs AI) game
                self.start_game(1)
            case "start2": # Start 2 player (human vs human) game
                self.start_game(2)
            case "input": # Get keyboard input
                self.get_input()
            case "ai": # AI player turn
                self.ai_turn()
            case "drop": # Drop piece
                self.step_drop()
            case "check": # Check for win or stalemate
                self.check_terminal()
            case "end":
                self.step_end()
            case "quit":
                pass


    def draw_background(self):
        bg = pygame.image.load(os.path.join(IMAGE_DIR,"Background.jpg"))
        self.surface.blit(bg,(0,0))


    def step_menu(self):
        """
        self.step_menu()
        performs next step in menu loop
        """
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.state = "quit"
                return
            else:
                for button in self.menu.buttons:
                    button.handle_event(event)

        match self.menu.options.option:
            case "close":
                self.state = "quit"
            case "menu":
                self.menu.draw_menu()
                pygame.display.flip()
            case "one":
                self.state = "start1"
            case "two":
                self.state = "start2"


    def start_game(self, n_pl = 2):
        """
        self.start_game(n_pl)
        Start Captain's Mistress game
        :param n_pl: Number of human players
        """
        surf = self.surface
        self.n_players = min([n_pl, 2]) # limit number of players to two
        self.graphics = GameGraphics(surf)  # graphics object for drawing game graphics
        self.mechanics = GameMechanics()  # mechanics object for handling game mechanics

        if n_pl == 1:
            self.ai_player = CMAIPlayer(self.mechanics)
            if self.mechanics.current_player == 1:
                self.state = "ai"
                return

        self.state = "input"


    def get_input(self):
        """
        self.step_game()
        Performs next step in game loop
        """
        events = pygame.event.get() # get events
        persist = False
        for event in events:
            if event.type == pygame.QUIT: # handle quit event
                self.state = "quit"
                return
            if event.type == pygame.KEYDOWN: # handle human player moves
                keys = pygame.key.get_pressed()
                if keys[pygame.K_LEFT]:
                    moved = self.mechanics.move_piece("left")
                    self.graphics.left_arrow = 1
                    persist = True
                elif keys[pygame.K_RIGHT]:
                    moved = self.mechanics.move_piece("right")
                    self.graphics.right_arrow = 1
                    persist = True
                elif keys[pygame.K_RETURN] or keys[pygame.K_SPACE]:
                    # dropped = self.mechanics.drop_piece()
                    # if dropped:
                    #     self.state = "check"
                    drop = self.mechanics.start_drop()
                    if drop:
                        self.state = "drop"

        self.graphics.draw_cm(self.mechanics.pieces)
        pygame.display.flip()

        if persist:
            pygame.time.wait(300)  # Visual persistence

            # Reset arrows
            self.graphics.left_arrow = 0
            self.graphics.right_arrow = 0


    def ai_turn(self):
        """
        self.step_game()
        Performs next step in game loop
        """
        events = pygame.event.get() # get events
        for event in events:
            if event.type == pygame.QUIT: # handle quit event
                self.state = "quit"
                return

        drop = self.ai_player.take_turn()
        if drop:
            self.state = "drop"

        self.graphics.draw_cm(self.mechanics.pieces)
        pygame.display.flip()


    def step_drop(self):
        drop = self.mechanics.move_piece("down")

        if not drop:
            self.state = "check"
            return

        self.graphics.draw_cm(self.mechanics.pieces)
        pygame.display.flip()
        pygame.time.wait(300)  # Visual persistence


    def check_terminal(self):
        terminal = self.mechanics.is_terminal_node()
        if terminal:
            self.state = "end"
            if not self.end_screen is None:
                self.end_screen.options.option = "end"

        else:
            self.mechanics.add_piece()
            if self.n_players == 1 and self.mechanics.current_player == 1:
                self.state = "ai"
            else:
                self.state = "input"


    def step_end(self):
        """
        self.step_end()
        Performs next step in end screen loop
        """

        if self.end_screen is None: # Initialise end screen
            surf = self.surface
            w = self.mechanics.winner
            ai = self.n_players == 1
            colours = self.graphics.player_colours
            self.end_screen = CMEndScreen(surf, w, ai, colours)

        for event in pygame.event.get():
            if event.type == pygame.QUIT: # handle quit event
                self.state = "quit"
                return
            else:
                for button in self.end_screen.buttons:
                    button.handle_event(event)

        match self.end_screen.options.option:
            case "end":
                self.end_screen.draw_end()
                pygame.display.flip()
            case "replay":
                if self.n_players == 1:
                    self.state = "start1"
                elif self.n_players == 2:
                    self.state = "start2"
            case "menu":
                self.state = "menu"
                self.end_screen = None
                if not self.menu is None:
                    self.menu.options.option = "menu"

