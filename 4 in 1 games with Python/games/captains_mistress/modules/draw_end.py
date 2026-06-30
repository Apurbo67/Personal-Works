import os
import pygame

from .button import Button

# Colors
BLUE = (28, 107, 160)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (200, 30, 30)       # Player (human)
YELLOW = (240, 230, 70)   # AI

# Image file
IMAGE_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "images")


class CMEndScreen:

    def __init__(self, surf, w, ai, colours, mgn = 20):
        """
        end_screen = CMEndScreen(surf, w, ai, colours)
        Creates end screen object for Captain's Mistress game
        :param surf: Pygame display object
        :param w: Winning player, equal to -1 for a draw
        :param ai: True for AI vs human game, False otherwise
        :param colours: List of player colours
        :param mgn: Desired margin around playing area. Default value of 20 pixels
        """
        self.surface = surf
        self.winner = w
        self.ai_game = ai
        self.player_colours = colours
        self.margin = mgn

        self.heading_label = None
        self.heading_rect = None
        self.make_heading()

        self.options = self.EndOptions()
        self.buttons = []
        replay_button = Button("Play Again", (0,0), self.options.replay)
        self.buttons.append(replay_button)
        menu_button = Button("Return to Game Menu", (0,0), self.options.menu)
        self.buttons.append(menu_button)
        self.position_buttons()


    class EndOptions:
        """
        End screen button function calls
        """

        def __init__(self):
            self.option = "end"

        def replay(self):
            self.option = "replay"

        def menu(self):
            self.option = "menu"


    def draw_background(self):

        bg = pygame.image.load(os.path.join(IMAGE_DIR,"Background.jpg")) # Background image from Maplemoths, CC BY 4.0 <https://creativecommons.org/licenses/by/4.0>, via Wikimedia Commons
        self.surface.blit(bg,(0,0))


    def make_heading(self):
        """
        self.draw_end()
        Draws end screen
        """
        surf = self.surface

        ai = self.ai_game
        w = self.winner
        font = pygame.font.SysFont("Arial", 72)
        label = font.render("Draw!", 1, WHITE) # Initialise label with draw result

        if w>=0: # Non-draw result
            if ai:
                if w == 0:
                    label = font.render("You win!", 1, RED)
                elif w == 1:
                    label = font.render("AI wins!", 1, YELLOW)
            else:
                colour = self.player_colours[w]
                if colour == RED:
                    label = font.render("Red wins!", 1, RED)
                elif colour == YELLOW:
                    label = font.render("Yellow wins!", 1, YELLOW)

        label_rect = label.get_rect()

        x = surf.get_width() // 2
        y = self.margin + label_rect.height // 2

        label_rect.center = (x, y)

        self.heading_label = label
        self.heading_rect = label_rect


    def draw_heading(self):

        h = self.heading_label
        rect = self.heading_rect
        self.surface.blit(h, rect)


    def position_buttons(self):

        surf = self.surface
        buttons = self.buttons

        r = self.heading_rect.height  # Heading height
        h = surf.get_height() - r
        dy = h // (len(buttons) + 1)  # Vertical spacing between buttons

        x = surf.get_width() // 2  # Position buttons in middle of screen horizontally
        y = r + dy

        for button in buttons:
            button.pos = (x, y)
            y += dy


    def draw_buttons(self):
        """
        self.draw_buttons()
        Draws buttons on menu screen
        """
        surf = self.surface
        buttons = self.buttons

        for button in buttons:
            button.draw(surf)


    def draw_end(self):
        """
        self.draw_end()
        Draws end screen
        """
        self.draw_background()
        self.draw_heading()
        self.draw_buttons()










