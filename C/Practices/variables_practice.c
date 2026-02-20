// IB 7th, Variables Practice - C
#include <stdio.h>

int main(){
    char name[] = "John Doe";

    int number = 7;

    float gpa = 4.0;

    char breakfast[] = "Oatmeal with berries";

    char color[] = "Blue";

    char school[] = "UCAS";

    int year = 2026;
    
    char eye_color[] = "Blue";

    int age = 15;

    char subject[] = "Geography";

    printf("%s chose the number %d.\nHe is %d years old.\nHe had %s for breakfast before going to %s for the %d year of school.\nHe maintains a %.1f GPA.\nHis favorite subject is %s and his favorite color is %s, which matches his %s eyes.", name, number, age, breakfast, school, year, gpa, subject, color, eye_color);
}