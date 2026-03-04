#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Example 1
    for(int i = 20; i > 0; i--){
        printf("%d ", i);
    }
    printf("\n"); // makes a new line

    // Example 2
    char names[][20] = {"Alex", "Katie", "Andrew", "Vienna", "Tia", "Treyson", "Xavier", "Jake"};
    int names_len = sizeof(names)/ sizeof(names[0]);
    for(int x = 0; x < names_len; x++){
        printf("%s LaRose\n", names[x]);
    }

    // Example 3
    srand(time(NULL));

    int number = rand() % 10 +1;
    int count = 0;

    for(count; count < number; count++){
        printf("duck\n");
    }
    printf("GOOSE!\n");

    return 0;
}