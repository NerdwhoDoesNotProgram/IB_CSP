#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(){
    // Example 1
    int i = 1;
    while(i <= 10){
        printf( "%d, ", i);
        i++; // increases variable i by 1
    }

    // Set a random number
    srand(time(NULL));

    printf("\nRandom numnber: %d\n", rand() % 11); //random m=number between 0 and 10
    printf("Random numnber: %d\n", (rand() %10) +1);
    printf("Random numnber: %d\n", (rand() %5)+5);

    // Example 2
    int goose = (rand() % 20) +1;
    int count = 1;
    while (count < goose){
        printf("duck\n");
        count++;
    }
    printf("GOOSE!");

    // Example 3
    int number = (rand() % 30) +1;

        while (true){
            int guess;
            printf("Guess a number between 1 and 30: ");
            scanf("%d", &guess);

            if(guess == number){
                printf("YOU WON! The number was %d.\n", number);
                break;
            }else if (guess < number){
                printf("Guess higher. ");
            }else{
                printf("Guess lower. ");
            }

        }


    return 0;
}