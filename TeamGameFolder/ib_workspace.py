
# -----------------------------------
# COMBAT
# -----------------------------------

def fight_monster(boss=False):

    global health, gold


    if boss:
        monster_health = random.randint(30, 36)
        print("\nTHE DARK BOSS APPEARS!")
    else:
        monster_health = random.randint(5, 8)
        print("\nA monster attacks!")


    while monster_health > 0 and health > 0:


        print("\nYour Health:", health)
        print("Enemy Health:", monster_health)
        print("Options: fight / run / heal")

        choice = input("> ").lower()


        if choice == "fight":

            weapon = get_best_weapon()
            power = weapons[weapon]

            player_damage = random.randint(1, power + 2)
            monster_damage = random.randint(1, 3)

            monster_health -= player_damage
            health -= monster_damage

            print("You used:", weapon)
            print("You dealt:", player_damage)
            print("Enemy dealt:", monster_damage)


        elif choice == "run":

            if boss:
                print("You cannot run from the boss!")

            else:

                if random.randint(1, 2) == 1:
                    print("You escaped!")
                    return
                else:
                    damage = random.randint(1, 2)
                    health -= damage
                    print("Failed escape! Lost", damage)


        elif choice == "heal":

            if "potion" in inventory:

                inventory.remove("potion")
                health += 4

                print("Healed! Health:", health)

            else:
                print("No potions!")


        else:
            print("Invalid command.")


    if monster_health <= 0:

        if boss:

            print("\nYOU WIN! 🏆")
            return "win"

        else:

            reward = random.randint(2, 5)
            gold += reward

            print("Monster defeated!")
            print("Gained", reward, "gold.")


# -----------------------------------
# RANDOM EVENT
# -----------------------------------

def random_event():

    event = random.randint(1, 4)


    if event == 1:

        if random.choice(["gold", "potion"]) == "gold":

            global gold
            amount = random.randint(2, 4)
            gold += amount

            print("You found", amount, "gold!")

        else:

            if len(inventory) < MAX_INVENTORY:

                inventory.append("potion")
                print("You found a potion!")

            else:
                print("Found a potion, but inventory is full.")


    elif event == 2:

        fight_monster()


    elif event == 3:

        print("Nothing happens...")


    elif event == 4:

        open_chest(current_room)


# -----------------------------------
# ROOMS
# -----------------------------------

def forest():
    print("\nYou are in a quiet forest.")
    print("Paths: north, east")


def cave():
    print("\nYou are in a dark cave.")
    print("Paths: south, east")


def river():
    print("\nYou stand beside a river.")
    print("Paths: west, north")
    print("A potion stand is here.")


def temple():

    print("\nYou enter the ancient temple.")

    result = fight_monster(boss=True)

    if result == "win":
        return True

    return False