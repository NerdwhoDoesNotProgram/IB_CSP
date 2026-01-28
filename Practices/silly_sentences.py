# IB Period 7  Silly Sentences - Python


choice = input("1 or 2: ")

punctuation_mark = input("Type of punctuation mark (Spell it out): ").lower()
number1 = input("Number of hours (Spell it out): ").lower()
verb = input("Verb ending in ing: ").lower()
number2 = input("Number between 1 and 100: ")

# If the user does not type out the punctuation, this fixes it.
if punctuation_mark == ",":
    punctuation_mark = "comma"

if punctuation_mark == ".":
    punctuation_mark = "period"

if punctuation_mark == "!":
    punctuation_mark = "exclamation mark"

if punctuation_mark == "?":
    punctuation_mark = "question mark"

if punctuation_mark == ";":
    punctuation_mark = "semicolon"

if punctuation_mark == "'":
    punctuation_mark = "apostrophe"

if punctuation_mark == ":":
    punctuation_mark = "colon"


# Prints out the sentence

if choice == "2": 
    print("After " + number1 + " hours of " + verb + ", I finally realized I was missing a " +  punctuation_mark + " on line " +  number2 + ".")

elif choice == "1":
    print("I spent " +  number1  + " hours " + verb + " to find why my code broke, only to discover that I typed a " +  punctuation_mark + " " + number2 + " times, instead of a variable name.")

else: 
    print("You chose " + choice + ", which wasn’t even an option. You know, after " + number1, "hours of staring at this code, I’m " + verb + " to think that", punctuation_mark, "on line", number2, "has better judgment than both of us.")

    