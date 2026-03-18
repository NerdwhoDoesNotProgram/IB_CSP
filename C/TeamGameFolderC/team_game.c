// =====================================================
// (Name TBD)
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

bool has_wand;
bool forest_hint_seen;
bool boss_defeated;

// --------------------------- Possibly unneeded now with how we have to do it, but we will see | Written by RH
// -----------------------------------
 //RESET GAME | Written by RH | Edited by
// -----------------------------------

// This is how we reset game if you die.
/*
int health;
int gold;
char inventory[5]; 
int current_room;
int game_running;

int reset_game();

health = 12;
gold = 0;
inventory[0] = " ";
current_room = "forest";
game_running = true;

// -----------------------------------
// INSTRUCTIONS | Written by RH | Edited by
// -----------------------------------
  
// Opening title page! Shows you the commands for the game.

int show_instructions(); 
*/
// --------------------------- Back to wat may now be needed.



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
// Add an item to the inventory if there is space
bool add_item(const char item[]) {
    if (inventory_count >= MAX_INVENTORY) {
        printf("Your inventory is full! You leave the %s behind.\n", item);
        return false;
    }

    inventory_count++;
    printf("You picked up: %s\n", item);

    // Potions increase potion count
    if (strcmp(item, "potion") == 0) { // strcmp compares two strings and returns 0 if they are the same. (like you have in your notes...) https://www.w3schools.com/c/ref_string_strcmp.php
        potions++;
    }
    // Stick upgrades weapon if stronger
    else if (strcmp(item, "stick") == 0) {
        if (weapon_power < 2) {
            weapon_power = 2;
            strcpy(current_weapon, "stick"); // strcpy is from string.h and copies the second string into the first string (which is why we needed string.h). https://www.w3schools.com/c/ref_string_strcpy.php
            printf("You equip the stick.\n");
        }
    }
    // Sword upgrades weapon if stronger
    else if (strcmp(item, "sword") == 0) {
        if (weapon_power < 4) {
            weapon_power = 4;
            strcpy(current_weapon, "sword");
            printf("You equip the sword.\n");
        }
    }
    // Magic wand upgrades weapon if stronger and unlocks temple
    else if (strcmp(item, "magic wand") == 0) {
        has_wand = true;
        if (weapon_power < 6) {
            weapon_power = 6;
            strcpy(current_weapon, "magic wand");
            printf("You equip the magic wand.\n");
        }
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

    potions--;
    inventory_count--;

    health += 4;
    if (health > MAX_HEALTH) {
        health = MAX_HEALTH;
    }

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

    has_wand = false;
    forest_hint_seen = false;
    boss_defeated = false;
}

// Written by IB | Edited by
// Show instructions for the player
void show_instructions() {
    printf("\n===== HOW TO PLAY =====\n");
    printf("Explore the forest, cave, river, and temple.\n");
    printf("Find better weapons and potions to survive.\n");
    printf("You may need to revisit places to discover new items.\n");
    printf("Commands: north, south, east, west, inventory, heal, quit\n");
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
// Show the simple map
void show_map() {
    printf("\n===== MAP =====\n");
    printf("        [North: Temple]\n");
    printf("[West: Forest] [Start] [East: Cave]\n");
    printf("        [South: River]\n");
    printf("================\n");
}


// ---------------------------
// Battle System | Written by IB | Edited by 
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
        } else if (strcmp(action, "heal") == 0) {
            if (use_potion()) {
                int enemy_damage = rand() % (enemy_damage_max - enemy_damage_min + 1) + enemy_damage_min;
                health -= enemy_damage;
                printf("The enemy attacks while you heal for %d damage!\n", enemy_damage);
            }
        } else if (strcmp(action, "run") == 0) {
            if (boss) {
                printf("You cannot run from the final boss!\n");
            } else {
                printf("You escaped!\n");
                return true;
            }
        } else {
            print("Invalid action");
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
        printf("You defeated the monster!\n");
    }

    return true;
}

// ---------------------------
// Room Functions | Written by RH | Edited by 
// ---------------------------
// forest room
bool forest_room(){
    printf("\n You enter the Forest.\n");

    if (!forest_hint_seen){
        printf("A paper pinned to a tree reads: \"Old places may hide new treasures.💰\"\n");
        forest_hint_seen = true;
    }
    
    int event = rand() % 3;
    
    if (event == 0) {
        printf("You find a potion near a tree stump.\n");
        add_item("potion");
    }
    else if (event == 1){
        printf("a wild beast jumps out from the bushes!🐺🐺\n");
        if (!fight_monster(false)) {
            return false;
        }
    }
    else {
        printf("The forest is quiet... to quiet.🦗🦗");
    }
    return true;
}

// cave room
    bool cave_room(){
        printf("\nYou enter the cave,👻 it looks spooky.👻👻\n"); // I added it lookes spooky for affects
        
        int event = rand() % 4;
       
        if (event == 0) {
            pritnf("You find a strudy stick on the ground,🥀 It's not the best.\n");
            add_item("srick");
        }
        else if (event ==1) {
            printf("You discover an old sword stuck in rocks.🗡️\n"); // I changed the frasing a bit
            add_item("sword");
        }
        else if (event ==2) {
            printf(" deep in the shadows you find... A MAGIC WAND!!🪄🪄\n"); // chnged words to sound more fun
            add_item("magic wand");
        }
        return true;
    }

// River room
    bool river_room(){
        printf("You walk to the river.\n");
        
        int event = rand() % 3;
        
        if (event == 0) {
            printf("")
        }
        
        
        
        return true;
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

    while (game_running && health > 0 && !boss_defeated) {
        show_map();
        show_stats();

        printf("\nWhere do you want to go? ");
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
        else if (strcmp(command, "inventory") == 0) {
            printf("\nYou are carrying:\n");
            printf("- Weapon: %s\n", current_weapon);
            printf("- Potions: %d\n", potions);
            printf("- Inventory slots used: %d/%d\n", inventory_count, MAX_INVENTORY);
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