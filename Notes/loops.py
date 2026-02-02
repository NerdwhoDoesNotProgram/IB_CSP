# IB 7th period Loops notes

import random # Library code that someone else wrote; always imort at the top

# Counts down from 18
"""start = 18

while start >= 1:
    print(start)
    start -= 2
"""

# Duck Duck Goose
"""goose = random.randint(1,20)
count = 1

while count < goose:
    print("Duck")
    count += 1
print("GOOSE!")"""


# Random number guessing game
number = random.randint(1,25)

while True:
    guess = int(input("Guess a number between 1 and 25: "))
    if guess == number:
        print(f"Congraduations! {number} was the number!")
        break #exit the loop
    elif guess > 25 or guess < 1:
        print("That is not an option.")
    elif guess < number:
        print("Your guess was too low")
    else:
        print('Your guess was too high')