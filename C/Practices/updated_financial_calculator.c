// IB 7th Update Financial Calculator
#include <stdio.h>

/*
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
    int percent_to_save = ("What percentage of your income would you like to save? ");

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
    if(spending_money > 0){
       printf("You have $%.2f of spending money each month!\n", spending_money);
    }else{
       printf("You are $%.2f in debt each month!\n", spending_money*-1);
    }

    return 0;
} */

// Verision 2
/*
// get money input
float get_money(char prompt[]) {
    float value;
    printf("%s", prompt);
    scanf("%f", &value);
    return value;
}

// calculate percent of income
float get_percent(float income, float expense) {
    return (expense / income) * 100;
}

// print category info
void print_category(char name[], float income, float amount) {
    float percent = get_percent(income, amount);
    printf("Your %s is $%.2f and that is %.0f%% of your income.\n",
           name, amount, percent);
}

int main() {

    float income = get_money("What is your monthly income: $ ");

    char *expenses[] = {"rent", "utilities", "groceries", "transportation"};
    float amounts[4];

    // get expense inputs
    for(int i = 0; i < 4; i++) {
        char prompt[100];
        printf("What is your monthly %s: $ ", expenses[i]);
        scanf("%f", &amounts[i]);
    }

    float savings_percent = get_money("What percentage of your income would you like to save? ");

    float savings = income * (savings_percent / 100);

    // print expense info
    for(int i = 0; i < 4; i++) {
        print_category(expenses[i], income, amounts[i]);
    }

    print_category("savings", income, savings);

    // calculate total expenses
    float total_expenses = savings;
    for(int i = 0; i < 4; i++) {
        total_expenses += amounts[i];
    }

    float spending = income - total_expenses;

    if(spending >= 0) {
        printf("You have $%.2f of spending money each month!\n", spending);
    } else {
        printf("You are $%.2f in debt each month!\n", spending * -1);
    }

    return 0;
} */

// Version 3

float get_money(char prompt[]) {
    float value;
    printf("%s", prompt);
    scanf("%f", &value);
    return value;
}

float get_percent(float income, float expense) {
    return (expense / income) * 100;
}

void print_category(char name[], float income, float amount) {
    printf("Your %s is $%.2f and that is %.0f%% of your income.\n",
           name, amount, get_percent(income, amount));
}

int main() {

    float income = get_money("What is your monthly income: $ ");

    char *expenses[] = {"rent", "utilities", "groceries", "transportation"};
    float amounts[4];

    for (int i = 0; i < 4; i++) {
        printf("What is your monthly %s: $ ", expenses[i]);
        scanf("%f", &amounts[i]);
    }

    float savings_percent = get_money("What percentage of your income would you like to save? ");
    float savings = income * (savings_percent / 100);

    float total_expenses = savings;

    for (int i = 0; i < 4; i++) {
        print_category(expenses[i], income, amounts[i]);
        total_expenses += amounts[i];
    }

    print_category("savings", income, savings);

    float spending = income - total_expenses;

    if (spending >= 0)
        printf("You have $%.2f of spending money each month!\n", spending);
    else
        printf("You are $%.2f in debt each month!\n", -spending);

    return 0;
}