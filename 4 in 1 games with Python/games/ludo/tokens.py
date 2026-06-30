
from __future__ import annotations
import pygame
from dataclasses import dataclass
from games.ludo.constants import (
    CELL_SIZE, cell_center, RING, START_INDEX, LANE_ENTRY_INDEX, HOME_LANES,
    COLOR_TUPLE, WHITE, BLACK
)

@dataclass
class Token:
    color: str
    base_cell: tuple[int,int]

    # state
    in_base: bool = True
    ring_index: int | None = None       # 0..51 when on the ring
    home_index: int | None = None       # 0..5  when in home lane (0 farthest, 5 at home)
    finished: bool = False

    radius: int = 10

    def grid_pos(self) -> tuple[int,int]:

        if self.finished:
            # park on home triangle center (the last lane cell)
            return HOME_LANES[self.color][-1]
        if self.in_base:
            return self.base_cell
        if self.home_index is not None:
            return HOME_LANES[self.color][self.home_index]
        # ring
        return RING[self.ring_index]

    def draw(self, surface: pygame.Surface):
        cx, cy = cell_center(*self.grid_pos())
        pygame.draw.circle(surface, COLOR_TUPLE[self.color], (cx, cy), self.radius)
        pygame.draw.circle(surface, BLACK, (cx, cy), self.radius, 2)


    def can_leave_base(self, dice: int) -> bool:
        return self.in_base and dice == 6

    def leave_base(self):
        self.in_base = False
        self.ring_index = START_INDEX[self.color]
        self.home_index = None

    def steps_to_finish(self) -> int:

        if self.in_base or self.finished:
            return 0

        start = self.ring_index
        entry = LANE_ENTRY_INDEX[self.color]
        if start <= entry:
            ring_steps = entry - start + 1
        else:
            ring_steps = (len(RING) - start) + (entry + 1)

        return ring_steps + len(HOME_LANES[self.color])

    def legal_move(self, dice: int) -> bool:
        if self.finished: return False
        if self.in_base:  return dice == 6

        steps = dice
        idx = self.ring_index
        entry = LANE_ENTRY_INDEX[self.color]
        if idx <= entry and idx + steps <= entry:
            return True
        if idx > entry:

            wrap = len(RING) - idx - 1
            if steps <= wrap: return True
            steps_after_wrap = steps - wrap - 1
            return steps_after_wrap <= (entry + 1)

        steps_into_lane = steps - (entry - idx + 1)
        return 0 <= steps_into_lane <= (len(HOME_LANES[self.color]) - 1 - (self.home_index or -1))

    def apply_move(self, dice: int):

        if self.in_base:
            self.leave_base()
            return

        idx = self.ring_index
        entry = LANE_ENTRY_INDEX[self.color]
        steps = dice


        if (idx <= entry and idx + steps <= entry) or (idx > entry and steps <= (len(RING) - idx - 1)):
            self.ring_index = (idx + steps) % len(RING)
            return


        if idx <= entry:
            steps_into_lane = steps - (entry - idx + 1)
        else:
            wrap = len(RING) - idx - 1
            steps_into_lane = steps - (wrap + 1 + entry + 1)

        self.ring_index = None
        self.home_index = max(0, min(len(HOME_LANES[self.color]) - 1, steps_into_lane))
        if self.home_index == len(HOME_LANES[self.color]) - 1:
            self.finished = True
