import pygame

class Launcher_Button:
    def __init__(self, text, pos, callback, image=None, hover_scale=1.08, font_size=28):
        self.text = text
        self.pos = pos
        self.callback = callback
        self.image = image
        self.hover_scale = hover_scale
        self.font = pygame.font.Font(None, font_size)

        # base rect determined from image or default size
        if self.image:
            self.base_image = self.image
            self.base_rect = self.base_image.get_rect(center=pos)
        else:
            # default rectangle if no image
            self.base_image = pygame.Surface((200, 80), pygame.SRCALPHA)
            self.base_image.fill((100, 100, 100))
            self.base_rect = self.base_image.get_rect(center=pos)

        # animation state
        self.target_scale = 1.0
        self.current_scale = 1.0
        self.scale_speed = 6.0  # how fast to animate scale
        self.hover = False

        # create hover glow surface once (semi-transparent)
        w, h = self.base_rect.size
        self.glow = pygame.Surface((w+40, h+20), pygame.SRCALPHA)
        pygame.draw.ellipse(self.glow, (255, 180, 60, 80), self.glow.get_rect())

        # clickable rect (updated each draw according to scale)
        self.rect = self.base_rect.copy()

    def update(self, dt):
        # Smoothly approach target_scale
        diff = self.target_scale - self.current_scale
        if abs(diff) > 0.001:
            self.current_scale += diff * min(1.0, dt * self.scale_speed)

        # update rect according to current_scale
        w = int(self.base_rect.width * self.current_scale)
        h = int(self.base_rect.height * self.current_scale)
        self.rect = pygame.Rect(0, 0, w, h)
        self.rect.center = self.base_rect.center

    def draw(self, screen):
        # draw glow if hovered
        if self.current_scale > 1.02:
            glow_rect = self.glow.get_rect(center=self.rect.center)
            screen.blit(self.glow, glow_rect)

        if self.image:
            # draw scaled image
            surf = pygame.transform.smoothscale(self.base_image, (self.rect.width, self.rect.height))
            screen.blit(surf, self.rect)
        else:
            pygame.draw.rect(screen, (60, 120, 200), self.rect, border_radius=12)

        # render text (centered)
        text_col = (10, 10, 10) if self.current_scale > 1.02 else (255, 255, 255)
        text_surf = self.font.render(self.text, True, text_col)
        text_rect = text_surf.get_rect(center=self.rect.center)
        screen.blit(text_surf, text_rect)

    def handle_event(self, event):
        if event.type == pygame.MOUSEMOTION:
            # update hover state
            self.hover = self.rect.collidepoint(event.pos)
            self.target_scale = self.hover_scale if self.hover else 1.0
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1 and self.rect.collidepoint(event.pos):
                # call callback
                try:
                    self.callback()
                except SystemExit:
                    raise
                except Exception as e:
                    print("Button callback exception:", e)