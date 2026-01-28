# Rock Paper Scissors... But Weird (Chaos Edition)
# Practice program with special unstoppable interactions

import random
import time  # Used only to slow down text for dramatic effect


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
    weird_items = [
        "flying banana",
        "haunted sock",
        "laser turtle",
        "homework monster"
    ]

    # ----- NUMBER INPUT -----
    if player_input.isdigit():
        computer_number = int(player_input) * 1_000_000
        print("You played the number:", player_input)
        print("Computer played the number:", computer_number)
        print("The computer's number is impossibly larger.")
        return "computer"

    # Computer chooses from weird + unstoppable options
    computer_choice = random.choice(unstoppable + weird_items)

    print("You played:", player_input)
    print("Computer played:", computer_choice)

    # ----- BLACK HOLE VS BLACK HOLE -----
    if player_input == "black hole" and computer_choice == "black hole":
        print("\nThe two black holes spiral around each other...")
        print(
            "They merge into a single, larger black hole, releasing massive\n"
            "amounts of energy as gravitational waves ripple through spacetime."
        )
        print("Reality collapses. You both lose this round.")
        return "none"

    # ----- BLACK HOLE VS ANGRY TEACHER -----
    if (
        (player_input == "black hole" and computer_choice == "angry teacher") or
        (player_input == "angry teacher" and computer_choice == "black hole")
    ):
        print("\nA battle of pure power begins.")
        print("They lock into an eternal staring contest.")
        print("The universe holds its breath...")
        return random.choice(["player", "computer"])

    # ----- ANGRY TEACHER VS ANGRY TEACHER -----
    if player_input == "angry teacher" and computer_choice == "angry teacher":
        print("\nTHE POWER IS UNSTOPPABLE.")
        print("THE PROGRAM CANNOT HANDLE THIS MUCH AUTHORITY.\n")

        # Fake crash by spamming errors
        for i in range(10):
            print("ERROR: TOO MUCH POWER")
            time.sleep(0.1)

        print("\nThe game barely survives. No one wins this round.")
        return "none"

    # ----- PLAYER USES UNSTOPPABLE -----
    if player_input in unstoppable:
        print("Your move is unstoppable.")
        return "player"

    # ----- COMPUTER USES UNSTOPPABLE -----
    if computer_choice in unstoppable:
        print("The computer used an unstoppable force.")
        return "computer"

    # ----- NORMAL WEIRD OUTCOME -----
    winner = random.choice(["player", "computer", "tie"])

    if winner == "player":
        print("You win this weird round.")
    elif winner == "computer":
        print("The computer wins this weird round.")
    else:
        print("It's a very strange tie.")

    return winner


# ----- GAME LOOP -----

play_again = "yes"

while play_again == "yes":

    player_score = 0
    computer_score = 0
    used_weird = False

    print("\nWelcome to Rock Paper Scissors...")
    print("First to 3 wins!\n")

    while player_score < 3 and computer_score < 3:
        print("Scores -> You:", player_score, "| Computer:", computer_score)
        player_choice = input(
            "Choose rock, paper, or scissors: "
        ).lower()

        if player_choice in ["rock", "paper", "scissors"]:
            computer_choice = get_computer_choice()

            print("You chose:", player_choice)
            print("Computer chose:", computer_choice)

            result = determine_winner(player_choice, computer_choice)

            if result == "player":
                player_score += 1
                print("You win this round!")
            elif result == "computer":
                computer_score += 1
                print("Computer wins this round!")
            else:
                print("It's a tie!")

        else:
            used_weird = True
            result = weird_round(player_choice)

            if result == "player":
                player_score += 1
            elif result == "computer":
                computer_score += 1

        print()

    # ----- ENDING -----

    if player_score == 3:
        print("🎉 YOU WON THE GAME!")
        if used_weird:
            print("Computer: \"You definitely cheated with cosmic entities.\"")
            print("Computer: \"Rematch. Immediately.\"")
        else:
            print("Computer: \"Fair and square... somehow.\"")
    else:
        print("🤖 COMPUTER WINS THE GAME!")
        print("Computer: \"I warned you not to challenge authority.\"")

    play_again = input("\nPlay again? (yes/no): ").lower()

print("\nGame terminated. Spacetime stabilizes.")
