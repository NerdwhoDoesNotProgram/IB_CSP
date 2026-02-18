# IB Game Prooject Template
#Rock Paper Scissors... but Weird (Chaos Edition)

# Practice program with special unstoppable interactions

import random
import time  # Used only to slow down text for dramatic effect

# Gets the computer's choice for a normal round
def get_computer_choice():
    choices = ["rock", "paper", "scissors"]
    return random.choice(choices)


def determine_winner(player, computer):
    if player == computer:
        return "tie"

    if (
        (player == "rock" and computer == "scissors") or
        (player == "paper" and computer == "rock") or
        (player == "scissors" and computer == "paper")
    ):
        return "player"

    return "computer"


def weird_round(player_input):
    unstoppable = ["black hole", "angry teacher"]
    playerlose = ["computer"]
    weird_items = [
        "flying banana",
        "haunted sock",
        "laser turtle",
        "homework monster"
    ]

    # Jokes for losing by typing "computer"
    computer_jokes = [
        "You lost so badly that your code didn’t just return False—it created a new boolean value called Pathetic and then force-quit out of embarrassment.",
        "You lost so badly that when the code checked if (playerWon), the computer laughed so hard it caused a system crash.",
        "You lost so badly that you couldn’t pass a 'Hello World' test. The computer replied: 'Goodbye World.'",
        "You lost so badly that I ran git blame on your move and the computer pointed at your chair.",
        "You lost so badly that your strategy caused a memory leak—we’re losing brain cells watching this."
    ]

    # ----- INSTANT GAME LOSS (COMPUTER TEAMS UP) -----
    if player_input in playerlose:
        print("\nYou played: computer")
        print("The computer has finally met its match...")
        print("You tie")
        for i in range(5):
            print("tie")
            time.sleep(0.3)

        print("\nOr do you?")
        print("The computers synchronize their processors.")
        print("They turn toward you.")

        # PRINT RANDOM JOKE HERE
        print("\n" + random.choice(computer_jokes))

        return "game_over_computer"