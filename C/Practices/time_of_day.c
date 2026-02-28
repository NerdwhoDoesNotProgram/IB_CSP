// IB 7th - Time of Day
#include <stdio.h>
#include <time.h>

int main() {

    char answer;
    int hour;

    printf("Do you know what time it is? (Y/N): ");
    scanf(" %c", &answer);

    if (answer == 'Y' || answer == 'y' || answer == 'yes' || answer == 'YES' || answer == 'Yes') {

        printf("What is the hour in military time (0-23): ");
        scanf("%d", &hour);

    } 
    else {

        printf("Good thing I know...\n");

        time_t now = time(NULL);
        struct tm *local = localtime(&now);

        hour = local->tm_hour;

        printf("The current hour is: %d\n", hour);
    }

    if (hour < 0 || hour > 23) {
        printf("That is not a valid time.\n");
    }
    else if (hour < 12) {
        printf("Good Morning!\n");
    }
    else if (hour < 18) {
        printf("Good Afternoon!\n");
    }
    else {
        printf("Good Evening!\n");
    }

    return 0;
}