#include <stdio.h>

/* print Farenheit-Celsius table
     for fahr = 0, 20, ..., 300 */
main(){

    float convert_to_cel(int fahr);
    
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    printf("\n");
    printf(" Fahr       C\n");
    printf(" -------------\n");
    while (fahr <= upper) {
        printf("|%3.0f\t%6.1f|\n", fahr, convert_to_cel(fahr));
        fahr = fahr + step;
    }
    printf(" -------------\n");
}

/* Convert Farenheit to Celsius */
float convert_to_cel(int fahr)
{
    float celsius;
    celsius = (5.0/9.0) * (fahr-32.0);
    return celsius;
}
