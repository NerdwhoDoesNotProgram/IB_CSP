// IB 7th Financial Calculator
#include <stdio.h>
#include <math.h>

int main(){

    float income = printf("What is your monthly income: $\n");
    scanf("%f", &income);

    float rent = printf("What is your monthly rent/mortgage: $\n");
    scanf("%f", &rent);

    float utilities = printf("What is your monthly utilities: $\n");
    scanf("%f", &utilities);

    float transportation = printf("What is your monthly transportation: $\n");
    scanf("%f", &transportation);

    float groceries = printf("What is your monthly groceries: $\n");
    scanf("%f", &groceries);


     printf("Your rent is $ %.2f, and that is %.2f percent of your income\n", rent, (rent/income)*100);

     printf("Your utilities is $ %.2f, and that is %.2f percent of your income\n", utilities, (utilities/income)*100);
     
     printf("Your groceries is $ %.2f, and that is %.2f percent of your income\n", groceries, (groceries/income)*100);

     printf("Your Transportation is $ %.2f, and that is %.2f percent of your income\n", transportation, (transportation/income)*100);

     printf("You should save %.2f$ a month\n", income);
    // float rent = printf("What is your monthly rent/mortgageP: $");




  


    return 0;
}