import pygame
import sys
import random

from games.ludo.constants import (
    WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BG,
    BUTTONS, BUTTON_COLOR, BUTTON_HOVER, BUTTON_BORDER, BUTTON_TEXT, BUTTON_FONT,
)
from games.ludo.game import Game

# init pygame + window once
pygame.init()
screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
pygame.display.set_caption("Ludo Game")

# tiny helper to center text in a rect
def draw_text_center(surface, text, font, color, rect):
    text_surf = font.render(text, True, color)
    text_rect = text_surf.get_rect(center=rect.center)
    surface.blit(text_surf, text_rect)

# main menu loop
def main_menu(screen):
    clock = pygame.time.Clock()
    running = True

    while running:
        screen.fill(WINDOW_BG)
        mouse_pos = pygame.mouse.get_pos()

        # title at the top
        title_font = pygame.font.SysFont("calibri", 70, bold=True)
        title_text = title_font.render("LUDO", True, (0, 0, 0))
        title_rect = title_text.get_rect(center=(WINDOW_WIDTH // 2, 150))
        screen.blit(title_text, title_rect)

        # prepare button labels
        rendered = []
        for label, rect in BUTTONS.items():
            text = label.replace("_", " ").title()
            rtxt = BUTTON_FONT.render(text, True, BUTTON_TEXT)
            rendered.append((rtxt, rect, label))

        # draw buttons (hover color if mouse is on it)
        for rtxt, rect, _mode in rendered:
            color = BUTTON_HOVER if rect.collidepoint(mouse_pos) else BUTTON_COLOR
            pygame.draw.rect(screen, color, rect, border_radius=12)
            pygame.draw.rect(screen, BUTTON_BORDER, rect, 3, border_radius=12)
            draw_text_center(screen, _mode.replace("_", " ").title(), BUTTON_FONT, BUTTON_TEXT, rect)

        pygame.display.flip()

        # handle clicks
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return "QUIT"
            elif event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos = pygame.mouse.get_pos()
                for _, rect, _mode in rendered:
                    if rect.collidepoint(mouse_pos):
                        if _mode == "QUIT":
                            return "QUIT"
                        elif _mode == "PLAY_VS_COMPUTER":
                            return "PVC"   # player vs computer
                        elif _mode == "PLAY_VS_PLAYER":
                            return "PVP"   # player vs player

        clock.tick(60)

# app entry – loop back to menu after each game
def main():
    pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))

    while True:
        mode = main_menu(screen)   # get mode from menu
        if mode == "QUIT":
            pygame.display.set_mode((800, 600))
            return
        game = Game(screen, mode)  # create a new game
        game.run()                 # run game loop

if __name__ == "__main__":
    main()
