# IB 7th period Updated financial calculator


# 1st update (I think that I did it right... I really over-thought it, so it is probably overly-complex from what was needed.)
"""def get_money(prompt):
    return round(float(input(prompt)), 2)


def get_percent(income, expense):
    return round((expense / income) * 100)


def print_category(name, income, amount):
    percent = get_percent(income, amount)
    print(f"Your {name} is ${amount:.2f} and that is {percent}% of your income")



income = get_money("What is your monthly income: $ ")

rent = get_money("What is your monthly rent/mortgage: $ ")

utilities = get_money("What are your monthly utilities: $ ")

groceries = get_money("What are your monthly groceries: $ ")

transportation = get_money("What is your monthly transportation: $ ")

savings_percent = get_money("What percentage of your income would you like to save? ")

savings = round(income * (savings_percent / 100), 2)

spending = round(
    income - rent - utilities - groceries - transportation - savings, 2
)


print_category("rent", income, rent)

print_category("utilities", income, utilities)

print_category("groceries", income, groceries)

print_category("transportation", income, transportation)

print_category("savings", income, savings)

print(f"You have ${spending:.2f} of spending money each month!")"""


# I think that I really over-thought all of this, so it got a lot more complex than needed.

def get_money(prompt):
    return round(float(input(prompt)), 2)

def get_percent(income, expense):
    return round((expense / income) * 100)

def print_category(name, income, amount):
    percent = get_percent(income, amount)
    print(f"Your {name} is ${amount: .2f} and that is {percent}% of your income")

income = get_money("What is your monthly income: $ ")

expenses = ["rent", "utilities", "groceries", "transportation"]

amounts = {}

for item in expenses:
    amounts[item] = get_money(f"What is your monthly {item}: $ ")

savings_percent = get_money("What percentage of your income would you like to save? ")

savings = round(income * (savings_percent / 100), 2)

for item in expenses:
    print_category(item, income, amounts[item])

print_category("savings", income, savings)

total_expenses = sum(amounts.values()) + savings

spending = round(income - total_expenses, 2)

print(f"You have ${spending: .2f} of spending money each month")