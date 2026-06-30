import pygame

class Game:

    def __init__(self,screen,name):
        self.screen = screen
        self.state = "start"
        self.name = name

        # Set up text display
        self.font = pygame.font.Font(pygame.font.get_default_font(), 24)
        self.text = self.font.render(self.name, True, "black")
        self.textRect = self.text.get_rect()

    def step(self):
        """Method to step through game"""
        match self.state:
            case "start":
                self.draw_game()
            case "running":
                self.get_input()

    def draw_game(self):
        self.screen.fill("pink")
        self.screen.blit(self.text, self.textRect)
        self.state = "running"


    def get_input(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_0]:
            self.state = "quit"