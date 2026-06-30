import os
import math
import pygame
import pygame.freetype

from .button import Button

# Colors
BLUE = (28, 107, 160)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (200, 30, 30)       # Player (human)
YELLOW = (240, 230, 70)   # AI

# Image file
IMAGE_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "images")

class CMMenu:

    def __init__(self, surf, mgn = 20):
        self.surface = surf
        self.margin = mgn # Margin around edge of screen

        self.heading = None
        self.heading_rect = None
        self.position_heading("CAPTAIN'S MISTRESS")

        self.options = self.MenuOptions()

        # Make menu buttons
        self.buttons = []
        one_player_button = Button("Human vs AI", (0,0), self.options.one_player)
        self.buttons.append(one_player_button)
        two_player_button = Button("Human vs Human", (0,0), self.options.two_player)
        self.buttons.append(two_player_button)
        close_button = Button("Return to Launcher", (0,0), self.options.close_game)
        self.buttons.append(close_button)
        self.position_buttons()
        self.draw_buttons()


    class MenuOptions:
        """
        Menu button function calls
        """

        def __init__(self):
            self.option = "menu"

        def one_player(self):
            self.option = "one"

        def two_player(self):
            self.option = "two"

        def close_game(self):
            self.option = "close"


    def draw_background(self):

        bg = pygame.image.load(os.path.join(IMAGE_DIR,"Background.jpg")) # Background image from Maplemoths, CC BY 4.0 <https://creativecommons.org/licenses/by/4.0>, via Wikimedia Commons
        self.surface.blit(bg,(0,0))



    def position_heading(self, heading_text):

        surf = self.surface
        font = pygame.font.SysFont(None, 72)

        self.heading = font.render(heading_text, 1, YELLOW)

        rect = self.heading.get_rect()

        x = surf.get_width() // 2
        y = rect.height // 2 + self.margin

        rect.center = (x, y)

        self.heading_rect = rect


    def draw_heading(self):

        h = self.heading
        rect = self.heading_rect
        self.surface.blit(h, rect)



    def position_buttons(self):
        """
        self.position_buttons()
        Sets button positions
        """
        surf = self.surface
        buttons = self.buttons

        r = self.heading_rect.height # Heading height
        h = surf.get_height() - r
        dy = h // (len(buttons) + 1) # Vertical spacing between buttons

        x = math.floor(surf.get_width() / 2) # Position buttons in middle of screen horizontally
        # y = math.floor(surf.get_height() / (len(buttons) + 1)) # Top button position
        # dy = y
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


    def draw_menu(self):
        self.draw_background()

        self.draw_heading()

        self.draw_buttons()






