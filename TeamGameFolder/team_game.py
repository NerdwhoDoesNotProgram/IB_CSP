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
# CONSTANTS | Written by 🎀 | Edited by
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
# RESET GAME | Written by 😊 | Edited by
# -----------------------------------

def reset_game():

    global health, gold,  inventory, current_room, game_running

    health = 12
    gold = 0
    inventory = []
    current_room = "forest"
    game_running = True

# -----------------------------------
# INSTRUCTIONS | Written by 😊 | Edited by
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
# MAP prints a simple map showing where you are. | Written by 😊 | Edited by
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
# BEST WEAPON | Written by 😊 | Edited by
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
# INVENTORY | Written by 😊 | Edited by
# -----------------------------------

def show_inventory():

    print("\n--------------------")
    print("Health:", health)
    print("Gold:",gold)
    print("Best Weapon:", get_best_weapon())
    print("Inventory:", inventory)
    print("Items:", len(inventory), "/", MAX_INVENTORY)

# -----------------------------------
# DROP ITEM | Written by 😊 | Edited by
# -----------------------------------

def drop_item():

    if not inventory:
        print("Inventory is empty.")
        return
    
    print("\nProp which item?")

    for i in range(len(inventory)):
        print(i+1, "-", inventory[i])

    try:
        choice = int(input(">")) - 1

        if 0<= choice < len(inventory):

            removed = inventory.pop(choice)
            print("Dropped:", removed)

        else:
            print("Invalid choice.")

    except:
        print("Invalid input.")

# -----------------------------------
# SHOP | Written by 🎀 | Edited by
# -----------------------------------