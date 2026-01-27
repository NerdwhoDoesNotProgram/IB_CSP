# IB Silly Sentences - Python


choice = input("1 or 2: ")

punctuation_mark = input("Type of punctuation mark: ")
number1 = input("Number of hours: ")
number2 = input("Number between 1 and 100: ")



if choice == "2": 
    print("After", number1, "hours of debugging, I finally realized I was missing a", punctuation_mark, "on line", number2 + ".")

elif choice == "1":
    print("I spent", number1, "hours trying to find why my code broke, only to discover I typed a", punctuation_mark, number2,"times, instead of a variable name.")

else: 
    print("You chose ", choice,", which wasn’t even an option. You know, after", number1, "hours of staring at this code, I’m starting to think that", punctuation_mark, "on line", number2, "has better judgment than both of us.")