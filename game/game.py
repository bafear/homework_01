import pgzrun
from random import randint
import random
WIDTH = 700
HEIGHT = 500
p = Actor('fox')
apple = Actor('apple')
yp = 350
score = 0
p.pos = (350,450)

def radd():
    y = random.choice('1234567')
    if y == '1':
        x = 50
    elif y == '2':
        x = 150
    elif y == '3':
        x = 250
    elif y == '4':
        x = 350
    elif y == '5':
        x = 450
    elif y == '6':
        x = 550
    elif y == '7':
        x = 650
    return x
    
def draw():
    screen.fill('blue')
    p.draw()
    apple.draw()

def place_apple():
    global score
    x = radd()
    apple.pos = (x,-10)
    score += 1
    
def update():
    global yp
    if yp == -50:
        yp = 650
    if yp == 750:
        yp = 50
    p.pos = (yp,450)
    apple.y += 6
    apple_collected = p.colliderect(apple)
    if apple_collected:
        place_apple()
    if apple.y > HEIGHT:
        x = radd()
        apple.pos = (x,-10)

def on_key_down(key):
    global yp
    if key == keys.LEFT:
         yp = yp-100
    if key == keys.RIGHT:
         yp = yp+100


pgzrun.go()
