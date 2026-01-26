# IB Finacial Calculator - Python

income = float(input("How much do you make monthly: $ "))

rent = float(input("How much is your rent per month: $ "))

utilities = float(input("How much is your utilities: $ "))

groceries = float(input("How much do you pay for groceries: $ "))

transportation = float(input("How much do you pay for transportation: $ "))

savings = float(income*0.10)

spending = float(income-rent-utilities-groceries-transportation-savings)



print("Your rent is $", rent, "and that is", int((rent/income)*100), "%","of your income")

print("Your utilities are $", utilities,"and that is", int((utilities/income)*100), "%", "of your income")

print("Your Groceries are $", groceries, "and that is", int((groceries/income)*100), "%", "of your income")

print("Your Transportation is $", transportation, "and that is", int((transportation/income)*100), "of your income")

print("You should save $", savings,"a month, and that is 10 % of your income" )

print("You have $", spending, "of sepending money each month!")