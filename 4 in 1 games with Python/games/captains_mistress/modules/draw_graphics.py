import pygame
import math


# Colors
BLUE = (28, 107, 160)
LIGHT_BLUE = (128, 128, 255)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (200, 30, 30)       # Player (human)
YELLOW = (240, 230, 70)   # AI


class GameGraphics:
    """Captain's Mistress game graphics
    Includes graphics size parameters and drawing methods"""

    def __init__(self, surf, pl = 2, mgn = 20):
        """
        __init__(self, screen, mgn = 20)
        Initialises game_graphics object for Captain's Mistress game
        :param surf: Pygame display object
        :param pl: Number of players
        :param mgn: Desired margin around playing area. Default value of 20 pixels
        """
        self.surface = surf # Pygame display surface
        self.margin = mgn # Margin from playing area to edge of screen
        self.n_x = 7 # Number of horizontal piece positions
        self.n_y = 6 # Number of vertical piece positions

        self.left_arrow = 0 # Left arrow state
        self.right_arrow = 0 # Right arrow state

        self.piece_radius = 1 # playing piece radius
        self.d_x = 2 # horizontal piece separation
        self.d_y = 2 # vertical piece separation
        self.calculate_piece_radius()

        self.x_grid = [] # list of horizontal grid positions
        self.y_grid = [] # List of vertical grid positions
        self.calculate_grid()

        self.n_players = pl # Number of players
        self.player_colours = [] # List of player colours
        self.assign_colours()


    def calculate_piece_radius(self):
        """
        self.calculate_piece_radius()
        Calculates playing piece radius based on Pygame display size, margin size and playing grid dimensions
        """
        # get playing area dimensions
        w = self.surface.get_width() - 2 * self.margin
        h = self.surface.get_height() - 2 * self.margin

        # maximum piece diameters
        dx = w / self.n_x
        dy = h / (self.n_y + 1) # Add row above for dropping pieces
        self.d_x = math.floor(dx)
        self.d_y = math.floor(dy)

        # radius calculation
        self.piece_radius = math.floor(0.9 * min([dx,dy])/2)


    def calculate_grid(self):
        """
        self.calculate_grid()
        populates x and y grid positions
        """
        nx = self.n_x
        ny = self.n_y
        dx = self.d_x
        dy = self.d_y

        # Populate horizontal positions
        if nx > 0:
            x = self.margin + math.floor(dx / 2)
            self.x_grid.append(x) # Leftmost grid position

            for k in range(1,nx):
                x += dx
                self.x_grid.append(x)

        # Populate vertical positions
        if ny > 0:
            # get playing area height
            h = self.surface.get_height()

            y = h - self.margin - math.floor(dy / 2) # Bottom grid position
            self.y_grid.append(y)

            for k in range(1, ny + 1):
                y -= dy
                self.y_grid.append(y)


    def assign_colours(self):
        """
        self.assign_colours()
        Assigns unique colour to each player
        """
        # colours = ["red", "yellow"] # list of colours
        colours = [RED, YELLOW]
        pl = self.n_players
        self.player_colours = [] # reset player colour list to empty

        for k in range(min(len(colours),pl)):
            self.player_colours.append(colours[k])


    def draw_piece(self, x, y, colour = BLACK):
        """
        self.draw_piece(x, y, colour)
        Draw playing piece
        :param x: horizontal piece centre pixel position
        :param y: vertical piece centre pixel position
        :param colour: piece colour, default value red
        """
        surf = self.surface
        r = self.piece_radius
        pygame.draw.circle(surf,colour,(x,y),r)


    def place_piece(self, x_i, y_i, colour = "red"):
        """
        self.place_piece(self, x_i, y_i, colour)
        Draw playing piece on grid location
        :param x_i: playing grid column number
        :param y_i: playing grid row number
        :param colour: piece colour, default value red
        """
        x = self.x_grid[x_i]
        y = self.y_grid[y_i]
        self.draw_piece(x, y, colour)


    def draw_arrows(self):

        font = pygame.font.SysFont("monospace", 72)
        big_font = pygame.font.SysFont("monospace", 96)

        left_text = "\u2190" # Left arrow string
        right_text = "\u2192" # Right arrow string

        big_left_label = big_font.render(left_text, 1, WHITE) # Left arrow pressed
        big_right_label = big_font.render(right_text, 1, WHITE)
        big_left_rect = big_left_label.get_rect()
        big_right_rect = big_right_label.get_rect()
        x_left = self.margin + big_left_rect.width // 2 # left arrow horizontal position
        x_right = self.surface.get_width() - x_left # right arrow horizontal position
        y = self.margin + big_left_rect.height // 2 # vertical arrow position

        if self.left_arrow == 0:
            left_label = font.render(left_text, 1, WHITE)
            left_rect = left_label.get_rect()
        else:
            left_label = big_left_label
            left_rect = big_left_rect

        if self.right_arrow == 0:
            right_label = font.render(right_text, 1, WHITE)
            right_rect = right_label.get_rect()
        else:
            right_label = big_right_label
            right_rect = big_right_rect

        left_rect.center = (x_left, y)
        right_rect.center = (x_right, y)
        self.surface.blit(left_label, left_rect)
        self.surface.blit(right_label, right_rect)


    def draw_top(self):
        """
        self.draw_top()
        Draws top area of Captain's Mistress playing surface
        """
        h = self.margin + self.d_y # height of top section
        surf = self.surface
        w = surf.get_width() # screen width
        rect = pygame.Rect((0, 0), (w, h))
        pygame.draw.rect(surf, BLACK, rect)
        self.draw_arrows()


    def draw_empty_slots(self):
        """
        self.draw_empty_slots()
        Draws empty piece slots
        """
        for x in self.x_grid:
            for y in self.y_grid:
                self.draw_piece(x, y, BLACK)


    def draw_cm(self, pieces):
        """Draw Captain's Mistress playing surface
        pieces: list of GameMechanics.PlayingPiece objects representing played pieces"""
        surf = self.surface
        colours = self.player_colours
        surf.fill(BLUE)
        self.draw_top()
        self.draw_empty_slots()

        for piece in pieces:
            xi = piece.x_i
            yi = piece.y_i
            pl = piece.player
            colour = self.player_colours[pl]

            self.place_piece(xi, yi, colour)


    def draw_win(self, pl, ai):

        surf = self.surface
        font = pygame.font.SysFont("monospace", 36)

        if ai:
            if pl==0:
                label = font.render("You win!", 1, RED)
            elif pl==1:
                label = font.render("AI wins!", 1, YELLOW)
            else:
                label = font.render("Draw!", 1, WHITE)
        else:
            if pl >= 0:
                colour = self.player_colours[pl]
                if colour == RED:
                    label_text = "Red wins!"
                elif colour == YELLOW:
                    label_text = "Yellow wins!"
                # label_text = colour + " wins!"
                label = font.render(label_text, 1, colour)
            else:
                label = font.render("Draw!", 1, WHITE)

        label_rect = label.get_rect()

        x = surf.get_width() // 2
        y = surf.get_height() // 2

        label_rect.center = (x, y)

        self.surface.blit(label, label_rect)




