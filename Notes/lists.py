numbers = [3,2,43,54,5,653,32,5465,456789876543565435654,43,54]
room = [209, 201, 202, 213]
names = ["Alex", "Katie","Jake", "Vienna"]


names[0] = "Alexander"
names.append("Jayshree") #adds to the end of the list
index = names.index("Vienna")
names.pop(3) #removes jake
print(len(names))
print(names)

for name in names:
    print(f"Hello {name}")

for number in numbers:
    print(f"{number}-10 = {number-10}")

for i in range(20):
    print(f"this is the {i} iteration of this loop")