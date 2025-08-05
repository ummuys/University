import tkinter
import random
import pygame
import sys

pygame.init()


def prepare_and_start():
    global player, exit, fires, enemies, all_spawnpoints
    pygame.mixer_music.stop()
    all_spawnpoints = []
    canvas.delete("all")

    player_pos = set_spawnpoint()
    exit_pos = set_spawnpoint()

    player = canvas.create_image((player_pos[0], player_pos[1]), image=player_right, anchor='nw')
    exit = canvas.create_image((exit_pos[0], exit_pos[1]), image=exit_pic, anchor='nw')

    N_FIRES = 3  # Число клеток, заполненных огнем
    fires = []
    for i in range(N_FIRES):
        fire_pos = set_spawnpoint()
        fire = canvas.create_image(fire_pos, image=fire_pic, anchor='nw')
        fires.append(fire)

    enemies = []
    for i in enemy_pack_pic:
        enemy_pos = set_spawnpoint()
        enemy = canvas.create_image(enemy_pos, image=i, anchor='nw')
        enemies.append((enemy, random_move))

    label.config(text="Съешь фрукт!")
    master.bind("<KeyPress>", key_pressed)


def set_spawnpoint():
    global all_spawnpoints
    pos = (random.randint(0, N_X - 1) * step, random.randint(0, N_Y - 1) * step)
    while pos in all_spawnpoints:
        pos = (random.randint(0, N_X - 1) * step, random.randint(0, N_Y - 1) * step)
    all_spawnpoints.append(pos)
    return pos


# Рандомный ход
def random_move():
    return random.choice([(step, 0), (-step, 0), (0, step), (0, -step)])


# Движения персонажа
def move_wrap(obj, move):
    canvas.move(obj, move[0], move[1])

    if canvas.coords(obj)[0] < 0:
        canvas.move(obj, N_X * step, move[1])

    elif canvas.coords(obj)[0] >= N_X * step:
        canvas.move(obj, -N_X * step, move[1])

    elif canvas.coords(obj)[1] < 0:
        canvas.move(obj, move[0], N_Y * step)

    elif canvas.coords(obj)[1] >= N_Y * step:
        canvas.move(obj, move[0], -N_Y * step)


# Ничего не делать
def do_nothing(event):
    if event.keysym == "Escape":
        master.destroy()
        sys.exit()
    elif event.keysym == "R" or event.keysym == "r":
        prepare_and_start()
    else:
        pass


# Проверка на победу
def check_move():
    if canvas.coords(player) == canvas.coords(exit):
        pygame.mixer_music.load("sounds/win_sound.mp3")
        label.config(text="Победа!")
        master.bind("<KeyPress>", do_nothing)
        pygame.mixer_music.play(1)
        canvas.delete(exit)
    else:
        for f in fires:
            if canvas.coords(player) == canvas.coords(f):
                pygame.mixer_music.load("sounds/dying_sound.mp3")
                label.config(text="Ты проиграл!")
                pygame.mixer_music.play(1)
                master.bind("<KeyPress>", do_nothing)
                break

        for e in enemies:
            if canvas.coords(player) == canvas.coords(e[0]):
                pygame.mixer_music.load("sounds/dying_sound.mp3")
                label.config(text="Ты проиграл!")
                pygame.mixer_music.play(1)
                master.bind("<KeyPress>", do_nothing)
                break


def key_pressed(event):
    pygame.mixer_music.load("sounds/waka-waka.mp3")
    if event.keysym == 'Up' or event.keysym == 'Down' or event.keysym == 'Left' or event.keysym == 'Right':
        for enemy in enemies:
            direction = enemy[1]()  # вызвать функцию перемещения у "врага"
            move_wrap(enemy[0], direction)  # произвести перемещение

    if event.keysym == 'Up':
        canvas.itemconfig(player, image=player_up)
        move_wrap(player, (0, -step))
        pygame.mixer_music.play(1)

    elif event.keysym == 'Down':
        canvas.itemconfig(player, image=player_down)
        move_wrap(player, (0, +step))
        pygame.mixer_music.play(1)

    elif event.keysym == 'Left':
        canvas.itemconfig(player, image=player_left)
        move_wrap(player, (-step, 0))
        pygame.mixer_music.play(1)

    elif event.keysym == 'Right':
        canvas.itemconfig(player, image=player_right)
        move_wrap(player, (+step, 0))
        pygame.mixer_music.play(1)

    elif event.keysym == 'Escape':
        master.destroy()
        sys.exit()

    elif event.keysym == "R" or event.keysym == "r":
        prepare_and_start()

    check_move()

all_spawnpoints = []
step = 60  # Размер клетки
N_X = 10
N_Y = 10  # Размер сетки
master = tkinter.Tk()
font_label = ("Tiny5", 30)
label = tkinter.Label(master, text="Съешь фрукт!", font=font_label, bg='#FFF4C0', width=28)
label.pack()

canvas = tkinter.Canvas(master, bg='black', height=N_X * step, width=N_Y * step)
canvas.pack()

player_up = tkinter.PhotoImage(file="pacman/pacman_up.png")
player_down = tkinter.PhotoImage(file="pacman/pacman_down.png")
player_right = tkinter.PhotoImage(file="pacman/pacman_right.png")
player_left = tkinter.PhotoImage(file="pacman/pacman_left.png")

fire_pic = tkinter.PhotoImage(file="obj_pic/firetourch.png")
exit_pic = tkinter.PhotoImage(file="obj_pic/fruit.png")

enemy_red = tkinter.PhotoImage(file="enemys/enemy_red.png")
enemy_blue = tkinter.PhotoImage(file="enemys/enemy_blue.png")
enemy_yellow = tkinter.PhotoImage(file="enemys/enemy_yellow.png")
enemy_pink = tkinter.PhotoImage(file="enemys/enemy_pink.png")

enemy_pack_pic = [enemy_red, enemy_blue, enemy_yellow, enemy_pink]

restart = tkinter.Button(master, text="Начать заново", command=prepare_and_start)
restart.pack()
prepare_and_start()
master.mainloop()
