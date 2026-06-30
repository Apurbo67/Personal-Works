import math
import numpy as np
import random
import copy


# Minimax settings (tune depth for difficulty / speed)
AI_DEPTH = 5  # 4-6 is typical; higher = stronger but slower

# Heuristic weights
WINDOW_LENGTH = 4
CENTER_WEIGHT = 3

class GameMechanics:

    def __init__(self):
        """
        mechanics = GameMechanics()
        Creates game mechanics object
        """
        self.n_x = 7  # Number of horizontal piece positions
        self.n_y = 6  # Number of vertical piece positions

        self.col_heights = [0] * self.n_x # Number of pieces in each column
        self.pieces = [] # List of pieces
        self.piece_positions = -np.ones((self.n_y, self.n_x))
        self.current_player = 0 # Current player
        self.winner = -1 # Game winner

        self.next_piece = None
        self.add_piece()


    class PlayingPiece:
        """
        Playing piece object
        """

        def __init__(self, xi, yi, pl):
            """
            self.PlayingPiece(xi,yi,pl)
            Creates new playing piece at specified grid position
            :param xi: horizontal grid position
            :param yi: vertical grid position
            :param pl: player that piece belongs to
            """
            self.x_i = xi # Horizontal grid position
            self.y_i = yi # Vertical grid position
            self.player = pl # Player that piece belongs to


    def add_piece(self):
        """
        self.add_piece()
        Adds new piece above playing area
        """
        xi = math.floor(self.n_x / 2) # place piece in the middle horizontally
        yi = self.n_y # place piece above top row of playing surface
        pl = self.current_player
        pl = abs(1 - pl) # go to next player
        self.current_player = pl
        piece = self.PlayingPiece(xi, yi, pl)
        self.next_piece = piece
        self.pieces.append(piece)


    def start_drop(self):

        piece = self.next_piece  # get next piece

        if not piece is None:  # confirm next piece exists
            xi = piece.x_i
            h = self.col_heights[xi]

            if h < self.n_y:  # check if column is already full
                return True

        return False  # return False for invalid move


    def end_drop(self):

        piece = self.next_piece  # get next piece

        if not piece is None:  # confirm next piece exists
            xi = piece.x_i
            yi = piece.y_i
            h = self.col_heights[xi]

            if yi == h:  # check if drop has finished
                self.piece_positions[yi][xi] = piece.player
                self.col_heights[xi] += 1
                self.next_piece = None
                return True

        return False  # return False for invalid move




    def move_piece(self, lr):
        """
        self.move_piece(lr)
        Horizontally moves next playing piece prior to dropping
        :param lr: movement direction, valid values are "left" and "right"
        :return: returns True if piece is moved successfully and False otherwise
        """

        piece = self.next_piece # get next piece

        if not piece is None: # confirm next piece exists
            if piece.y_i == self.n_y: # confirm piece has not been dropped yet
                xi = piece.x_i
                if lr == "left":
                    if xi > 0: # confirm piece is not already in left most position
                        xi -= 1
                        piece.x_i = xi
                        return True
                elif lr == "right":
                    if xi < self.n_x - 1: # confirm piece is not already in right most position
                        xi += 1
                        piece.x_i = xi
                        return True
            if lr == "down":
                xi = piece.x_i
                yi = piece.y_i
                h = self.col_heights[xi]
                if yi > h:
                    yi -= 1
                    piece.y_i =yi
                    return True
                else:
                    self.end_drop()
                    return False

        return False # return False for invalid move


    def drop_piece(self):
        """
        self.drop_piece()
        Drops current player piece into position
        :return: returns True if piece is moved successfully and False otherwise
        """
        piece = self.next_piece  # get next piece

        if not piece is None: # confirm next piece exists
            xi = piece.x_i
            h = self.col_heights[xi]

            if h < self.n_y: # check if column is already full
                piece.y_i = h
                self.piece_positions[h][xi] = piece.player
                self.col_heights[xi] += 1
                self.next_piece = None
                return True

        return False # return False for invalid move


    def winning_move(self, pl):
        """
        self.winning_move(pl)
        Checks if player pl has made a winning move
        :param pl: Player to check
        :return: Returns true if player has won game and false otherwise
        """

        nx = self.n_x
        ny = self.n_y

        board = self.piece_positions

        # Horizontal check
        for c in range(nx - 3):
            for r in range(ny):
                if all(board[r][c + i] == pl for i in range(4)):
                    self.winner = pl
                    return True
        # Vertical check
        for c in range(nx):
            for r in range(ny - 3):
                if all(board[r + i][c] == pl for i in range(4)):
                    self.winner = pl
                    return True
        # Positive diagonal
        for c in range(nx - 3):
            for r in range(ny - 3):
                if all(board[r + i][c + i] == pl for i in range(4)):
                    self.winner = pl
                    return True
        # Negative diagonal
        for c in range(nx - 3):
            for r in range(3, ny):
                if all(board[r - i][c + i] == pl for i in range(4)):
                    self.winner = pl
                    return True
        return False

    def is_terminal_node(self):
        """
        self.is_terminal_node()
        Checks if game has reached a terminal state (win/loss or stalemate)
        :return: True if game has ended, False otherwise
        """
        return self.winning_move(0) or self.winning_move(1) or len(self.get_valid_locations()) == 0


    def evaluate_window(self, window, pl):
        """
        score = self.evaluate_window(window, pl)
        Calculates score based on a given player's potential to complete a winning move within a provided selection of piece positions
        :param window: Array containing -1s to represent open piece positions, and 0s and 1s to represent positions occupied by a player
        :param pl: 0 or 1 representing player of interest
        :return: Score calculated for given window and player
        """
        score = 0
        opp_pl = abs(pl - 1)

        if window.count(pl) == 4: # Winning move
            score += 100
        elif window.count(pl) == 3 and window.count(-1) == 1: # One piece away from winning move
            score += 5
        elif window.count(pl) == 2 and window.count(-1) == 2: # Two pieces away from winning move
            score += 2

        if window.count(opp_pl) == 3 and window.count(-1) == 1: # Opposite player is one piece away from winning move
            score -= 4

        return score


    def score_position(self, pl):
        """
        self.score_position(pl)
        Calculates a score representing a given player's potential to win the current game
        :param pl: Player of interest
        :return: Calculated score
        """
        score = 0
        positions = self.piece_positions
        nx = self.n_x
        ny = self.n_y
        # Center column preference
        center_array = [int(i) for i in list(positions[:, nx // 2])]
        center_count = center_array.count(pl)
        score += center_count * CENTER_WEIGHT

        # Horizontal
        for r in range(ny):
            row_array = [int(i) for i in list(positions[r, :])]
            for c in range(nx - 3):
                window = row_array[c:c + WINDOW_LENGTH]
                score += self.evaluate_window(window, pl)

        # Vertical
        for c in range(nx):
            col_array = [int(i) for i in list(positions[:, c])]
            for r in range(ny - 3):
                window = col_array[r:r + WINDOW_LENGTH]
                score += self.evaluate_window(window, pl)

        # Positive diagonal
        for r in range(ny - 3):
            for c in range(nx - 3):
                window = [positions[r + i][c + i] for i in range(WINDOW_LENGTH)]
                score += self.evaluate_window(window, pl)

        # Negative diagonal
        for r in range(ny - 3):
            for c in range(nx - 3):
                window = [positions[r + 3 - i][c + i] for i in range(WINDOW_LENGTH)]
                score += self.evaluate_window(window, pl)

        return score


    def get_valid_locations(self):
        """
        self.get_valid_locations()
        Lists columns with space available to drop next piece
        :return: List of column indices
        """
        nx = self.n_x
        ny = self.n_y
        cols = self.col_heights
        return [c for c in range(nx) if cols[c] < ny]


    def score_position_after_move(self, col, pl):
        """Helper to produce quick heuristic for ordering moves in minimax"""
        valid_locations = self.get_valid_locations()
        if len(valid_locations) == 0:
            return -999999

        #print(self.next_piece)
        temp = copy.deepcopy(self)
        #print(temp.next_piece)
        temp.next_piece.x_i = col
        temp.drop_piece()
        return temp.score_position(pl)


    # --- Minimax with alpha-beta pruning ---
    def minimax(self, depth, alpha, beta, maximizingPlayer):
        """
        col, score = self.minimax(depth, alpha, beta, maximizingPlayer)
        Performs minimax optimisation to determine best move for AI player
        :param depth: Maximum tree search depth
        :param alpha: Pruning parameter for human player
        :param beta: Pruning parameter for AI
        :param maximizingPlayer: True if considering best move for human player, False
        :return col: column index of best move
        :return score: score reflecting AI player's ability to win based on recommended move
        """
        terminal = self.is_terminal_node() # check for end state
        if terminal:
            if self.winning_move(1):
                return None, 100000000000000 # Found AI winning move
            elif self.winning_move(0):
                return None, -100000000000000 # Found human player winning move
            else:
                return None, 0 # Stalemate
        if depth == 0:
            score = self.score_position(1)
            return None, score

        valid_locations = self.get_valid_locations()
        if maximizingPlayer:
            value = -math.inf
            chosen_col = random.choice(valid_locations)
            ordered = sorted(valid_locations, key=lambda c: self.score_position_after_move(c, 1), reverse=True)
            for col in ordered:
                b_copy = copy.deepcopy(self)
                b_copy.next_piece.x_i = col
                b_copy.drop_piece()
                b_copy.add_piece()
                col, new_score = b_copy.minimax(depth - 1, alpha, beta, False)
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
            ordered = sorted(valid_locations, key=lambda c: self.score_position_after_move(c, 0))
            for col in ordered:
                b_copy = copy.deepcopy(self)
                b_copy.next_piece.x_i = col
                b_copy.drop_piece()
                b_copy.add_piece()
                col, new_score = b_copy.minimax(depth - 1, alpha, beta, True)
                if new_score < value:
                    value = new_score
                    chosen_col = col
                beta = min(beta, value)
                if alpha >= beta:
                    break
            return chosen_col, value



