// add function to make a monster in the forest be the black knight
//show an 'X' at where you are on the map


// =====================================================
// THE HOLY GRAIL
// Written by: IB and RH
// 7th Period
// =====================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added for string handling functions like strcmp, strcpy, and strcspn (for input handling and inventory management)
#include <time.h> // Added for time function, which is used to seed the random number generator (for more varied gameplay, like damage and item drops)
#include <ctype.h> // Added for tolower function, which converts characters to lowercase (used in input handling)
#include <stdbool.h> // Added for bool, rather than having to use int (0 or 1) for true/false

// ---------------------------
// Global Constants | Written by RH | Edited by IB
// ---------------------------
#define MAX_INVENTORY 5
#define MAX_HEALTH 12

// ---------------------------
// Global Variables | Written by RH | Edited by IB
// ---------------------------
int health;
int potions;
int inventory_count;
int weapon_power;

char current_weapon[20];
char current_room[20];

bool has_wand;
bool forest_hint_seen;
bool boss_defeated;

char inventory[MAX_INVENTORY][20];


// ---------------------------
// Helper Functions | Written by IB | Edited by 
// ---------------------------

// Written by IB | Edited by
// Remove the newline character left by fgets
void remove_newline(char str[]) {
    str[strcspn(str, "\n")] = '\0'; // strcspn is from string.h and returns the index of the first occurrence of the second string in the first string (or the length of the first string if it is not found). This effectively replaces the newline character with a null terminator, removing it from the string. (In other words, it finds the newline character(\n) and replaces it with a null terminator, which ends the string there.) https://www.w3schools.com/c/ref_string_strcspn.php
}

// Written by IB | Edited by
// Convert a string to lowercase
void to_lowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]); // tolower is from ctype.h (which is why I added that as well) and converts a character to lowercase. https://www.geeksforgeeks.org/c/tolower-function-in-c/
    }
}

// Written by IB | Edited by
// Recalculate potion count, weapon, and wand after inventory changes
void recalculate_inventory_stats() {
    potions = 0;
    has_wand = false;
    weapon_power = 1;
    strcpy(current_weapon, "fists");

    for (int i = 0; i < inventory_count; i++) {
        if (strcmp(inventory[i], "potion") == 0) {
            potions++;
        }
        else if (strcmp(inventory[i], "stick") == 0) {
            if (weapon_power < 2) {
                weapon_power = 2;
                strcpy(current_weapon, "stick");
            }
        }
        else if (strcmp(inventory[i], "sword") == 0) {
            if (weapon_power < 4) {
                weapon_power = 4;
                strcpy(current_weapon, "sword");
            }
        }
        else if (strcmp(inventory[i], "magic wand") == 0) {
            has_wand = true;
            if (weapon_power < 6) {
                weapon_power = 6;
                strcpy(current_weapon, "magic wand");
            }
        }
    }
}

// Written by IB | Edited by
// Show numbered inventory list
void show_inventory_list() {
    printf("\nYou are carrying:\n");

    if (inventory_count == 0) {
        printf("- Nothing\n");
    } else {
        for (int i = 0; i < inventory_count; i++) {
            printf("%d. %s\n", i + 1, inventory[i]);
        }
    }

    printf("- Weapon equipped: %s\n", current_weapon);
    printf("- Potions: %d\n", potions);
    printf("- Inventory slots used: %d/%d\n", inventory_count, MAX_INVENTORY);
}

// Written by IB | Edited by
// Drop an item by number
bool drop_item() {
    char input[20];
    int choice;

    if (inventory_count == 0) {
        printf("You have nothing to drop.\n");
        return false;
    }

    show_inventory_list();
    printf("\nEnter the number of the item to drop (or 0 to cancel): ");
    fgets(input, sizeof(input), stdin);
    remove_newline(input);

    choice = atoi(input);

    if (choice == 0) {
        printf("You keep everything.\n");
        return false;
    }

    if (choice < 1 || choice > inventory_count) {
        printf("Invalid choice.\n");
        return false;
    }

    printf("You dropped: %s\n", inventory[choice - 1]);

    for (int i = choice - 1; i < inventory_count - 1; i++) {
        strcpy(inventory[i], inventory[i + 1]);
    }

    inventory_count--;
    inventory[inventory_count][0] = '\0';

    recalculate_inventory_stats();
    return true;
}

