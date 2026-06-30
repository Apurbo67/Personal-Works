from __future__ import annotations
import pygame

# main window setup
WINDOW_BG = (245, 220, 196)  # background color
FPS = 60
TURN_SECONDS = 15  # timer per player

# side panel setup
PANEL_LEFT, PANEL_TOP = 840, 90
PANEL_WIDTH, PANEL_HEIGHT = 320, 420
PANEL_TEXT_LEFT = PANEL_LEFT + 10

# dice area
DICE_RECT = pygame.Rect(1030, 520, 170, 170)

# window size
WINDOW_WIDTH = PANEL_LEFT + PANEL_WIDTH + 50
WINDOW_HEIGHT = 700

# grid setup
GRID_COLS = 15
GRID_ROWS = 15
CELL_SIZE = 32
GRID_LEFT = 285
GRID_TOP = 80

# grid functions
def cell_rect(col: int, row: int) -> pygame.Rect:
    return pygame.Rect(
        GRID_LEFT + col * CELL_SIZE,
        GRID_TOP + row * CELL_SIZE,
        CELL_SIZE, CELL_SIZE
    )

def cell_center(col: int, row: int) -> tuple[int, int]:
    r = cell_rect(col, row)
    return (r.x + r.w // 2, r.y + r.h // 2)

# colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREY = (200, 200, 200)
DARK_GREY = (120, 120, 120)

RED = (220, 50, 50)
GREEN = (40, 170, 70)
BLUE = (45, 110, 210)
YELLOW = (232, 186, 32)

# border colors
BORDER_RED = (200, 40, 40)
BORDER_GREEN = (34, 150, 60)
BORDER_BLUE = (35, 95, 190)
BORDER_YELLOW = (206, 166, 28)

# easy way to get color
COLOR_TUPLE = {"RED": RED, "GREEN": GREEN, "BLUE": BLUE, "YELLOW": YELLOW}
COLORS_ORDER = ["RED", "GREEN", "BLUE", "YELLOW"]

TOKEN_RADIUS = 10  # token circle size

# base areas for players
BASES = {
    "RED": (0, 0, 6, 6),
    "GREEN": (9, 0, 6, 6),
    "BLUE": (0, 9, 6, 6),
    "YELLOW": (9, 9, 6, 6),
}

# token starting spots
BASE_TOKENS = {
    "RED": [(1,1),(4,1),(1,4),(4,4)],
    "GREEN": [(10,1),(13,1),(10,4),(13,4)],
    "BLUE": [(1,10),(4,10),(1,13),(4,13)],
    "YELLOW": [(10,10),(13,10),(10,13),(13,13)],
}

# safe cells where tokens can’t be killed
SAFE_STARS = [(1,6),(6,1),(8,1),(13,6),(13,8),(8,13),(6,13),(1,8)]

# main ring path around the board
RING: list[tuple[int,int]] = [
    (6, 1), (7, 1), (8, 1),
    (8, 2), (8, 3), (8, 4), (8, 5),
    (9, 6), (10, 6), (11, 6), (12, 6), (13, 6), (14, 6),
    (14, 7), (14, 8), (13, 8), (12, 8), (11, 8), (10, 8), (9, 8),
    (8, 9), (8,10), (8,11), (8,12), (8,13), (8,14),
    (7,14), (6,14), (6,13), (6,12), (6,11), (6,10), (6,9),
    (5,8), (4,8), (3,8), (2,8), (1,8), (1,7),
    (1,6), (2,6), (3,6), (4,6), (5,6), (6,5),
    (6,4), (6,3), (6,2)
]
RING_LEN = len(RING)
SAFE_INDEXES = {i for i, cr in enumerate(RING) if cr in SAFE_STARS}

# start points for each color
START_INDEX = {
    "RED": RING.index((6,13)),
    "GREEN": RING.index((1,6)),
    "BLUE": RING.index((6,1)),
    "YELLOW": RING.index((13,8)),
}

# when to turn into home lane
LANE_ENTRY_INDEX = {
    "RED": RING.index((6,9)),
    "GREEN": RING.index((9,8)),
    "BLUE": RING.index((5,8)),
    "YELLOW": RING.index((8,9)),
}

# home paths for each color
HOME_LANES: dict[str, list[tuple[int,int]]] = {
    "RED": [(7,13),(7,12),(7,11),(7,10),(7,9),(7,8)],
    "GREEN": [(1,7),(2,7),(3,7),(4,7),(5,7),(6,7)],
    "BLUE": [(7,1),(7,2),(7,3),(7,4),(7,5),(7,6)],
    "YELLOW": [(13,7),(12,7),(11,7),(10,7),(9,7),(8,7)],
}
HOME_LEN = 6

# turn order
PLAYERS_ORDER = ["RED", "GREEN", "YELLOW", "BLUE"]
AI_PLAYERS = {"GREEN", "YELLOW", "BLUE"}  # AI will play these

# fonts for HUD
pygame.font.init()
HUD_TURN_FONT = pygame.font.SysFont("calibri", 48, bold=True)
HUD_INFO_FONT = pygame.font.SysFont("calibri", 28, bold=True)

# positions for text
HUD_TURN_POS = (PANEL_TEXT_LEFT, PANEL_TOP)
HUD_TIMER_POS = (PANEL_TEXT_LEFT, PANEL_TOP + 60)
HUD_DICE_POS = (PANEL_TEXT_LEFT, PANEL_TOP + 110)

# player text colors
PLAYER_COLOR_MAP = {
    "RED": pygame.Color("red"),
    "GREEN": pygame.Color("green"),
    "YELLOW": pygame.Color("gold"),
    "BLUE": pygame.Color("dodgerblue"),
}

# convert token base grid coords to pixels
HOME_POSITIONS = {
    color: [cell_center(c, r) for (c, r) in coords]
    for color, coords in BASE_TOKENS.items()
}

# fonts for menu and buttons
MENU_FONT = pygame.font.SysFont("calibri", 40, bold=True)
BUTTON_FONT = pygame.font.SysFont("calibri", 36, bold=True)

# menu button layout
BUTTON_WIDTH = 260
BUTTON_HEIGHT = 70
BUTTON_SPACING = 20
BUTTON_START_Y = 250
BUTTON_X = WINDOW_WIDTH // 2 - BUTTON_WIDTH // 2

# buttons for main menu
BUTTONS = {
    "PLAY_VS_COMPUTER": pygame.Rect(BUTTON_X, BUTTON_START_Y, BUTTON_WIDTH, BUTTON_HEIGHT),
    "PLAY_VS_PLAYER": pygame.Rect(BUTTON_X, BUTTON_START_Y + (BUTTON_HEIGHT + BUTTON_SPACING), BUTTON_WIDTH, BUTTON_HEIGHT),
    "RETURN TO LAUNCHER": pygame.Rect(BUTTON_X, BUTTON_START_Y + 2 * (BUTTON_HEIGHT + BUTTON_SPACING), BUTTON_WIDTH, BUTTON_HEIGHT),
}

# button colors
BUTTON_COLOR = (220, 180, 120)
BUTTON_HOVER = (255, 220, 160)
BUTTON_BORDER = (100, 70, 40)
BUTTON_TEXT = (0, 0, 0)
