
from __future__ import annotations
import pygame
from games.ludo.constants import (
    CELL_SIZE, GRID_COLS, GRID_ROWS,
    GRID_LEFT, GRID_TOP,
    WHITE, BLACK, GREY,
    RED, GREEN, BLUE, YELLOW,
    BORDER_RED, BORDER_GREEN, BORDER_BLUE, BORDER_YELLOW,
    BASES, SAFE_STARS,
)

class Board:


    def __init__(self) -> None:
        pass


    def _cell_rect(self, c: int, r: int) -> pygame.Rect:
        return pygame.Rect(GRID_LEFT + c*CELL_SIZE, GRID_TOP + r*CELL_SIZE, CELL_SIZE, CELL_SIZE)

    def _fill_cells(self, surface: pygame.Surface, cells, color, border=BLACK, bw=1):
        for c, r in cells:
            rect = self._cell_rect(c, r)
            pygame.draw.rect(surface, color, rect)
            if bw:
                pygame.draw.rect(surface, border, rect, bw)


    def draw(self, surface: pygame.Surface) -> None:

        base_specs = [
            ("RED",    BORDER_RED),
            ("GREEN",  BORDER_GREEN),
            ("BLUE",   BORDER_BLUE),
            ("YELLOW", BORDER_YELLOW),
        ]
        for name, bcol in base_specs:
            x, y, w, h = BASES[name]
            rect = pygame.Rect(GRID_LEFT + x*CELL_SIZE, GRID_TOP + y*CELL_SIZE,
                               w*CELL_SIZE, h*CELL_SIZE)
            pygame.draw.rect(surface, WHITE, rect)
            pygame.draw.rect(surface, bcol, rect, 4)


        for c in range(GRID_COLS):
            for r in range(GRID_ROWS):
                pygame.draw.rect(surface, GREY, self._cell_rect(c, r), 1)


        self._fill_cells(surface, [(7, r) for r in range(0, 6)], BLUE)

        self._fill_cells(surface, [(7, r) for r in range(9, 15)], RED)

        self._fill_cells(surface, [(c, 7) for c in range(0, 6)], GREEN)

        self._fill_cells(surface, [(c, 7) for c in range(9, 15)], YELLOW)

        # Center 3x3 black
        center = pygame.Rect(
            GRID_LEFT + 6*CELL_SIZE, GRID_TOP + 6*CELL_SIZE,
            CELL_SIZE*3, CELL_SIZE*3
        )
        pygame.draw.rect(surface, BLACK, center)

        # center diamond
        mid = (GRID_LEFT + 7.5*CELL_SIZE, GRID_TOP + 7.5*CELL_SIZE)
        tri = CELL_SIZE*1.5
        pts_up    = [(mid[0], mid[1]-tri), (mid[0]-tri, mid[1]), (mid[0]+tri, mid[1])]
        pts_right = [(mid[0]+tri, mid[1]), (mid[0], mid[1]-tri), (mid[0], mid[1]+tri)]
        pts_down  = [(mid[0], mid[1]+tri), (mid[0]-tri, mid[1]), (mid[0]+tri, mid[1])]
        pts_left  = [(mid[0]-tri, mid[1]), (mid[0], mid[1]-tri), (mid[0], mid[1]+tri)]
        pygame.draw.polygon(surface, GREEN, pts_left)
        pygame.draw.polygon(surface, YELLOW, pts_right)
        pygame.draw.polygon(surface, RED, pts_down)
        pygame.draw.polygon(surface, BLUE, pts_up)
        pygame.draw.polygon(surface, BLACK, pts_up, 2)
        pygame.draw.polygon(surface, BLACK, pts_right, 2)
        pygame.draw.polygon(surface, BLACK, pts_down, 2)
        pygame.draw.polygon(surface, BLACK, pts_left, 2)

        # Safe stars
        star_r = max(3, CELL_SIZE//6)
        for c, r in SAFE_STARS:
            cx = GRID_LEFT + c*CELL_SIZE + CELL_SIZE//2
            cy = GRID_TOP  + r*CELL_SIZE + CELL_SIZE//2
            pygame.draw.circle(surface, YELLOW, (cx, cy), star_r)
            pygame.draw.circle(surface, BLACK,  (cx, cy), star_r, 1)
