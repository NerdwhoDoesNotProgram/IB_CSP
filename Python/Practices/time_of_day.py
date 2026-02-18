# IB 7th period Time of Day - python

from datetime import datetime

# Get the current date and time
now = datetime.now()

# Access the hour attribute
current_hour = now.hour


def unknown_time():
    print("Good think I know,")
    if time < 12:
     print("Good Morning!")

    elif time >= 12 and time < 18:
     print("Good Afternoon!")

    elif time < 0 or time > 24:
        print("That is not a time.")

    else:
     print("Good Evening!")

def known_time():
    if time_input < 12:
     print("Good Morning!")

    elif time_input >= 12 and time_input < 18:
     print("Good Afternoon!")

    elif time_input < 0 or time_input > 24:
        print("That is not a time.")

    else:
     print("Good Evening!")


do_you_know = input("Do you know what time it is (Yes/No): ").strip().capitalize()

if do_you_know == "Yes":
   time_input = int(input("What is the hour in military time: "))
   known_time()

else:
  time = current_hour
  unknown_time()
  