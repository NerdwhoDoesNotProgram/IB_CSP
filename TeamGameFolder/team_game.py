#  IB GLG, 7th period, Adventure RPG Game - Improved Version

# GLG = 🎀
# IB = 😊

# Step by step  plan:
# Defines each of the needed variables, including room names
# 
# Plans the rooms
# Makes you able to decide what/where to go.
# Loops that choice
# Boss
# Win or lose

import random

#------------------
# CONSTANTS 🎀
#------------------

MAX_INVENTORY = 5

weapons = {
"fists": .5,
"stick": 2,
"sword": 4,
"magic wand":6
}

rooms = ["forest", "cave", "river", "temple"]

# -----------------------------------
# RESET GAME 😊
# -----------------------------------

def reset_game():

    global health, gold,  inventory, current_room, game_running

    health = 12
    gold = 0
    inventory = []
    current_room = "forest"
    game_running = True

# -----------------------------------
# INSTRUCTIONS 😊
# -----------------------------------

def show_instructions():
    print("\n===================================")
    print("     ADVENTURE RPG GAME")
    print("===================================")
    print("Commands:")
    print(" north / south / east / west")
    # print(" look")
    print(" inventory")
    print(" map")
    print(" drop")
    print(" shop")
    print(" quit")
    print("===================================")

# -----------------------------------
# MAP prints a simple map showing where you are. 😊
# -----------------------------------

def show_map():

    pos = current_room # pos is position


    def mark(room):
        if room == pos:
            return "x"
        return " "
    
    print("\nMAP:\n")

    print(f" [C{mark('cave')}]---[T{mark('temple')}]")
    print("   |")
    print(f" [F{mark('forest')}]---[💰R{mark('river')}]")

    print("\nLegend: \nX = You \nC = cave \nT = Temple \nF = forest \nR = river \n💰 = potion shop")


# -----------------------------------
# BEST WEAPON 😊
# -----------------------------------

def get_best_weapon():
    best = "fists"
    best_power = weapons["fists"]

    for item in inventory:

        if item in weapons:

            if weapons[item] > best_power:
                best = item
                best_power = weapons[item]

    return best

# -----------------------------------
# INVENTORY 😊
# -----------------------------------

def show_inventory():

    print("\n--------------------")
    print("Health:", health)
    print("Gold:",gold)
    print("Best Weapon:", get_best_weapon())
    print("Inventory:", inventory)
    print("Items:", len(inventory), "/", MAX_INVENTORY)

# -----------------------------------
# DROP ITEM 😊
# -----------------------------------