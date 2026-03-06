// IB 7th Update Financial Calculator
#include <stdio.h>

// Function to get user input
float get_input(char prompt[]) {
    float value;
    printf("%s", prompt);
    scanf("%f", &value);
    return value;
}

// Function to calculate percent of income
float percent_of_income(float income, float expense) {
    return (expense / income) * 100;
}

int main() {

    float income = get_input("What is your monthly income: $");
    float rent = get_input("What is your monthly rent/mortgage: $");
    float utilities = get_input("What is your monthly utilities: $");
    float groceries = get_input("What is your monthly groceries: $");
    float transportation = get_input("What is your monthly transportation: $");

    float savings = income * 0.10;
    float total_expenses = rent + utilities + groceries + transportation;
    float spending_money = income - total_expenses - savings;

    printf("\nYour rent is $%.2f and that is %.0f%% of your income.\n",
           rent, percent_of_income(income, rent));

    printf("Your utilities are $%.2f and that is %.0f%% of your income.\n",
           utilities, percent_of_income(income, utilities));

    printf("Your groceries are $%.2f and that is %.0f%% of your income.\n",
           groceries, percent_of_income(income, groceries));

    printf("Your transportation is $%.2f and that is %.0f%% of your income.\n",
           transportation, percent_of_income(income, transportation));

    printf("You should save $%.2f a month, that is 10%% of your income.\n", savings);
    printf("You have $%.2f of spending money each month!\n", spending_money);

    return 0;
}