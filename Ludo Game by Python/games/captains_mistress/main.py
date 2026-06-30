import pygame

#import game modules
from .modules.cm_game import CMGame

def main():
    pygame.init()
    screen = pygame.display.set_mode((800, 600))
    pygame.display.set_caption("Captain's Mistress")
    game = CMGame(screen)

    running = True
    while running:
        if game.state == "quit":
            running = False
            break
        game.step()

    return

if __name__ == "__main__":
    main()