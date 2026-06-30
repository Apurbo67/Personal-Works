import math
import random
import copy

# from game_mechanics import GameMechanics

# Minimax settings (tune depth for difficulty / speed)
AI_DEPTH = 5  # 4-6 is typical; higher = stronger but slower

# Heuristic weights
WINDOW_LENGTH = 4
CENTER_WEIGHT = 3


class CMAIPlayer:

    def __init__(self, mech):
        """
        player = CMAIPlayer(mech)
        Creates Captain's Mistress AI object
        :param mech: GameMechanics object
        """
        self.mechanics = mech # game mechanics object


    def take_turn(self):
        """
        self.take_turn()
        AI player takes turn
        :return: returns True if turn is completed successfully and False otherwise
        """
        #board = copy.deepcopy(self.mechanics)
        #col, minimax_score = board.minimax(AI_DEPTH, -math.inf, math.inf, True) # Use minimax algorithm to decide next move
        col, minimax_score = self.mechanics.minimax(AI_DEPTH, -math.inf, math.inf, True)  # Use minimax algorithm to decide next move
        if col is None: # No result from minimax algorithm, use pick_best_move instead
            col = self.pick_best_move(1)
        self.mechanics.next_piece.x_i = col
        # dropped = self.mechanics.drop_piece()
        drop = self.mechanics.start_drop()
        if drop:
            return True
        else:
            return False


    def pick_best_move(self,pl):
        """
        col = self.pick_best_move(pl)
        Picks the most advantageous move for a given player based on the current game state, without using minimax algorithm
        :param pl: Player making move. Equal to 0 for human or 1 for AI
        :return: Index of best column for player to drop piece
        """
        valid_locations = self.mechanics.get_valid_locations()
        best_score = -math.inf
        best_col = random.choice(valid_locations)
        for col in valid_locations: # score each column
            temp_board = copy.deepcopy(self.mechanics)
            temp_board.next_piece.x_i = col
            temp_board.drop_piece()
            score = temp_board.score_position(pl)
            if score > best_score: # update best score
                best_score = score
                best_col = col
        return best_col
