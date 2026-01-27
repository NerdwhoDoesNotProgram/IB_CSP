# IB Finacial Calculator - Python

income = round(float(input("What is your monthly income: $ ")), 2)

rent = round(float(input("What is your monthly rent/mortgage: $ ")), 2)

utilities = round(float(input("What are your monthly utilities: $ ")), 2)

groceries = round(float(input("What is your monthly groceries: $ ")), 2)

transportation = round(float(input("What is your monthly transportation: $")), 2)

percent = round(float(input("What percentage of your income would you like to save? (Exclude the percentage symbol) It is recomended 10% and higher: ")), 2)

percent_of_savings = percent/100

savings = round(float(income*percent_of_savings), 2)

spending = round(float(income-rent-utilities-groceries-transportation-savings), 2)



print("Your rent is $", rent, "and that is", round((rent/income)*100), "%","of your income")

print("Your utilities are $", utilities,"and that is", round((utilities/income)*100), "%", "of your income")

print("Your Groceries are $", groceries, "and that is", round((groceries/income)*100), "%", "of your income")

print("Your Transportation is $", transportation, "and that is", round((transportation/income)*100), "% of your income")

print("You should save $", savings,"a month, and that is", int(percent), "% of your income" )

print("You have $", spending, "of sepending money each month!")
