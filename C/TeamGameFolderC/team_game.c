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

bool has_wand;
bool forest_hint_seen;
bool boss_defeated;


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

/*
//Written by IB | Edited by
// Updates the map as to show you where you are

pos = current_room

char mark(room) {
    if (room ==)
}
*/


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
        } else if (strcmp(action, "heal") == 0) {
            if (use_potion()) {
                int enemy_damage = rand() % (enemy_damage_max - enemy_damage_min + 1) + enemy_damage_min;
                health -= enemy_damage;
                printf("The enemy attacks while you heal for %d damage!\n", enemy_damage);
            }
        } else if (strcmp(action, "run") == 0) {
            if (boss) {
                printf("You cannot run from the final boss! As you turn away, he devours you whole!\n");
                health = 0;
            } else {
                printf("You escaped!\n");
                return true;
            }
        } else {
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
    printf("\nYou enter the Forest.\n");

    if (!forest_hint_seen){
        printf("\nA paper pinned to a tree reads: \"Old places may hide new treasures.💰\"\n");
        forest_hint_seen = true;
    }
    
    int event = rand() % 3;
    
    if (event == 0) {
        printf("\nYou find a potion near a tree stump.\n");
        add_item("potion");
    }
    else if (event == 1){
        printf("\nYou encounter the black knight. \n");
        if (!fight_monster(false)) {
            return false;
        }
    }
    else {
        printf("\nThe forest is quiet... too quiet.🦗🦗\n");
    }
    return true;
}

// cave room
bool cave_room() {
    printf("\nYou enter the cave,👻 it looks spooky.👻👻\n"); // I added it looks spooky for affects
        
    int event = rand() % 4;
       
    if (event == 0) {
         printf("\nYou find a sturdy stick on the ground,🥀 It's not the best.\n");
          add_item("stick");
    } else if (event ==1) {
        printf("\nYou discover an old sword stuck in rocks.🗡️\n"); // I changed the frasing a bit
        add_item("sword");
    } else if (event ==2) {
        printf(" \nDeep in the shadows you find... A MAGIC WAND!!🪄🪄\n"); // changed words to sound more fun
        add_item("magic wand");
    } else {
        printf("\nThe cave chest is empty.\n");
        printf("A note inside reads: \"Raided... but treasures return to those who check again.\"\n");
    }
    return true;
}

// River room
bool river_room() {
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
        printf("\nThe river is calm. You take a short rest.\n");
    }
        
    return true;
}
// Temple room
bool temple_room() {
    printf("\nYou arrive at the ancient temple of the gods.\n");

    if (!has_wand) {
        printf("\nA magical barrier blocks you from entering the temple.\n");
        printf("\nA glowing poneglyph says: \"Only the wand lets past.\"\n");
        return true;
    }
    printf("\nYou cast a spell and the barrier disappears before your eyes.\n");
    printf("\nYou step into the temple\n");

    return fight_monster(true);

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

// Written by IB | Edited by
int main() {
    char play_again[10];

    srand(time(NULL));

    printf("=====================================\n");
    printf("           THE HOLY GRAIL\n");
    printf("=====================================\n");

    do  {
        play_game();
        printf("\nWould you like to play again? (yes/no): ");
        fgets(play_again, sizeof(play_again), stdin);
        remove_newline(play_again);
        to_lowercase(play_again);
    } while (strcmp(play_again, "yes") == 0);
    
    printf("\nThanks for playing!\n");
    return 0;
}