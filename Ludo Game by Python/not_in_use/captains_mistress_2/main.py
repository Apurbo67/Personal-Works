import pygame
import sys
import numpy as np
import math
import random
import time

# --- Game constants ---
ROW_COUNT = 6
COLUMN_COUNT = 7
SQUARESIZE = 100
RADIUS = int(SQUARESIZE / 2 - 5)
WIDTH = COLUMN_COUNT * SQUARESIZE
HEIGHT = (ROW_COUNT + 1) * SQUARESIZE 
SIZE = (WIDTH, HEIGHT)

# Colors
BLUE = (28, 107, 160)
BLACK = (0, 0, 0)
RED = (200, 30, 30)       # Player (human)
YELLOW = (240, 230, 70)   # AI

# Players
PLAYER = 1
AI = 2
EMPTY = 0

# Minimax settings (tune depth for difficulty / speed)
AI_DEPTH = 5  # 4-6 is typical; higher = stronger but slower

# Heuristic weights
WINDOW_LENGTH = 4
CENTER_WEIGHT = 3

# --- Board utility functions ---
def create_board():
    return np.zeros((ROW_COUNT, COLUMN_COUNT), dtype=int)

def drop_piece(board, row, col, piece):
    board[row][col] = piece

def is_valid_location(board, col):
    return board[ROW_COUNT - 1][col] == EMPTY

def get_next_open_row(board, col):
    for r in range(ROW_COUNT):
        if board[r][col] == EMPTY:
            return r
    return None

def winning_move(board, piece):
    # Horizontal check
    for c in range(COLUMN_COUNT - 3):
        for r in range(ROW_COUNT):
            if all(board[r][c + i] == piece for i in range(4)):
                return True
    # Vertical check
    for c in range(COLUMN_COUNT):
        for r in range(ROW_COUNT - 3):
            if all(board[r + i][c] == piece for i in range(4)):
                return True
    # Positive diagonal
    for c in range(COLUMN_COUNT - 3):
        for r in range(ROW_COUNT - 3):
            if all(board[r + i][c + i] == piece for i in range(4)):
                return True
    # Negative diagonal
    for c in range(COLUMN_COUNT - 3):
        for r in range(3, ROW_COUNT):
            if all(board[r - i][c + i] == piece for i in range(4)):
                return True
    return False

def is_terminal_node(board):
    return winning_move(board, PLAYER) or winning_move(board, AI) or len(get_valid_locations(board)) == 0

# --- Heuristic evaluation ---
def evaluate_window(window, piece):
    score = 0
    opp_piece = PLAYER if piece == AI else AI

    if window.count(piece) == 4:
        score += 100
    elif window.count(piece) == 3 and window.count(EMPTY) == 1:
        score += 5
    elif window.count(piece) == 2 and window.count(EMPTY) == 2:
        score += 2

    if window.count(opp_piece) == 3 and window.count(EMPTY) == 1:
        score -= 4  

    return score

