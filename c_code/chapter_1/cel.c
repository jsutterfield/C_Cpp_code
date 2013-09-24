#include <stdio.h>

/* print Celsius-Farenheit table
     for cel = 0, 20, ..., 300 */
main(){
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;
    printf("\n");
    printf(" C       Fahr\n");
    printf(" -------------\n");
    while (celsius <= upper) {
        fahr = celsius * (9.0/5.0) + 32;
        printf("|%3.0f\t%6.1f|\n", celsius, fahr);
        celsius = celsius + step;
    }
    printf(" -------------\n");
}    