// Written by IB | Edited by
// Add an item to the inventory if there is space
bool add_item(const char item[]) {
    char input[20];
    int choice;

    if (inventory_count >= MAX_INVENTORY) {
        printf("Your inventory is full! You found a %s.\n", item);
        show_inventory_list();
        printf("\nChoose an item number to drop for the new %s, or 0 to leave it behind: ", item);

        fgets(input, sizeof(input), stdin);
        remove_newline(input);

        choice = atoi(input);

        if (choice == 0) {
            printf("You leave the %s behind.\n", item);
            return false;
        }

        if (choice < 1 || choice > inventory_count) {
            printf("Invalid choice. You leave the %s behind.\n", item);
            return false;
        }

        printf("You dropped: %s\n", inventory[choice - 1]);

        for (int i = choice - 1; i < inventory_count - 1; i++) {
            strcpy(inventory[i], inventory[i + 1]);
        }

        inventory_count--;
        inventory[inventory_count][0] = '\0';

        recalculate_inventory_stats();
    }

    strcpy(inventory[inventory_count], item);
    inventory_count++;

    printf("You picked up: %s\n", item);

    recalculate_inventory_stats();

    if (strcmp(item, "stick") == 0 && strcmp(current_weapon, "stick") == 0) {
        printf("You equip the stick.\n");
    }
    else if (strcmp(item, "sword") == 0 && strcmp(current_weapon, "sword") == 0) {
        printf("You equip the sword.\n");
    }
    else if (strcmp(item, "magic wand") == 0 && strcmp(current_weapon, "magic wand") == 0) {
        printf("You equip the magic wand.\n");
    }

    return true;
}

// Written by IB | Edited by
// Use one potion to heal the player
bool use_potion() {
    if (potions <= 0) {
        printf("You don't have any potions!\n");
        return false;
    }

    if (health >= MAX_HEALTH) {
        printf("You are already at full health.\n");
        return false;
    }

    for (int i = 0; i < inventory_count; i++) {
        if (strcmp(inventory[i], "potion") == 0) {
            for (int j = i; j < inventory_count - 1; j++) {
                strcpy(inventory[j], inventory[j + 1]);
            }

            inventory_count--;
            inventory[inventory_count][0] = '\0';
            break;
        }
    }

    health += 4;
    if (health > MAX_HEALTH) {
        health = MAX_HEALTH;
    }

    recalculate_inventory_stats();

    printf("You used a potion and restored health!\n");
    printf("Health: %d/%d | Potions left: %d\n", health, MAX_HEALTH, potions);

    return true;
}

// ---------------------------
// Game Setup / Display | Written by IB | Edited by 
// ---------------------------

// Written by IB | Edited by
// Reset all game variables at the start of a new game
void reset_game() {
    health = MAX_HEALTH;
    potions = 0;
    inventory_count = 0;
    weapon_power = 1;

    strcpy(current_weapon, "fists");
    strcpy(current_room, "start");

    has_wand = false;
    forest_hint_seen = false;
    boss_defeated = false;

    for (int i = 0; i < MAX_INVENTORY; i++) {
        inventory[i][0] = '\0';
    }
}

// Written by IB | Edited by
// Show instructions for the player
void show_instructions() {
    printf("\n===== HOW TO PLAY =====\n");
    printf("Explore the forest, cave, river, and temple.\n");
    printf("Find better weapons and potions to survive.\n");
    printf("You may need to revisit places to discover new items.\n");
    printf("Commands: north, south, east, west, map, inventory, drop, heal, quit\n");
    printf("In battle: fight, heal, run\n");
    printf("Goal: Defeat the final boss in the temple!\n");
    printf("========================\n\n");
}

// Written by IB | Edited by
// Show current player stats
void show_stats() {
    printf("\n----- PLAYER STATS -----\n");
    printf("Health: %d/%d\n", health, MAX_HEALTH);
    printf("Weapon: %s (Power %d)\n", current_weapon, weapon_power);
    printf("Potions: %d\n", potions);
    printf("Inventory Slots Used: %d/%d\n", inventory_count, MAX_INVENTORY);
    printf("------------------------\n");
}

