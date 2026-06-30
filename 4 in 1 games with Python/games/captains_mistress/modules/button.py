import pygame

# Colors
BLUE = (28, 107, 160)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (200, 30, 30)       # Player (human)
YELLOW = (240, 230, 70)   # AI
LIGHT_GREY = (200, 200, 200)

class Button:
    def __init__(self, text, pos, callback, w = 300, h = 60, font_size=32, font_col = BLUE, font_hov = WHITE, bg_col = WHITE, bg_hov = YELLOW):
        self.text = text
        self.pos = pos
        self.callback = callback
        self.width = w
        self.height = h
        self.font = pygame.font.SysFont("Arial", font_size)
        self.font_colour = font_col
        self.font_hover_colour = font_hov
        self.background_colour = bg_col
        self.background_hover_colour = bg_hov
        self.color = (200, 200, 200)
        self.hover_color = (255, 255, 0)
        self.rect = None


    def draw(self, screen):

        if self.rect and self.rect.collidepoint(pygame.mouse.get_pos()):
            font_colour = self.font_hover_colour
            bg_colour = self.background_hover_colour
        else:
            font_colour = self.font_colour
            bg_colour = self.background_colour


        # font_colour = self.font_hover_colour if self.rect and self.rect.collidepoint(pygame.mouse.get_pos()) else self.font_colour
        text_surf = self.font.render(self.text, True, font_colour)
        text_rect = text_surf.get_rect(center=self.pos)

        # Draw background
        button_rect = pygame.Rect(0, 0, self.width, self.height)
        button_rect.center = text_rect.center
        self.rect = button_rect
        pygame.draw.rect(screen, bg_colour, button_rect)

        screen.blit(text_surf, text_rect)


    def handle_event(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            if self.rect and self.rect.collidepoint(event.pos):
                self.callback()