def score_position(board, piece):
    score = 0
    # Center column preference
    center_array = [int(i) for i in list(board[:, COLUMN_COUNT // 2])]
    center_count = center_array.count(piece)
    score += center_count * CENTER_WEIGHT

    # Horizontal
    for r in range(ROW_COUNT):
        row_array = [int(i) for i in list(board[r, :])]
        for c in range(COLUMN_COUNT - 3):
            window = row_array[c:c + WINDOW_LENGTH]
            score += evaluate_window(window, piece)

    # Vertical
    for c in range(COLUMN_COUNT):
        col_array = [int(i) for i in list(board[:, c])]
        for r in range(ROW_COUNT - 3):
            window = col_array[r:r + WINDOW_LENGTH]
            score += evaluate_window(window, piece)

    # Positive diagonal
    for r in range(ROW_COUNT - 3):
        for c in range(COLUMN_COUNT - 3):
            window = [board[r + i][c + i] for i in range(WINDOW_LENGTH)]
            score += evaluate_window(window, piece)

    # Negative diagonal
    for r in range(ROW_COUNT - 3):
        for c in range(COLUMN_COUNT - 3):
            window = [board[r + 3 - i][c + i] for i in range(WINDOW_LENGTH)]
            score += evaluate_window(window, piece)

    return score

def get_valid_locations(board):
    return [c for c in range(COLUMN_COUNT) if is_valid_location(board, c)]

def pick_best_move(board, piece):
    valid_locations = get_valid_locations(board)
    best_score = -math.inf
    best_col = random.choice(valid_locations)
    for col in valid_locations:
        row = get_next_open_row(board, col)
        temp_board = board.copy()
        drop_piece(temp_board, row, col, piece)
        score = score_position(temp_board, piece)
        if score > best_score:
            best_score = score
            best_col = col
    return best_col

# --- Minimax with alpha-beta pruning ---
def minimax(board, depth, alpha, beta, maximizingPlayer):
    valid_locations = get_valid_locations(board)
    terminal = is_terminal_node(board)
    if depth == 0 or terminal:
        if terminal:
            if winning_move(board, AI):
                return (None, 100000000000000)
            elif winning_move(board, PLAYER):
                return (None, -100000000000000)
            else:  
                return (None, 0)
        else: 
            return (None, score_position(board, AI))

    if maximizingPlayer:
        value = -math.inf
        chosen_col = random.choice(valid_locations)
        ordered = sorted(valid_locations, key=lambda c: score_position_after_move(board, c, AI), reverse=True)
        for col in ordered:
            row = get_next_open_row(board, col)
            b_copy = board.copy()
            drop_piece(b_copy, row, col, AI)
            new_score = minimax(b_copy, depth - 1, alpha, beta, False)[1]
            if new_score > value:
                value = new_score
                chosen_col = col
            alpha = max(alpha, value)
            if alpha >= beta:
                break
        return chosen_col, value
    else:  
        value = math.inf
        chosen_col = random.choice(valid_locations)
        ordered = sorted(valid_locations, key=lambda c: score_position_after_move(board, c, PLAYER))
        for col in ordered:
            row = get_next_open_row(board, col)
            b_copy = board.copy()
            drop_piece(b_copy, row, col, PLAYER)
            new_score = minimax(b_copy, depth - 1, alpha, beta, True)[1]
            if new_score < value:
                value = new_score
                chosen_col = col
            beta = min(beta, value)
            if alpha >= beta:
                break
        return chosen_col, value

def score_position_after_move(board, col, piece):
    """Helper to produce quick heuristic for ordering moves in minimax"""
    temp = board.copy()
    row = get_next_open_row(temp, col)
    if row is None:
        return -999999
    drop_piece(temp, row, col, piece)
    return score_position(temp, piece)

# --- Pygame drawing functions ---
def draw_board(screen, board, selector_col):
    pygame.draw.rect(screen, BLACK, (0, 0, WIDTH, SQUARESIZE))
    selector_x = selector_col * SQUARESIZE + SQUARESIZE // 2
    pygame.draw.circle(screen, YELLOW, (selector_x, SQUARESIZE // 2), RADIUS // 2)

    for c in range(COLUMN_COUNT):
        for r in range(ROW_COUNT):
            pygame.draw.rect(screen, BLUE,
                             (c * SQUARESIZE, (r + 1) * SQUARESIZE, SQUARESIZE, SQUARESIZE))
            pygame.draw.circle(screen, BLACK,
                               (c * SQUARESIZE + SQUARESIZE // 2, (r + 1) * SQUARESIZE + SQUARESIZE // 2),
                               RADIUS)

    for c in range(COLUMN_COUNT):
        for r in range(ROW_COUNT):
            piece = board[ROW_COUNT - 1 - r][c]
            pos_x = c * SQUARESIZE + SQUARESIZE // 2
            pos_y = (r + 1) * SQUARESIZE + SQUARESIZE // 2
            if piece == PLAYER:
                pygame.draw.circle(screen, RED, (pos_x, pos_y), RADIUS)
            elif piece == AI:
                pygame.draw.circle(screen, YELLOW, (pos_x, pos_y), RADIUS)
    pygame.display.update()

# --- Main game loop ---
def main():
    pygame.init()
    screen = pygame.display.set_mode(SIZE)
    pygame.display.set_caption("Connect 4 — Human vs AI (Minimax + Alpha-Beta)")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("monospace", 36)
    small_font = pygame.font.SysFont("monospace", 20)

    board = create_board()
    game_over = False
    turn = random.choice([PLAYER, AI])
    selector_col = COLUMN_COUNT // 2

    draw_board(screen, board, selector_col)
    pygame.display.flip()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q or event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    sys.exit()
                if event.key == pygame.K_r:
                    board = create_board()
                    game_over = False
                    turn = random.choice([PLAYER, AI])
                    selector_col = COLUMN_COUNT // 2
                    draw_board(screen, board, selector_col)
                    continue
                if not game_over and turn == PLAYER:
                    if event.key == pygame.K_LEFT:
                        selector_col = max(0, selector_col - 1)
                        draw_board(screen, board, selector_col)
                    elif event.key == pygame.K_RIGHT:
                        selector_col = min(COLUMN_COUNT - 1, selector_col + 1)
                        draw_board(screen, board, selector_col)
                    elif event.key == pygame.K_SPACE or event.key == pygame.K_RETURN:
                        col = selector_col
                        if is_valid_location(board, col):
                            row = get_next_open_row(board, col)
                            drop_piece(board, row, col, PLAYER)
                            if winning_move(board, PLAYER):
                                label = font.render("You win!", 1, RED)
                                screen.blit(label, (40, 10))
                                game_over = True
                            turn = AI
                            draw_board(screen, board, selector_col)

        # AI turn
        if not game_over and turn == AI:
            pygame.time.wait(300)
            col, minimax_score = minimax(board.copy(), AI_DEPTH, -math.inf, math.inf, True)
            if col is None:
                col = pick_best_move(board, AI)
            if is_valid_location(board, col):
                row = get_next_open_row(board, col)
                drop_piece(board, row, col, AI)
                if winning_move(board, AI):
                    label = font.render("AI wins!", 1, YELLOW)
                    screen.blit(label, (40, 10))
                    game_over = True
                turn = PLAYER
                draw_board(screen, board, selector_col)

        pygame.draw.rect(screen, BLACK, (0, 0, WIDTH, SQUARESIZE))
        turn_text = "Your turn (RED)" if turn == PLAYER and not game_over else "AI thinking..." if turn == AI and not game_over else ""
        text_surface = small_font.render(turn_text, True, (255, 255, 255))
        screen.blit(text_surface, (10, 10))
        pygame.display.update()

        if game_over:
            hint = small_font.render("Press R to restart or Q to quit", True, (255, 255, 255))
            screen.blit(hint, (10, HEIGHT - 30))
            pygame.display.update()
            while True:
                ev = pygame.event.wait()
                if ev.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
                if ev.type == pygame.KEYDOWN:
                    if ev.key == pygame.K_r:
                        board = create_board()
                        game_over = False
                        turn = random.choice([PLAYER, AI])
                        selector_col = COLUMN_COUNT // 2
                        draw_board(screen, board, selector_col)
                        break
                    elif ev.key == pygame.K_q or ev.key == pygame.K_ESCAPE:
                        pygame.quit()
                        sys.exit()

        clock.tick(30)

if __name__ == "__main__":
    main()
