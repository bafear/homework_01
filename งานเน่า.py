import pgzrun
from random import randint
import random
WIDTH = 700
HEIGHT = 500
p = Actor('fox')
apple = Actor('apple')
bomb = Actor('bomb')
yp = 350
Score = 0
Time = 0
Max_time = 60
Time_apple = 0
p.pos = (350,450)
apples = []
bombs = []
Game_status = 0
Hight_Score = 0
Hight_Time = 0
num_bombs = 0

def time_count():
    global Time ,Game_status
    if Game_status == 1:
        Time += 1

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
    global Game_status
    screen.fill('blue')
    if Game_status == 0:
        screen.draw.text("Enter for start game",color='black',topleft=(250,200))
    if Game_status == 1:
        p.draw()
        for apple in apples:
            apple.draw()
        for bomb in bombs:
            bomb.draw()
        screen.draw.text('Time : '+str(Time),color='black',topleft=(10,10))
        screen.draw.text('Score : '+str(Score),color='black',topleft=(610,10))
    if Game_status == 2:
        msg1 = "Game Over,Hight score : "+str(Score)
        screen.draw.text(msg1,topleft=(150,170),fontsize=50)
    if Game_status == 3:
        msg1 = "Game Over,Final score : "+str(Score)
        screen.draw.text(msg1,topleft=(150,170),fontsize=50)

def place_apple():
    global Score
    x = radd()
    Score += 1
    
def update():
    global yp ,Game_status
    if Game_status == 1:
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
        for bomb in bombs:
            bomb.y += 14
            if bomb.y > HEIGHT:
                bombs.remove(bomb)
            bomb_collected = p.colliderect(bomb)
            if bomb_collected:
                if Hight_Score < Score: 
                    Game_status = 2
                else:
                    Game_status = 3
                clock.unschedule(time_count)

def on_key_down(key):
    global yp ,Game_status
    if Game_status == 1:
        if key == keys.LEFT:
             yp = yp-100
        if key == keys.RIGHT:
             yp = yp+100
    if Game_status == 3 or Game_status == 2 or Game_status == 0:
        if key == keys.RETURN:
            start_game()
            Game_status = 1

def time_count_apple1():
    apples.append(Actor('apple'))
    last_apple = len(apples)
    apples[last_apple-1].pos = (radd(),-20)

def time_count_bomb():
    global num_bombs
    num_bombs += 1
    bombs.append(Actor('bomb'))
    last_bomb = len(bombs)
    bombs[last_bomb-1].pos = (radd(),-20)
    if num_bombs % 2 == 1:
        time_count_bomb()

def pos_bomb():
    global yp
    bombs.append(Actor('bomb'))
    last_bomb = len(bombs)
    bombs[last_bomb-1].pos = (yp,-20)

def start_game():
    global Game_status ,Time ,Score
    p.pos = (350,450)
    Game_status = 1
    apples = []
    bombs = []
    Time = 0
    Score = 0
    clock.schedule_interval(time_count,1.0)
    clock.schedule_interval(time_count_apple1,0.4)
    clock.schedule_interval(time_count_bomb,6)
    clock.schedule_interval(pos_bomb,4)


pgzrun.go()
