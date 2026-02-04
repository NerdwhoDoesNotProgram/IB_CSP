# IB 7th period Functions notes

def hello():
    print("Hello World!")

def full_name(first_name, last_name):
    return f"{first_name} {last_name}"

hello()
print(full_name("Vienna", "LaRose"))
name = full_name("Tia", "LaRose")
print(f"{name} doesn't like {full_name('Annabeth', 'Chase')}")

def factoral(number):
    total = 1
    for i in range(1, number +1):
        total *= i
    return total

for num in range(1,10):
    print(f"The factoral of {num} is {factoral(num)}")


def admin():
    name = "Ms. LaRose"
    print(f"{name} is the admin for the lab!")
    name = "Mrs. Derbidge"
    print(f"{name} is the admin for the lab!")

admin()