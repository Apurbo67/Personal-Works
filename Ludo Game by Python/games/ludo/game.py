from __future__ import annotations
import pygame
import random
from typing import List, Dict, Optional, Tuple

# draw board stuff
from games.ludo.board import Board

# games_shared settings and data
from games.ludo.constants import (
    WINDOW_BG, FPS, TURN_SECONDS,
    DICE_RECT, COLOR_TUPLE, COLORS_ORDER, AI_PLAYERS,
    HUD_TURN_POS, HUD_TIMER_POS, HUD_DICE_POS,
    HUD_TURN_FONT, HUD_INFO_FONT,
    GRID_LEFT, GRID_TOP, CELL_SIZE, TOKEN_RADIUS,
    BASE_TOKENS, SAFE_STARS,
    RING, RING_LEN, START_INDEX, LANE_ENTRY_INDEX, HOME_LANES, HOME_LEN,
)

# convert grid (col,row) to pixel center
def grid_to_pixel(col: int, row: int) -> Tuple[int, int]:
    return (
        GRID_LEFT + col * CELL_SIZE + CELL_SIZE // 2,
        GRID_TOP + row * CELL_SIZE + CELL_SIZE // 2,
    )

# check if a cell is safe (no capture)
def is_safe_cell(col_row: Tuple[int, int]) -> bool:
    return col_row in SAFE_STARS


class Token:
    # each token knows color, base spot, and where it is
    def __init__(self, color: str, base_pos: Tuple[int, int]):
        self.color = color
        self.base_pos = base_pos   # stays here until it rolls a 6
        self.state = "BASE"        # BASE | RING | HOME | FINISHED
        self.ring_index: Optional[int] = None
        self.home_index: Optional[int] = None

    # where to draw the token right now (grid coords)
    def current_grid_pos(self) -> Tuple[int, int]:
        if self.state == "BASE":
            return self.base_pos
        elif self.state == "RING":
            return RING[self.ring_index]  # type: ignore
        elif self.state == "HOME":
            return HOME_LANES[self.color][self.home_index]  # type: ignore
        else:  # FINISHED -> just keep it at lane end
            return HOME_LANES[self.color][-1]

    # draw the token as a circle
    def draw(self, surface: pygame.Surface):
        x, y = grid_to_pixel(*self.current_grid_pos())
        pygame.draw.circle(surface, COLOR_TUPLE[self.color], (x, y), TOKEN_RADIUS)
        pygame.draw.circle(surface, (0, 0, 0), (x, y), TOKEN_RADIUS, 2)


