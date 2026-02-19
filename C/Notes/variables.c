// This is a comment in C!
#include <stdio.h> // Lets us use inputs and outputs

int main(){
    //Variables examples
    int age = 9999;
    float gpa = 3.98;
    char grade = 'A';   // Single letter uses single quotes
    const char name[] = "Eric";
    int number;
    char user[50];

    gpa = 4.0;

    printf("Tell me your name\n");
    scanf("%s", &user); // Can not take in more than one word

    printf("What is your favorite number\n");
    scanf("%d", &number);

    printf("%s's favorite number is: %d\n", user, number);
    printf("It worked!\n");
    printf("%d\n", age);
    printf("Your GPA is: %f\n", gpa);
    printf("you have an %c incomputer science\n", grade);
    return 0; //required last line in your main function
}