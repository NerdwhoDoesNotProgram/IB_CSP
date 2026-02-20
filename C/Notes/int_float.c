// IB Integets and Floats Notes - C
#include <stdio.h>
#include <math.h>

int main(){
    int people = 22;
    int apples = 25;
    int room = 200;

    printf("people: %d\nApples: %d\nRoom: %d\n", people, apples, room);
    printf("Each person gets %f apple(s)\n", (float) apples/people);

    float liters = 2.7;
    float farenheit = 72.82;
    const float pi = 3.14159265;
    float celsius = (farenheit-32) * 5/9;

    printf("Liters: %.2f\nFarenheit: %.1f\npi: %.5f\n", liters, farenheit, pi);
    printf("Celsius is: %.2f\n", round(celsius)); // rounds to whole number
    printf("%f\n",  (int) pow(2,3));
    sqrt(10); // Saves as variable or print, just don't leave it

    return 0;
}