class Game:
    def __init__(self, screen: pygame.Surface, mode: str):
        self.screen = screen
        self.clock = pygame.time.Clock()
        self.board = Board()

        # start from first color in order
        self.turn_color = COLORS_ORDER[0]
        self.turn_timer = TURN_SECONDS
        self.dice_value: Optional[int] = None
        self.dice_rolled = False

        # small delay so AI doesn’t spam instantly
        self.ai_delay = 0.4
        self.ai_cooldown = 0.0

        # build 4 tokens per color
        self.tokens: Dict[str, List[Token]] = {
            color: [Token(color, pos) for pos in BASE_TOKENS[color]]
            for color in COLORS_ORDER
        }

        # which tokens are clickable after a roll
        self.valid_click_targets: List[Token] = []

        # PVC = Player vs Computer (others are AI)
        self.ai_colors = set(AI_PLAYERS) if mode == "PVC" else set()

    # move to next turn (or keep same if rolled 6)
    def reset_turn(self, keep_same_color: bool = False):
        if not keep_same_color:
            idx = COLORS_ORDER.index(self.turn_color)
            self.turn_color = COLORS_ORDER[(idx + 1) % len(COLORS_ORDER)]
        self.turn_timer = TURN_SECONDS
        self.dice_rolled = False
        self.dice_value = None
        self.valid_click_targets.clear()
        self.ai_cooldown = 0.0

    # roll the dice
    def roll_dice(self):
        self.dice_value = random.randint(1, 6)
        self.dice_rolled = True

        # figure out which tokens can actually move
        self.valid_click_targets = self.legal_tokens_to_move(self.turn_color, self.dice_value)

        # no move and not a 6 -> pass turn
        if not self.valid_click_targets and self.dice_value != 6:
            self.reset_turn(keep_same_color=False)

    # filter tokens that have at least one legal move
    def legal_tokens_to_move(self, color: str, dice: int) -> List[Token]:
        res: List[Token] = []
        for t in self.tokens[color]:
            if self.can_move_token(t, dice):
                res.append(t)
        return res

    # basic move rules
    def can_move_token(self, token: Token, dice: int) -> bool:
        state = token.state
        if state == "FINISHED":
            return False

        if state == "BASE":
            # only 6 can come out
            return dice == 6

        if state == "RING":
            # check ring and possible lane entry
            return self._can_ring_advance(token, dice)

        if state == "HOME":
            # must not overshoot home end
            target = token.home_index + dice
            return target < HOME_LEN

        return False

    # ring movement including turning into home lane
    def _can_ring_advance(self, token: Token, dice: int) -> bool:
        idx = token.ring_index
        lane_entry = LANE_ENTRY_INDEX[token.color]
        steps_to_entry = (lane_entry - idx) % RING_LEN

        if dice <= steps_to_entry:
            # still on the ring
            return True
        else:
            # steps into lane after passing entry
            steps_into_lane = dice - steps_to_entry - 1
            return steps_into_lane < HOME_LEN

    # actually update token position based on dice
    def move_token(self, token: Token, dice: int):
        if token.state == "BASE":
            # jump to the color’s start cell on ring
            token.state = "RING"
            token.ring_index = START_INDEX[token.color]
            self._maybe_capture_on_ring_cell(token)
            return

        if token.state == "RING":
            idx = token.ring_index  # type: ignore
            lane_entry = LANE_ENTRY_INDEX[token.color]
            steps_to_entry = (lane_entry - idx) % RING_LEN

            if dice <= steps_to_entry:
                # move forward on ring
                token.ring_index = (idx + dice) % RING_LEN
                self._maybe_capture_on_ring_cell(token)
                return
            else:
                # jump into home lane
                steps_into_lane = dice - steps_to_entry - 1
                token.state = "HOME"
                token.home_index = steps_into_lane
            return

        if token.state == "HOME":
            target = token.home_index + dice  # type: ignore
            if target == HOME_LEN - 1:
                # reached last cell -> finished
                token.home_index = target
                token.state = "FINISHED"
            elif target < HOME_LEN - 1:
                token.home_index = target
            # if target >= HOME_LEN we ignore (illegal)

    # handle capturing on ring (but not on safe cells)
    def _maybe_capture_on_ring_cell(self, mover: Token):
        col_row = mover.current_grid_pos()
        if is_safe_cell(col_row):
            return  # no capture on safe squares

        for color, toks in self.tokens.items():
            if color == mover.color:
                continue
            for t in toks:
                if t.state == "RING" and t.current_grid_pos() == col_row:
                    # send enemy back to base
                    t.state = "BASE"
                    t.ring_index = None
                    t.home_index = None

    # click handling for human player
    def handle_mouse_click(self, pos: Tuple[int, int]):
        # click dice to roll
        if DICE_RECT.collidepoint(pos) and not self.dice_rolled:
            self.roll_dice()
            return

        # already rolled: click one of your legal tokens
        if self.dice_rolled and self.dice_value is not None:
            clicked = self._token_at_pixel(self.turn_color, pos, legal_only=True)
            if clicked:
                self.move_token(clicked, self.dice_value)
                got_six = (self.dice_value == 6)
                if got_six:
                    self.reset_turn(keep_same_color=True)   # extra roll
                else:
                    self.reset_turn(keep_same_color=False)

    # find which token (if any) is under mouse
    def _token_at_pixel(self, color: str, pos: Tuple[int, int], legal_only: bool) -> Optional[Token]:
        mx, my = pos
        for t in self.tokens[color]:
            if legal_only and not self.can_move_token(t, self.dice_value or 0):
                continue
            gx, gy = grid_to_pixel(*t.current_grid_pos())
            if (mx - gx) ** 2 + (my - gy) ** 2 <= (TOKEN_RADIUS + 6) ** 2:
                return t
        return None

    # AI logic (very simple): roll, pick a legal move, prefer captures
    def ai_take_turn(self, dt: float):
        self.ai_cooldown -= dt
        if self.ai_cooldown > 0:
            return
        self.ai_cooldown = self.ai_delay

        if not self.dice_rolled:
            self.roll_dice()
            return

        if self.dice_value is None:
            return

        legal = self.legal_tokens_to_move(self.turn_color, self.dice_value)
        if not legal:
            # no move; if 6 then extra try, else pass
            if self.dice_value == 6:
                self.reset_turn(keep_same_color=True)
            else:
                self.reset_turn(keep_same_color=False)
            return

        # try to capture if possible, else just move the first one
        choice = None
        for t in legal:
            if self._simulate_ring_capture_if_moved(t, self.dice_value):
                choice = t
                break
        if choice is None:
            choice = legal[0]

        self.move_token(choice, self.dice_value)
        if self.dice_value == 6:
            self.reset_turn(keep_same_color=True)
        else:
            self.reset_turn(keep_same_color=False)

    # quick check: would this move capture someone on the ring?
    def _simulate_ring_capture_if_moved(self, token: Token, dice: int) -> bool:
        if token.state == "BASE":
            dest = RING[START_INDEX[token.color]]
            if is_safe_cell(dest):
                return False
            return any(
                (other.state == "RING" and other.current_grid_pos() == dest)
                for color, lst in self.tokens.items() if color != token.color
                for other in lst
            )

        if token.state == "RING":
            idx = token.ring_index  # type: ignore
            lane_entry = LANE_ENTRY_INDEX[token.color]
            steps_to_entry = (lane_entry - idx) % RING_LEN
            if dice <= steps_to_entry:
                dest = RING[(idx + dice) % RING_LEN]
                if is_safe_cell(dest):
                    return False
                return any(
                    (other.state == "RING" and other.current_grid_pos() == dest)
                    for color, lst in self.tokens.items() if color != token.color
                    for other in lst
                )
        return False

    # draw the dice box + pips
    def draw_dice(self):
        pygame.draw.rect(self.screen, (255, 255, 255), DICE_RECT, border_radius=15)
        pygame.draw.rect(self.screen, (0, 0, 0), DICE_RECT, 2, border_radius=15)
        if self.dice_value:
            self._draw_dice_face()

    # draw pips based on dice value
    def _draw_dice_face(self):
        center = (DICE_RECT.centerx, DICE_RECT.centery)
        radius = 8
        spots = {
            1: [(0, 0)],
            2: [(-18, -18), (18, 18)],
            3: [(-18, -18), (0, 0), (18, 18)],
            4: [(-18, -18), (18, -18), (-18, 18), (18, 18)],
            5: [(-18, -18), (18, -18), (0, 0), (-18, 18), (18, 18)],
            6: [(-18, -18), (18, -18), (-18, 0), (18, 0), (-18, 18), (18, 18)],
        }
        for dx, dy in spots[self.dice_value]:
            pygame.draw.circle(self.screen, (0, 0, 0), (center[0] + dx, center[1] + dy), radius)

    # draw right panel info
    def draw_hud(self):
        color_rgb = COLOR_TUPLE[self.turn_color]
        turn_text = HUD_TURN_FONT.render(f"Turn: {self.turn_color}", True, color_rgb)
        self.screen.blit(turn_text, HUD_TURN_POS)

        tleft = max(0, int(self.turn_timer))
        timer_text = HUD_INFO_FONT.render(f"Timer: {tleft}s", True, (0, 0, 0))
        self.screen.blit(timer_text, HUD_TIMER_POS)

        dice_val = self.dice_value if self.dice_value is not None else "—"
        dice_text = HUD_INFO_FONT.render(f"Dice: {dice_val}", True, (0, 0, 0))
        self.screen.blit(dice_text, HUD_DICE_POS)

    # draw all tokens
    def draw_tokens(self):
        for color, lst in self.tokens.items():
            for t in lst:
                t.draw(self.screen)

    # one full frame
    def draw(self):
        self.screen.fill(WINDOW_BG)
        self.board.draw(self.screen)
        self.draw_tokens()
        self.draw_dice()
        self.draw_hud()
        pygame.display.flip()

    # input
    def handle_events(self):
        quit_signal = None
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return "QUIT"
            if event.type == pygame.MOUSEBUTTONDOWN:
                # only humans click; AI ignores mouse
                if self.turn_color not in self.ai_colors:
                    self.handle_mouse_click(pygame.mouse.get_pos())
        return quit_signal

    # countdown per turn and auto-pass/move if needed
    def update_timer(self, dt: float):
        self.turn_timer -= dt
        if self.turn_timer <= 0:
            if self.turn_color in self.ai_colors:
                # AI turn is handled in ai_take_turn anyway
                self.turn_timer = 1  # avoid firing every frame
            else:
                # for humans: if timeout, roll or move something simple
                if not self.dice_rolled:
                    self.roll_dice()
                else:
                    legal = self.legal_tokens_to_move(self.turn_color, self.dice_value or 0)
                    if legal:
                        self.move_token(legal[0], self.dice_value or 0)
                        if (self.dice_value or 0) == 6:
                            self.reset_turn(keep_same_color=True)
                        else:
                            self.reset_turn(keep_same_color=False)
                    else:
                        self.reset_turn(keep_same_color=False)

    # main loop
    def run(self):
        while True:
            dt = self.clock.tick(FPS) / 1000.0
            quit_signal = self.handle_events()
            if quit_signal == "QUIT":
                return  # return to launcher

            # let AI play its turn automatically
            if self.turn_color in self.ai_colors:
                self.ai_take_turn(dt)

            # timer logic
            self.update_timer(dt)

            # draw everything
            self.draw()
