// IB 7th Time of Day - C
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//int main(){
 //   time_t now = time(NULL);
 //   struct tm *t = localtime(&now);
 //   char buffer[100];

 //   strftime(buffer, sizeof(buffer), "%H:%M:%S", t);
  //  printf("Formatted time: %s\n", buffer);

  //  return 0;
//}
int time_input;
int time_now;
int current_hour_military;


int time_of_day(){
    time_t current_raw_time;
    struct tm *day_time_info;

    // 1. Get the current time as a time_t value (seconds since Unix epoch)
    current_raw_time = time(NULL);
    if (current_raw_time == (time_t)-1) {
        fprintf(stderr, "Failure to obtain the current time.\n");
        return EXIT_FAILURE;
    }

    // 2. Convert the time_t value to local time and store in a struct tm
    day_time_info = localtime(&current_raw_time);

    // 3. Extract the hour (in 24-hour format) into your integer variable
    // The tm_hour member stores hours since midnight in the range [0, 23].
    current_hour_military = day_time_info->tm_hour;

    // 4. Use the variable (optional: print to verify)
    printf("The current hour in military time is: %d\n", current_hour_military);
    // You can also use strftime to format the time into a string, if needed.

    return EXIT_SUCCESS;
}

int unknown_time(){
    time_now = 
    printf("Good thing that I know...");
    if(time_now)
    return 0;
}

int known_time(){
    if (time_input < 12){
     printf("Good Morning!");

    }else if (time_input >= 12 && time_input < 18){
     printf("Good Afternoon!");
    }else if (time_input < 0 || time_input > 24){
        printf("That is not a time.");

    }else{
     printf("Good Evening!");

    return 0;
    }
}

int main(){
    char do_you_know = printf("Do you know what time it is (Yes/No): ");
    scanf("%s", do_you_know);

    if (do_you_know == "Yes"){
        int what_time = printf("What is the hour in military time: ");
        scanf("%d", what_time);
        time_now = what_time;
    } else{
        printf("Good thing I know...");
    }
    return 0;
}