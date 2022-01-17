
import sys
import pygame
from random import randint
from pygame import font
from pygame import sprite
from pygame import draw
from pygame import color
from pygame import rect
from pygame import image
from pygame.locals import*
from pygame.time import Clock
from pygame.version import ver

#Initialize python window
pygame.init()
screenWidth = 500
screenHeight =500
screen = pygame.display.set_mode((screenWidth,screenHeight))
pygame.display.set_caption('Breaker Brick')

#Colors
ORANGE = (255,128,0)
RED = (153,0,0)
DARKBLUE = (0,0,102)
GREY = (64,244,208)
score = 0
lives = 3

#Pygame clock setup
clock = pygame.time.Clock()

class Paddle(pygame.sprite.Sprite):
    def __init__(self, color, width, height):
        super().__init__()
        self.vel = 5
        self.image = pygame.Surface([width,height])
        self.mask = pygame.mask.from_surface(self.image)
        pygame.draw.rect(self.image,color,[0,0,width,height])
        self.rect = self.image.get_rect()
        

class projectile(pygame.sprite.Sprite):
    def __init__(self,color):
        super().__init__()
        self.velocity = [randint(2,6),randint(-6,6)]
        self.image = pygame.Surface([10,10])
        self.image.fill((0,0,0))
        self.image.set_colorkey((0,0,0))
        self.mask = pygame.mask.from_surface(self.image)
        pygame.draw.circle(self.image, color, [self.image.get_width()//2,self.image.get_height()//2], 5)
        self.rect = self.image.get_rect()
    def update(self):
        self.rect.x += self.velocity[0]
        self.rect.y += self.velocity[1]
    def reset(self):
        self.rect.x = 500/2
        self.rect.y = 500/2
        self.velocity = [randint(2,6),randint(-8,8)]


class squares(pygame.sprite.Sprite):
    def __init__(self,color, width, height):
        super().__init__()
        self.image = pygame.Surface([width,height])
        pygame.draw.rect(self.image, color, [0,0,width,height])
        self.rect = self.image.get_rect()

#Sprite Mangment
allSprites = pygame.sprite.Group()
allBalls = pygame.sprite.Group()
allBricks = pygame.sprite.Group()

#Font
font = pygame.font.Font(pygame.font.get_default_font(),12)


#Creating the Paddle
player = Paddle(GREY, 50, 10)
player.rect.x = 200
player.rect.y = 450
allSprites.add(player)

#Creating the Ball
pong = projectile((255,255,255))
pong.rect.x = player.rect.x + 23    
pong.rect.y = player.rect.y - 20
allBalls.add(pong)
allSprites.add(pong)
maxBallSpeed = [-6,6]

#Create Brick Layout
for i in range(6):
    for l in range(6):
        brick = squares(ORANGE, 70, 30)
        brick.rect.x = 10 + l * 80
        brick.rect.y = 40 + i * 40
        allSprites.add(brick)
        allBricks.add(brick)
    

#Update Screen Function (Called once per frame)
def updateDisplay():
    screen.fill(DARKBLUE)
    allSprites.draw(screen)
    text = font.render('Score: ' + str(score), 1, (255,255,255))
    text3 = font.render('Lives: ' +str(lives), 1, (255,0,0))
    screen.blit(text, (10,10))
    screen.blit(text3, (400, 10))
    pygame.display.flip()
    pygame.display.update()

inGame = True
#Main game loop
while inGame:

    #FrameRate Limit
    clock.tick(60)

    #Pygame Event handeling
    for event in pygame.event.get():
        if event.type == QUIT:
            sys.exit()

    #Sprite Updates
    allSprites.update()

    #input setup
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and player.rect.x > player.vel:
        player.rect.x-= player.vel
        paddleDirection = -1
    if keys[pygame.K_RIGHT] and player.rect.x < screenWidth - player.rect.width - player.vel:
        player.rect.x+= player.vel
        paddleDirection = -1
    

    #Ball Logic
    for pong in allBalls:
        if pong.rect.y <= 0:
            pong.velocity[1] = -pong.velocity[1]
        if pong.rect.x <= 0:
            pong.velocity[0] = -pong.velocity[0]
        if pong.rect.x >= 500:
            pong.velocity[0] = -pong.velocity[0]
        if pong.rect.y >= 500:
            pong.reset()
            lives -= 1
            if lives <= 0:
                screen.fill(DARKBLUE)
                text2 = font.render('YOU LOSE!',1,(255,0,0))
                text4 = font.render('Final Score: ' + str(score) ,1, (255,255,255))
                screen.blit(text2,(225,250))
                screen.blit(text4,(225,270))
                pygame.display.flip()
                pygame.display.update()
                pygame.time.wait(5000)
                inGame = False
        if pong.velocity[0] == 0:
            pong.velocity[0] += 1
        if pong.velocity[1] == 0:
            pong.velocity[1] += 1

    #Paddle and Ball Collision detection
    paddleDirection = 1
    if pygame.sprite.spritecollideany(player,allBalls):
        if abs(pong.rect.bottom - player.rect.top) < 8 and pong.velocity[1] > 0:
            if paddleDirection == 1:
                pong.velocity[1] = -pong.velocity[1]
                pong.velocity[0] += paddleDirection
                if pong.velocity[1] > maxBallSpeed[1]:
                    pong.velocity[1] = maxBallSpeed[1]
                if pong.velocity[1] > maxBallSpeed[0]:
                    pong.velocity[1] = maxBallSpeed[0]
            if paddleDirection == -1:
                pong.velocity[1] = -pong.velocity[1]
                pong.velocity[0] += paddleDirection
                if pong.velocity[1] > maxBallSpeed[1]:
                    pong.velocity[1] = maxBallSpeed[1]
                if pong.velocity[1] > maxBallSpeed[0]:
                    pong.velocity[1] = maxBallSpeed[0]

        else:
            pong.velocity[1] *= -1


    #Ball and Brick Collision detection
    brickCollision = pygame.sprite.spritecollide(pong, allBricks, False)
    for brick in brickCollision:
        if abs(pong.rect.bottom - brick.rect.top) < 8 and pong.velocity[1] > 0:
            pong.velocity[1] = -pong.velocity[1]
        if abs(pong.rect.top - brick.rect.bottom) < 8 and pong.velocity[1] < 0:
            pong.velocity[1] = -pong.velocity[1]
        if abs(pong.rect.left - brick.rect.right) < 8 and pong.velocity[1] > 0:
            pong.velocity[0] = -pong.velocity[0]
        if abs(pong.rect.right - brick.rect.left) < 8 and pong.velocity[1] > 0:
            pong.velocity[0] = -pong.velocity[0]
        if abs(pong.rect.left - brick.rect.right) < 8 and pong.velocity[1] < 0:
            pong.velocity[0] = -pong.velocity[0]
        if abs(pong.rect.right - brick.rect.left) < 8 and pong.velocity[1] < 0:
            pong.velocity[0] = -pong.velocity[0]
        brick.kill()
        score += 1
        
        #End Game Conditions
        if len(allBricks) == 0:
                screen.fill(DARKBLUE)
                text2 = font.render('YOU WIN!',1,(255,255,255))
                text4 = font.render('Final Score: ' + str(score) ,1, (255,255,255))
                screen.blit(text2,(225,250))
                screen.blit(text4,(225,270))
                pygame.display.flip()
                pygame.display.update()
                pygame.time.wait(5000)
                inGame = False
    
    updateDisplay()
    

pygame.quit()    