// Written by IB | Edited by
// Returns X if the player is in that room
char mark_room(const char room[]) {
    if (strcmp(current_room, room) == 0) {
        return 'X';
    }
    return ' ';
}

// Written by IB | Edited by
// Show the simple map
void show_map() {
    printf("\nMAP:\n\n");
    printf("   [C%c]---[T%c]\n", mark_room("cave"), mark_room("temple"));
    printf("   [F%c]---[@%cR]\n", mark_room("forest"), mark_room("river"));

    if (strcmp(current_room, "start") == 0) {
        printf("        ^ You are at Start\n");
    }

    printf("\nLegend:\n");
    printf("X = You\n");
    printf("C = Cave\n");
    printf("T = Temple\n");
    printf("F = Forest\n");
    printf("R = River\n");
    printf("@ = Start\n");
}


// ---------------------------
// Battle System | Written by IB | Edited by RH
// ---------------------------
bool fight_monster(bool boss) {
    int enemy_health;
    int enemy_damage_min;
    int enemy_damage_max;

    if (boss) {
        enemy_health = rand() % 5 + 24; // 24 through 28
        enemy_damage_min = 2;
        enemy_damage_max = 4;

        printf("\n*** FINAL BOSS APPEARS! ***\n");
        printf("This enemy looks powerful... you hope you came prepared.\n");
    } else {
        enemy_health = rand() % 4 + 5; // 5 to 8
        enemy_damage_min = 1;
        enemy_damage_max = 3;

        printf("\nA monster attacks!\n");
    }

    while (enemy_health > 0 && health > 0) {
        char action[20];

        printf("\nEnemy Health: %d\n", enemy_health);
        printf("Your Health: %d/%d\n", health, MAX_HEALTH);
        printf("Choose action (fight/heal/run): ");

        fgets(action, sizeof(action), stdin);
        remove_newline(action);
        to_lowercase(action);

        if (strcmp(action, "fight") == 0) {
            int player_damage = rand() % (weapon_power + 2) + 1;
            enemy_health -= player_damage;
            printf("You hit for %d damage!\n", player_damage);

            if (enemy_health > 0) {
                int enemy_damage = rand() % (enemy_damage_max - enemy_damage_min + 1) + enemy_damage_min;
                health -= enemy_damage;
                printf("The enemy hits you for %d damage!\n", enemy_damage);
            }
        }
        else if (strcmp(action, "heal") == 0) {
            if (use_potion()) {
                int enemy_damage = rand() % (enemy_damage_max - enemy_damage_min + 1) + enemy_damage_min;
                health -= enemy_damage;
                printf("The enemy attacks while you heal for %d damage!\n", enemy_damage);
            }
        }
        else if (strcmp(action, "run") == 0) {
            if (boss) {
                printf("You cannot run from the final boss! As you turn away, he devours you whole!\n");
                health = 0;
            } else {
                printf("You escaped!\n");
                return true;
            }
        }
        else {
            printf("Invalid action\n");
        }
    }

    if (health <= 0) {
        printf("\nYou were defeated...\n");
        return false;
    }

    if (boss) {
        printf("\n*** You defeated the final boss and won the game! ***\n");
        boss_defeated = true;
    } else {
        printf("\nYou defeated the monster!\n");
    }

    return true;
}

// ---------------------------
// Room Functions | Written by RH | Edited by 
// ---------------------------
// forest room
bool forest_room() {
    strcpy(current_room, "forest");

    printf("\nYou enter the Forest.\n");

    if (!forest_hint_seen) {
        printf("\nA paper pinned to a tree reads: \"Old places may hide new treasures.💰\"\n");
        forest_hint_seen = true;
    }

    int event = rand() % 3;

    if (event == 0) {
        printf("\nYou find a potion near a tree stump.\n");
        add_item("potion");
    }
    else if (event == 1) {
        printf("\nYou encounter the black knight. \n");
        if (!fight_monster(false)) {
            return false;
        }
    }
    else {
        printf("\nThe forest is quiet... too quiet.🦗🦗\n");
    }

    strcpy(current_room, "start");
    return true;
}

