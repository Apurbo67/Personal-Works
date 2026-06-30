import random
import pygame
from .constants import DICE_RECT, BLACK, WHITE

# simple 3x3 pip layouts for each face
PIPS = {
    1: ((1, 1),),
    2: ((0, 0), (2, 2)),
    3: ((0, 0), (1, 1), (2, 2)),
    4: ((0, 0), (0, 2), (2, 0), (2, 2)),
    5: ((0, 0), (0, 2), (1, 1), (2, 0), (2, 2)),
    6: ((0, 0), (0, 2), (1, 0), (1, 2), (2, 0), (2, 2)),
}

class Dice:
    # keep the current value and where it sits on screen
    def __init__(self):
        self.value = 6            # start with something visible
        self.rect = DICE_RECT     # clickable box

    # random 1..6
    def roll(self):
        self.value = random.randint(1, 6)

    # check if user clicked the dice
    def handle_click(self, pos) -> bool:
        if self.rect.collidepoint(pos):
            self.roll()           # roll on click
            return True
        return False

    # draw the white box + border + pips
    def draw(self, surface: pygame.Surface):
        pygame.draw.rect(surface, WHITE, self.rect, border_radius=12)
        pygame.draw.rect(surface, BLACK, self.rect, 2, border_radius=12)

        # split the box into 3x3 cells
        cell_w = self.rect.w // 3
        cell_h = self.rect.h // 3
        r = min(cell_w, cell_h) // 6   # small dot radius

        # put pips in the right cells
        for (cx, cy) in PIPS[self.value]:
            px = self.rect.x + cx * cell_w + cell_w // 2
            py = self.rect.y + cy * cell_h + cell_h // 2
            pygame.draw.circle(surface, BLACK, (px, py), r)
