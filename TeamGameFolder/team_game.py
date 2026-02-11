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
# CONSTANTS | Written by 🎀 | Edited by 😊
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
    print("Inventory:", inventory.strip())
    print("Items:", len(inventory), "/", MAX_INVENTORY)

# -----------------------------------
# DROP ITEM | Written by 😊 | Edited by
# -----------------------------------

def drop_item():

    if not inventory:
        print("Inventory is empty.")
        return
    
    print("\nDrop which item?")

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
# SHOP | Written by 🎀 | Edited by 😊
# ----------------------------------

def potion_shop():
    
    global gold
    
    print("\n---POTION SHOP ---")
    print("potion cost 5 gold.")
    print("your gold:", gold)

    
    if len(inventory) >= MAX_INVENTORY:
        print("Inventory full. Drop something first.")
        return
    
    if gold < 5:
        print("you dummy, your poor, HA HA HA - GLG")
        return 
    
    buy = input("Buy potion? (yes/no): ").lower().strip()

    if buy == "yes":
        gold -= 5
        inventory.append("potion")
        print("You bought a potion!")
        
    
# -----------------------------------
# CHEST | Written by 😊 | Edited by 🎀
# -----------------------------------

def open_chest(room):

    print("\nYou found a chest!")
    
    if room == "forest":
        weapon = "stick"
    
    elif room == "cave":
        weapon = "magic wand"

    elif room == "river":
        weapon = "sword"
    
    else:
        weapon = "sword"
        
    print("Inside is a ", weapon + "!")
    
    if len(inventory) >= MAX_INVENTORY:
        
        print("Inventory full.")

        drop = input("🗑️ Drop item? (yes/no): ").lower().strip()
        
        if drop != "yes":
            return
        
        drop_item()
        
    inventory.append(weapon)

    print("You stored the", weapon + ".")

# -----------------------------------
# COMBAT  | Written by 🎀 | Edited by 😊
# -----------------------------------

def fight_monster(boss=False):
    
    global health, gold


    if boss:
        monster_health = random.randint(30, 36)
        print("\nTHE DARK BOSS APPEARS!")
    else: 
        
        monster_health = random.randint(5, 8)
        print("\nA monster attacks! OH NO!")

    while monster_health > 0 and health > 0:


        print("\nyour Health:", health)
        print("Enemy Health:", monster_health)
        print ("options: fight / run / heal")

        choice = input("> ").lower()

        if choice == "fight":

            weapon = get_best_weapon()
            power = weapons[weapon]

            player_damage =  random.randint(1, power + 2)
            monster_damage = random.randint(1, 3)

            monster_health -= player_damage 
            health -= monster_damage 

            print("you used:", weapon)
            print("you dealt:" , player_damage)
            print ("enemy dealt:", monster_damage)
      
        elif choice == "run":
            if boss: 
                print("You  cannot run from the boss!")

            else: 
                if random.randit(1,2) == 1:
                    print("You escaped!")
                
                else:
                    damage = random.randit(1, 2)
                    health -= damage 
                    print("Failed escape! Lost", damage)

        elif choice == "heal":

            if "potion" in inventory:
                
                inventory.remove("potion")
                health += 4

                print("Healed! health:", health)

            else:
                print("no potions!")

        else:
            print("Invalid command.")

    if monster_health <= 0:
    
      if boss:

        print ("\nYOU WIN! 🏆")
        return "win"

    else:
        reward =  random.randint(2, 5)
        gold += reward 

        print("Monster defeated!") 
        print("Gained", reward, "gold.")
        
# -----------------------------------
# RANDOM EVENT  | Written by 🎀 | Edited by 😊
# -----------------------------------

def random_event():
    
    event = random.randint(1, 4)

    if event == 1:

        if random.choice(["gold", "potion"]) == "gold":
            global gold 
            amount = random.randint(2,5)
            gold += amount

            print("you found", amount, "gold!")

        else:
            if len(inventory) < MAX_INVENTORY:

                inventory.append("potion")
                print("you found", amount, "gold!")

            else:

                print("Found a potion, but inventory is full.")

    elif event == 2:

        fight_monster()

    elif event == 3:

     print("Nothing happens...")

    elif event == 4:

        open_chest(current_room)
    



# -----------------------------------
# ROOMS  | Written by 🎀 | Edited by 😊
# -----------------------------------

def forest():
    print("\nyou are in a scary forest.")
    print("paths: north, east")

def cave():
    print("\nyou are in a dark cave.")
    print("paths: south, east")

def river():
    print ("\nyou stand beside a beautiful river.")
    print("paths: west, north")
    print("A potion stand is here.")

def temple():
    print("\ntyou enter the ancient temple.")

    result = fight_monster(boss=True)

    if result == "win":
        return True 

    return False 





# -----------------------------------
# MAIN  | Written by 😊 | Edited by 🎀 
# -----------------------------------

def main():

    global current_room, game_running

    reset_game()
    show_instructions()

    while game_running:

        if health <=0:

            print("\nGAME OVER 💀")

            again = input("Play again? ").lower().strip()

            if again == "yes":
                reset_game()
                continue
            else:
                break

        if current_room == "forest":
            forest()

        elif current_room == "cave":
            cave()

        elif current_room == "river":
            river()

        elif current_room == "temple":

            win = temple()

            if win:

                again = input("Play again? ").lower().strip()

                if again == "yes":
                    reset_game()
                    continue
                else:
                    break

        command = input("\nWhat do you do? ").lower().strip()

        moved = False

        # BASIC

        if command == "quit":
            break

        elif command == "inventory":
            show_inventory()

        elif command == "map":
            show_map()

        elif command == "drop":
            drop_item()

        elif command == "shop":

            if current_room == "river":
                potion_shop()
            else:
                print("No shop here.")

        # MOVEMENT

        elif command == "north":

            if current_room == "forest":
                current_room = "cave"
                moved = True

            elif current_room == "river":

                if "magic blade" in inventory:
                    current_room = "temple"
                    moved = True
                else:
                    print("Barrier! Need magic blade.")

            else:
                print("Can't go that way.")


        elif command == "south":

            if current_room == "cave":
                current_room = "forest"
                moved = True
            else:
                print("Can't go that way.")


        elif command == "east":

            if current_room == "forest":
                current_room = "river"
                moved = True

            elif current_room == "cave":

                if "magic blade" in inventory:
                    current_room = "temple"
                    moved = True
                else:
                    print("Barrier! Need magic blade.")

            else:
                print("Can't go that way.")
        
        elif command == "west":
            if current_room == "river":
                current_room = "forest"
                moved = True
            else:
                print("Can't go that way.")

        else:
            print("Unknown command.")

        if moved and current_room != "temple":
            random_event()


# -----------------------------------
# START  | Written by 😊
# -----------------------------------

main()
