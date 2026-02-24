// IB Strings Notes
#include <stdio.h>
#include <string.h>

int main(){
    char subject[] = "Computer Science Prinipals";
    char school[] = "UCAS";
    char book[50];

    printf("What is your favorite book: ");
    // scanf("%s", &book);
    fgets(book, sizeof(book), stdin);

    printf("This is %s taught at %s. It is awesome!\n", subject, school);
    printf("%sThat is a cool book!\n", book);

    // Concatination
    char first[] = "Vienna";
    char last[] = "LaRose";
    char full_name[20];

    first[0] = 'K';
    first[1] = 'a';
    first[2] = 't';
    first[3] = 'i';
    first[4] = 'e';
    first[5] = ' ';
    // Just updating  the variable listed, not creating a new one
    strcat(full_name, first);
    //strcat(full_name, " ");
    strcat(full_name, last);

    printf("%s\n", full_name);

    // length of strings
    printf("%lu\n", strlen(full_name));

    return 0;
}