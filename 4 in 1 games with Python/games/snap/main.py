import os
import pygame
import random

# menu overlay
def choose_mode_ui(window):
    W, H = window.get_size()
    btn_w, btn_h = 220, 70
    gap = 40
    WHITE, BLACK = (255, 255, 255), (0, 0, 0)
    RED, BLUE = (200, 30, 30), (30, 80, 200)
    LARGE = pygame.font.Font(None, 32)
    classic = pygame.Rect(0, 0, btn_w, btn_h); classic.center = (W//2, H//2 - (btn_h//2 + gap))
    arcade  = pygame.Rect(0, 0, btn_w, btn_h); arcade.center  = (W//2, H//2 + (btn_h//2 + gap))
    checkbox = pygame.Rect(W//2 + 50, H//2 + 180, 30, 30)
    hardmode = False

    BASE_DIR = os.path.dirname(os.path.abspath(__file__))
    background = pygame.image.load(os.path.join(BASE_DIR, 'background.jpg'))
    clock = pygame.time.Clock()
    # button inputs
    while True:
        for e in pygame.event.get():
            if e.type == pygame.QUIT: return "classic", hardmode
            if e.type == pygame.KEYUP and e.key == pygame.K_ESCAPE: return "classic", hardmode
            if e.type == pygame.MOUSEBUTTONDOWN and e.button == 1:
                if classic.collidepoint(e.pos): return "classic", hardmode
                if arcade.collidepoint(e.pos):  return "arcade", hardmode
                if checkbox.collidepoint(e.pos):
                    hardmode = not hardmode
        # background
        window.blit(background, (0, 0))
        t = LARGE.render("Choose Mode", True, BLACK)
        window.blit(t, t.get_rect(center=(W//2, H//2 - 150)))
        # draw buttons
        for rect, label in ((classic,"Classic"), (arcade,"Arcade")):
            pygame.draw.rect(window, RED, rect, border_radius=12)
            pygame.draw.rect(window, WHITE, rect, width=3, border_radius=12)
            lbl = LARGE.render(label, True, WHITE)
            window.blit(lbl, lbl.get_rect(center=rect.center))
        # checkbox
        pygame.draw.rect(window, WHITE, checkbox, width=3)
        window.blit(LARGE.render("Hard Mode(?):", True, BLACK), (checkbox.left - 160, checkbox.y))
        if hardmode:
            pygame.draw.rect(window, RED, checkbox.inflate(-6, -6))
            text = LARGE.render("Yes", True, BLACK)
            window.blit(text, (checkbox.right + 10, checkbox.y))

        pygame.display.flip()
        clock.tick(60)

def main():
    global previous_card, current_card, snap_window_open, AI_snap, flipped_cards, snap_text, snap_colour, player_deck, AI_deck, AI_snap_delay, player_snap_time, wait_flip, AI_cards, player_cards
    pygame.init()

    # ---- setup -----
    pygame.display.set_caption("Snap")
    # window dimensions wxh
    screen_width = 800
    screen_height = 600
    window = pygame.display.set_mode((screen_width, screen_height))
    mode, hardmode = choose_mode_ui(window)
    # card size width and height
    card_width, card_height = 80, 116
    # load images background and deck
    BASE_DIR = os.path.dirname(os.path.abspath(__file__))
    background = pygame.image.load(os.path.join(BASE_DIR, 'background.jpg'))
    deck_back = pygame.image.load(os.path.join(BASE_DIR, "deck.png"))
    # colours & fonts
    WHITE, BLACK = (255,255,255), (0,0,0)
    RED, BLUE, GREY = (200,30,30), (30,80,200), (210,210,210)
    LARGE = pygame.font.Font(None, 32)
    SMALL = pygame.font.Font(None, 24)
    # position coordinates
    PLAYER_POS = (screen_width//2 - card_width//2, screen_height - 180)
    AI_POS     = (screen_width//2 - card_width//2, 60)
    CENTRE_POS = (screen_width//2 - card_width//2, screen_height//2 - card_height//2)
    # rectangle blocks (click)
    pile_rect = pygame.Rect(PLAYER_POS[0], PLAYER_POS[1], card_width, card_height)
    snap_rect = pygame.Rect(CENTRE_POS[0], CENTRE_POS[1], card_width, card_height)

    # load card images
    def load_card():
        ranks = [2, 3, 4, 5, 6, 7, 8, 9, 10, 'jack', 'queen', 'king', 'ace']
        suits = ['hearts', 'diamonds', 'spades', 'clubs']
        images = {}
        for suit in suits:
            for rank in ranks:
                card_name = f"{rank}_of_{suit}"
                images [card_name] = pygame.image.load(os.path.join(BASE_DIR, "cards", f"{card_name}.png"))
        return images

    # create deck
    def create_deck():
        ranks = [2, 3, 4, 5, 6, 7, 8, 9, 10, 'jack', 'queen', 'king', 'ace']
        suits = ['hearts', 'diamonds', 'spades', 'clubs']
        return[f"{rank}_of_{suit}"for suit in suits for rank in ranks]

    card_images = load_card()
    deck = create_deck()
    random.shuffle(deck)

    # initial state
    player_cards = deck[0:int(len(deck)//2)]
    AI_cards = deck[int(len(deck)//2):len(deck)]
    flipped_cards = []
    previous_card = None
    current_card = None
    snap_window_open = False
    wait_flip = False
    AI_snap = None
    AI_flip = None
    turn = "player"
    snap_text = ""
    if hardmode:
        AI_flip_delay = 1000
        AI_snap_delay = 500
    else:
        AI_flip_delay = 1500
        AI_snap_delay = 1200
    game_over = False
    winner_text = ""
    player_snap_time = None
    if hardmode:
        timer = 40
    else:
        timer = 60
    time_left = timer if mode == "arcade" else None
    player_score = 0 if mode == "arcade" else None
    AI_score = 0 if mode == "arcade" else None
    snap_colour = None

    # flip cards function
    def flip_card(who):
        global previous_card, current_card, snap_window_open, AI_snap, AI_snap_delay, player_snap_time, wait_flip
        pile = player_cards if who == "player" else AI_cards
        if not pile:
            return False
        previous_card = current_card
        current_card = pile.pop()
        flipped_cards.append(current_card)

        # if ranks match open snap window and set AI snap timer
        if previous_card and current_card and previous_card[0] == current_card[0]:
            snap_window_open = True
            snap_start_time = pygame.time.get_ticks()
            AI_snap = snap_start_time + AI_snap_delay
            if hardmode:
                AI_snap_delay = random.randint(600, 900)
            elif player_snap_time is not None:
                AI_snap_delay = max(550, int(player_snap_time-snap_start_time))
        else:
            AI_snap = None
            snap_window_open = False
        wait_flip = False
        return True

    # awards flipped cards to either player or AI
    def award(to):
        global flipped_cards, snap_window_open, AI_snap, wait_flip, player_cards, AI_cards
        if not flipped_cards:
            return
        random.shuffle(flipped_cards)
        if to == "player":
            player_cards = flipped_cards + player_cards # add pile to front of list (under deck)
        else:
            AI_cards = flipped_cards + AI_cards
        flipped_cards = []
        snap_window_open = False
        AI_snap = None
        wait_flip = True

    # For clicking centre pile to snap
    def player_snap():
        nonlocal player_score
        global player_snap_time, snap_text, snap_colour
        if not snap_window_open:
            return
        player_snap_time = pygame.time.get_ticks()
        if previous_card and current_card and previous_card[0] == current_card[0]:
            award("player")
            snap_text, snap_colour = "PLAYER SNAP!", RED
            if mode == "arcade":
                player_score += 10
    def incorrect_snap():
        nonlocal player_score
        global snap_text, snap_colour, wait_flip
        if not snap_window_open:
            if wait_flip:
                return
            award("AI")
            snap_text, snap_colour = "INCORRECT SNAP!", RED
            if mode == "arcade":
                player_score -= 10

    # game loop
    clock = pygame.time.Clock()
    running = True
    while running:
        dt = clock.tick(60)/1000.0
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

                # Draw rectangle for mouse click
            if event.type == pygame.MOUSEBUTTONDOWN:
                x, y = pygame.mouse.get_pos()
                if not game_over:
                    if pile_rect.collidepoint(x, y) and turn == "player":
                        if flip_card("player"):
                            turn = "AI"
                            AI_flip = pygame.time.get_ticks() + AI_flip_delay
                            snap_text = ""
                    if snap_rect.collidepoint(x, y) and snap_window_open:
                        player_snap()
                    elif snap_rect.collidepoint(x, y) and not snap_window_open:
                        incorrect_snap()

        if mode == "arcade" and not game_over and time_left is not None:
            time_left -= dt
            if time_left <= 0:
                time_left = 0
                game_over = True
                if player_score > AI_score:
                    winner_text = f"Player Wins!  {player_score} : {AI_score}"
                elif AI_score > player_score:
                    winner_text = f"AI Wins!  {AI_score} : {player_score}"
                else:
                    winner_text = f"Draw!  {player_score} : {AI_score}"

        # AI's actions
        if turn == "AI" and AI_flip and pygame.time.get_ticks() >= AI_flip:  # if AI's turn and flip time passed
            if flip_card("AI"):
                turn = "player"
                AI_flip = None  # reset AI timer
                snap_text = ""

        if AI_snap and snap_window_open and pygame.time.get_ticks() >= AI_snap:
            award("AI")
            snap_text, snap_colour = "AI SNAP!", BLUE
            if mode == "arcade":
                AI_score += 10
            AI_snap = None  # reset AI timer
            turn = "player"

        window.blit(background, (0, 0))
        player_deck = window.blit(deck_back, PLAYER_POS)
        AI_deck = window.blit(deck_back, AI_POS)

        # Snap display text
        if snap_text:
            txt = (LARGE.render(snap_text, True, snap_colour))
            window.blit(txt, (CENTRE_POS[0] + card_width//2 - txt.get_width()//2, CENTRE_POS[1] - 50))

        # flipped cards & count text
        if current_card:
            window.blit(card_images[current_card], (360, 242))
        pile_txt = SMALL.render(f"Pile: {len(flipped_cards)}", True, BLACK)
        window.blit(pile_txt, (360, 218))

        # card counters (convert to string to text image)
        if mode == "classic":
            p_count = SMALL.render(f"Player cards: {len(player_cards)}", True, BLACK)
            a_count = SMALL.render(f"AI cards: {len(AI_cards)}", True, BLACK)
            window.blit(p_count, (PLAYER_POS[0] + card_width//2 - p_count.get_width()//2, PLAYER_POS[1] + card_height + 6))
            window.blit(a_count, (AI_POS[0] + card_width//2 - a_count.get_width()//2, AI_POS[1] - 20))
        else:
            hud_time = LARGE.render(f"Timer: {int(time_left)}s", True, BLACK)
            hud_p = SMALL.render(f"Player score: {player_score}", True, BLACK)
            hud_ai = SMALL.render(f"AI score: {AI_score}", True, BLACK)
            window.blit(hud_time, (screen_width - 120, 20))
            window.blit(hud_p, (PLAYER_POS[0] + card_width//4 - 40, PLAYER_POS[1] + card_height + 6))
            window.blit(hud_ai, (AI_POS[0] + card_width//4 - 30, AI_POS[1] - 20))

        # check winner
        if mode == "classic" and not game_over and (len(player_cards) == 0 or len(AI_cards) == 0):
            game_over = True
            if len(player_cards) > len(AI_cards):
                winner_text = "Player Wins!"
            elif len(AI_cards) > len(player_cards):
                winner_text = "AI Wins!"
        # end game screen (transparent)
        if game_over:
            overlay = pygame.Surface((screen_width, screen_height), pygame.SRCALPHA)
            overlay.fill((0, 0, 0, 120))
            window.blit(overlay, (0, 0))
            end = LARGE.render(f"Game Over: {winner_text}", True, WHITE)
            window.blit(end, (screen_width//2 - end.get_width()//2, screen_height//2 - 20))

        pygame.display.update()

if __name__ == "__main__":
    main()

