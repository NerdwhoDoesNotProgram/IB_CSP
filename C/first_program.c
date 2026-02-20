// IB 7th First Program - C
#include <stdio.h>

int main(){
    
    char name[50];

    printf("Please enter your name:");
    scanf("%s", name);

    printf("Hello, %s! Welcome to your first C program.", name);

    return 0;
}