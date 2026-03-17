#include <stdio.h>
// Example 1
int sqr(int num){
    return num * num;
}

// Example 2 (no parameters AND no return)
int count = 0;
void add(){
    count++;
}

// Example 3 (string parameter)
void hello(char* name){
    printf("Hello %s! Welcome to my program!\n", name);
}


int main(){
    // Example 1 continured
    int number = sqr(12);
    printf("%d\n", number);
    printf("%d\n", sqr(8));

    // Example 2 continued
    printf("%d\n", count);
    add();
    add();
    add();
    add();
    add();
    add();
    add();
    add();
    printf("%d\n", count);

    // Example 3 continued
    hello("Alex");
    hello("Katie");
    hello("Andrew");
    hello("Tia");
    hello("Treyson");
    hello("Xavier");
    hello("Jake");

    return 0;
}


