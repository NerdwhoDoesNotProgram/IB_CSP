// IB RH, 7th period, Adventure RPG Game

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

const int max_inventory = 5;

char weapons[][4] = {
    "fists": 1,
    "stick": 2,
    "sword": 3,
    "magic wand": 4,
};

char rooms[][7] = {"forest", "cave", "river", "temple"};

// -----------------------------------
 //RESET GAME | Written by RH | Edited by
// -----------------------------------

// This is how we reset game if you die.

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
// INSTRUCTIONS | Written by 😊 | Edited by
// -----------------------------------
  
// Opening title page! Shows you the commands for the game.

int show_instructions();
   

