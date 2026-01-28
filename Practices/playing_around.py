# Rock Paper Scissors... But Weird (Extra Version)
# Practice program with special unbeatable inputs

import random


# Chooses a normal RPS option for the computer
def get_computer_choice():
    choices = ["rock", "paper", "scissors"]
    return random.choice(choices)


# Determines winner for normal RPS
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


# Handles weird/special rounds
def weird_round(player_input):
    unstoppable = ["black hole", "angry teacher"]
    weird_items = [
        "flying banana",
        "haunted sock",
        "laser turtle",
        "homework monster"
    ]

    # If the player types a number
    if player_input.isdigit():
        computer_number = int(player_input) * 1000000
        print("You played the number:", player_input)
        print("Computer played the number:", computer_number)
        print("The computer's number is impossibly larger.")
        return "computer"

    # If player uses an unstoppable move
    if player_input in unstoppable:
        print("You played:", player_input)
        print("That move is unstoppable.")
        return "player"

    # Computer randomly chooses what to counter with
    computer_choice = random.choice(unstoppable + weird_items)

    print("You played:", player_input)
    print("Computer played:", computer_choice)

    # If computer uses an unstoppable move, it wins
    if computer_choice in unstoppable:
        print("The computer used an unstoppable force.")
        return "computer"

    # Otherwise, choose a random outcome
    winner = random.choice(["player", "computer", "tie"])

    if winner == "player":
        print("You win this weird round.")
    elif winner == "computer":
        print("The computer wins this weird round.")
    else:
        print("It's a weird tie.")

    return winner


# ----- GAME LOOP (allows replay) -----

play_again = "yes"

while play_again == "yes":

    player_score = 0
    computer_score = 0
    used_weird = False

    print("\nWelcome to Rock Paper Scissors")
    print("First to 3 wins!\n")

    # Main round loop
    while player_score < 3 and computer_score < 3:
        print("Scores -> You:", player_score, "| Computer:", computer_score)
        player_choice = input(
            "Choose rock, paper, or scissors: "
        ).lower()

        # Normal RPS path
        if player_choice in ["rock", "paper", "scissors"]:
            computer_choice = get_computer_choice()

            print("You chose:", player_choice)
            print("Computer chose:", computer_choice)

            result = determine_winner(player_choice, computer_choice)

            if result == "player":
                print("You win this round!")
                player_score += 1
            elif result == "computer":
                print("Computer wins this round!")
                computer_score += 1
            else:
                print("It's a tie!")

        # Weird / special input path
        else:
            used_weird = True
            result = weird_round(player_choice)

            if result == "player":
                player_score += 1
            elif result == "computer":
                computer_score += 1

        print()

    # ----- END GAME MESSAGES -----

    if player_score == 3:
        print("🎉 YOU WON THE GAME!")

        if used_weird:
            print("Computer: \"HEY! Black holes and angry teachers aren't fair!\"")
            print("Computer: \"Rematch. NOW.\"")
        else:
            print("Computer: \"Impossible... you followed the rules.\"")

    else:
        print("🤖 COMPUTER WINS THE GAME!")
        print("Computer: \"Predictable. Even your weird moves failed.\"")
        print("Computer: \"Come back when you invent stronger nonsense.\"")

    play_again = input("\nPlay again? (yes/no): ").lower()

print("\nGame over. The black hole consumes the console.")
