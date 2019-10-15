import pgzrun
from random import randint
import random
WIDTH = 700
HEIGHT = 500
p = Actor('fox')
apple = Actor('apple')
yp = 350
Score = 0
Time = 0
Time_apple = 0
p.pos = (350,450)
apples = []
Game_start = False
Game_end = False

def time_count():
    global Time ,Game_end
    if Game_end == False:
        Time += 1

def time_out():
    global Game_end
    Game_end = True

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
    global Game_end
    screen.fill('blue')
    p.draw()
    for apple in apples:
        apple.draw()
    screen.draw.text('Time : '+str(Time),color='black',topleft=(10,10))
    if Game_end:
        #screen.fill('pink')
        msg = "Time out, final score : "+str(Score)
        screen.draw.text(msg,topleft=(150,250),fontsize=50)

def place_apple():
    global Score
    x = radd()
    Score += 1
    
def update():
    global yp ,Game_end
    if Game_end == False:
        if yp == -50:
            yp = 650
        if yp == 750:
            yp = 50
        p.pos = (yp,450)
        for apple in apples:
            apple.y += 6
            apple_collected = p.colliderect(apple)
            if apple_collected:
                place_apple()
                apples.remove(apple)
            if apple.y > HEIGHT:
                apples.remove(apple)

def on_key_down(key):
    global yp
    if key == keys.LEFT:
         yp = yp-100
    if key == keys.RIGHT:
         yp = yp+100

def time_count_apple():
    global Time_apple
    Time_apple += 1
    apples.append(Actor('apple'))
    last = len(apples)
    apples[last-1].pos = (radd(),-20)

clock.schedule_interval(time_count,1.0)
clock.schedule_interval(time_count_apple,0.7)

pgzrun.go()
