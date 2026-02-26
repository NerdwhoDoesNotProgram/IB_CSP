// IB Conditionals 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int grade = 99;
    bool isprogramming = true;

    if (grade >= 90){
        if (grade > 93){
            printf("Your grade is %d percent. That is an A!\n", grade);
        }else{
            printf("Your grade is %d percent. That is an A-\n", grade);
        }
    }else if (grade >= 80){
        printf("Your grade is %d percent. That is an B.\n", grade);
    }else if (grade >= 70){
        printf("Your grade is %d percent. That is an C.\n", grade);
    }else if (grade >= 60){
        printf("Your grade is %d percent. That is an D.\n", grade);
    }else{
        printf("Your grade is %d percent. That is an F.\n", grade);
    }

    int num = -483;

    if (num < 10 && num > -10){
        printf("%d is a single digit number\n", num);
    }else if (num < 100 && num > -100){
        printf("%d is a double digit number\n", num);
    }else if (num < 1000 && num > -1000){
        printf("%d is a triple digit number\n", num);
    }else if (num < 10000 && num > -10000){
        printf("%d is a quadruple digit number\n", num);
    }else{
        printf("%d is a large number\n", num);
    }

    char name[] = "Treyson";

    if (strcmp(name, "Treyson") == 0){
        printf("Welcome Admin\n");
    }else{
        printf("Welcome %s\n", name);
    }

    return 0;
}