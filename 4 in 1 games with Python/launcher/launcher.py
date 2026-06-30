import sys
import os
import pygame
from pygame import mixer
from math import sin, cos


# Import updated Button
from .launcher_button import Launcher_Button as Button

# Import games
import games.captains_mistress as game1
import games.ludo as game2
import games.snap as game3

# ----------------- Config -----------------
WIN_W, WIN_H = 800, 600
FPS = 60

ASSETS_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "assets")
IMAGES_DIR = os.path.join(ASSETS_DIR, "images")
SOUNDS_DIR = os.path.join(ASSETS_DIR, "sounds")

BG_GIF = os.path.join(IMAGES_DIR, "background.gif")
BTN_IMG_1 = os.path.join(IMAGES_DIR, "cap_mistress.png")
BTN_IMG_2 = os.path.join(IMAGES_DIR, "ludo.png")
BTN_IMG_3 = os.path.join(IMAGES_DIR, "snap.png")
BTN_IMG_EXIT = os.path.join(IMAGES_DIR, "exit.png")

SOUND_BG = os.path.join(SOUNDS_DIR, "kids_gaming_music.mp3")
SOUND_CLICK = os.path.join(SOUNDS_DIR, "mouse_click_sound.mp3")
# ------------------------------------------

def load_image_safe(path, size=None):
    """Load an image or return a colored surface if missing."""
    try:
        img = pygame.image.load(path).convert_alpha()
        if size:
            img = pygame.transform.smoothscale(img, size)
        return img
    except Exception:
        w, h = size if size else (200, 80)
        surf = pygame.Surface((w, h), pygame.SRCALPHA)
        surf.fill((80, 80, 80, 230))
        return surf

def load_gif_frames(path, max_frames=None, scale_to=None):
    frames = []
    try:
        img = pygame.image.load(path)
        frames.append(img.convert())
    except Exception:
        # fallback: try background.jpg next to gif
        alt = os.path.splitext(path)[0] + ".jpg"
        try:
            img = pygame.image.load(alt)
            frames.append(img.convert())
        except Exception:
            frames = []
    # scale frames if requested
    if scale_to and frames:
        frames = [pygame.transform.smoothscale(f, scale_to) for f in frames]
    if not frames:
        # final fallback: plain gradient surface
        surf = pygame.Surface(scale_to if scale_to else (WIN_W, WIN_H))
        surf.fill((18, 24, 34))
        frames = [surf]
    return frames

def play_bg_music(path):
    if not os.path.isfile(path):
        return
    try:
        mixer.music.load(path)
        mixer.music.set_volume(0.35)
        mixer.music.play(-1) 
    except Exception as e:
        print("Warning: could not play background music:", e)

def load_click_sfx(path):
    if not os.path.isfile(path):
        return None
    try:
        return mixer.Sound(path)
    except Exception:
        return None

def center_positions_column(count, start_y, spacing, center_x):
    """Return list of (x,y) positions for centered vertical column."""
    positions = []
    total_h = (count - 1) * spacing
    top = start_y - total_h // 2
    for i in range(count):
        y = top + i * spacing
        positions.append((center_x, y))
    return positions

def main():
    pygame.init()
    mixer.init()
    screen = pygame.display.set_mode((WIN_W, WIN_H))
    pygame.display.set_caption("Game Launcher")
    clock = pygame.time.Clock()
    font = pygame.font.Font(None, 56)  # large title

    # Load animated background frames (scale to window)
    bg_frames = load_gif_frames(BG_GIF, scale_to=(WIN_W, WIN_H))
    bg_frame_count = len(bg_frames)
    bg_fps = 12  # how fast the gif cycles
    bg_timer = 0.0

    # Load sounds
    play_bg_music(SOUND_BG)
    click_sfx = load_click_sfx(SOUND_CLICK)

    # Button images + sizes
    btn_size = (200, 90)  # width, height
    btn_img_1 = load_image_safe(BTN_IMG_1, size=btn_size)
    btn_img_2 = load_image_safe(BTN_IMG_2, size=btn_size)
    btn_img_3 = load_image_safe(BTN_IMG_3, size=btn_size)
    btn_img_exit = load_image_safe(BTN_IMG_EXIT, size=(180, 60))

    # Buttons center column layout
    center_x = WIN_W // 2
    spacing = 130 # game buttons spacing between centers
    start_y = WIN_H // 2 + 20
    positions = center_positions_column(3, start_y, spacing, center_x)

    buttons = [
        Button("Captain's Mistress", positions[0], lambda: (click_sfx and click_sfx.play(), game1.main()), image=btn_img_1),
        Button("Ludo", positions[1], lambda: (click_sfx and click_sfx.play(), game2.main()), image=btn_img_2),
        Button("Snap", positions[2], lambda: (click_sfx and click_sfx.play(), game3.main()), image=btn_img_3),
    ]

    # Exit button centered at bottom
    exit_pos = (center_x, WIN_H - 60)
    exit_button = Button("Exit", exit_pos, lambda: (click_sfx and click_sfx.play(), pygame.quit(), sys.exit()), image=btn_img_exit)

    title_text = "Game Collection"
    subtitle_text = "Select a game"

    running = True
    while running:
        dt = clock.tick(FPS) / 1000.0  # seconds passed this frame
        bg_timer += dt

        # handle events
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                break
            for b in buttons:
                b.handle_event(event)
            exit_button.handle_event(event)

        # draw background frame (cycle at bg_fps)
        if bg_frames:
            frame_index = int((bg_timer * bg_fps)) % bg_frame_count
            screen.blit(bg_frames[frame_index], (0, 0))
        else:
            screen.fill((18, 24, 34))

        # subtle overlay vignette for nicer look
        vignette = pygame.Surface((WIN_W, WIN_H), pygame.SRCALPHA)
        for i in range(1):
            pygame.draw.rect(vignette, (0, 0, 0, 100), vignette.get_rect())
        screen.blit(vignette, (0, 0))

        # Title
        title_surf = font.render(title_text, True, (255, 220, 180))
        title_rect = title_surf.get_rect(center=(center_x, 80))
        screen.blit(title_surf, title_rect)

        # Subtitle smaller
        sub_font = pygame.font.Font(None, 28)
        sub_surf = sub_font.render(subtitle_text, True, (220, 220, 220))
        sub_rect = sub_surf.get_rect(center=(center_x, 120))
        screen.blit(sub_surf, sub_rect)

        # Draw and update buttons
        for b in buttons:
            b.update(dt)   # allow animation updates (hover)
            b.draw(screen)

        # Exit button draw (no hover scale on exit to keep it stable)
        exit_button.update(dt)
        exit_button.draw(screen)

        pygame.display.flip()

    pygame.quit()

if __name__ == "__main__":
    main()