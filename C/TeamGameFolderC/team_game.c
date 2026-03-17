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
// Battle System | Written by  | Edited by 
// ---------------------------


// ---------------------------
// Room Functions | Written by  | Edited by 
// ---------------------------


// ---------------------------
// Main Game Loop | Written by  | Edited by 
// ---------------------------


// ---------------------------
// Main Function | Written by  | Edited by 
// ---------------------------