// cave room
bool cave_room() {
    strcpy(current_room, "cave");

    printf("\nYou enter the cave,👻 it looks spooky.👻👻\n"); // I added it looks spooky for affects

    int event = rand() % 4;

    if (event == 0) {
        printf("\nYou find a sturdy stick on the ground,🥀 It's not the best.\n");
        add_item("stick");
    }
    else if (event == 1) {
        printf("\nYou discover an old sword stuck in rocks.🗡️\n"); // I changed the frasing a bit
        add_item("sword");
    }
    else if (event == 2) {
        printf("\nDeep in the shadows you find... A MAGIC WAND!!🪄🪄\n"); // changed words to sound more fun
        add_item("magic wand");
    }
    else {
        printf("\nThe cave chest is empty.\n");
        printf("A note inside reads: \"Raided... but treasures return to those who check again.\"\n");
    }

    strcpy(current_room, "start");
    return true;
}

// River room
bool river_room() {
    strcpy(current_room, "river");

    printf("\nYou walk to the river.\n");

    int event = rand() % 4;

    if (event == 0) {
        printf("\nYou find a potion floating near the shore.\n");
        add_item("potion");
    }
    else if (event == 1) {
        printf("\nSomething lurks near the water... It's a gnome! He runs towards you.\n");
        if (!fight_monster(false)) {
            return false;
        }
    }
    else if (event == 2) {
        printf("\nSomething lurks near the water... It's a gnome! He runs away.\n");
    }
    else {
        printf("\nThe river is calm you take a short rest.\n");
    }

    strcpy(current_room, "start");
    return true;
}

// Temple room
bool temple_room() {
    strcpy(current_room, "temple");

    printf("\nYou arrive at the ancient temple of the gods.\n");

    if (!has_wand) {
        printf("\nA magical barrier blocks you from entering the temple.\n");
        printf("\nA glowing poneglyph says: \"Only the wand lets past.\"\n");
        strcpy(current_room, "start");
        return true;
    }

    printf("\nYou cast a spell and the barrier disappears in your eyes.\n");
    printf("\nYou step into the temple\n");

    bool result = fight_monster(true);
    strcpy(current_room, "start");
    return result;
}


// ---------------------------
// Main Game Loop | Written by  | Edited by 
// ---------------------------

// Written by IB | Edited by
// Run one full game
void play_game() {
    char command[20];
    bool game_running = true;

    reset_game();
    show_instructions();
    show_map();

    while (game_running && health > 0 && !boss_defeated) {
        show_stats();

        printf("\nWhat do you want to do or go? ");
        fgets(command, sizeof(command), stdin);
        remove_newline(command);
        to_lowercase(command);

        if (strcmp(command, "north") == 0) {
            // If player has the wand, they may enter the temple and fight the boss
            if (has_wand) {
                if (!temple_room()) {
                    game_running = false;
                }
            } else {
                // Otherwise, just show the barrier message
                temple_room();
            }
        }
        else if (strcmp(command, "south") == 0) {
            if (!river_room()) {
                game_running = false;
            }
        }
        else if (strcmp(command, "east") == 0) {
            if (!cave_room()) {
                game_running = false;
            }
        }
        else if (strcmp(command, "west") == 0) {
            if (!forest_room()) {
                game_running = false;
            }
        }
        else if (strcmp(command, "map") == 0) {
            show_map();
        }
        else if (strcmp(command, "inventory") == 0) {
            show_inventory_list();
        }
        else if (strcmp(command, "drop") == 0) {
            drop_item();
        }
        else if (strcmp(command, "heal") == 0) {
            use_potion();
        }
        else if (strcmp(command, "quit") == 0) {
            printf("You leave the adventure behind.\n");
            game_running = false;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    if (boss_defeated) {
        printf("\nCongratulations, adventurer!\n");
    }
    else if (health <= 0) {
        printf("\nGame Over.\n");
    }
}

// ---------------------------
// Main Function | Written by  | Edited by 
// ---------------------------

// Written by IB | Edited by
int main() {
    char play_again[10];

    srand(time(NULL));

    printf("=====================================\n");
    printf("           THE HOLY GRAIL\n");
    printf("=====================================\n");

    do {
        play_game();
        printf("\nWould you like to play again? (yes/no): ");
        fgets(play_again, sizeof(play_again), stdin);
        remove_newline(play_again);
        to_lowercase(play_again);
    } while (strcmp(play_again, "yes") == 0);

    printf("\nThanks for playing!\n");
    return 0;
}