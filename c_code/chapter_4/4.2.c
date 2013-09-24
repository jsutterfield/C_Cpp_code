#include <ctype.h>
#include<stdio.h>

int pows(int base, int exp);
double atof(char s[]);

main()
{
    printf("%f\n", atof("123.45e-6"));
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, sign2, epow;
    for (i = 0; isspace(s[i]); i++) /*skip white space*/
        ;
    sign = (s[i] == '-' ) ? -1 : 1 ;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val= 0.0; isdigit(s[i]); i++)
        val= 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power= 1.0; isdigit(s[i]); i++) {
        val= 10.0 * val+ (s[i] - '0');
        power *= 10.0;
    }
    if (!s[i] == 'e' && !s[i] == 'E')
        return sign * val / power;
    ++i;
    sign2 = 0;
    if (s[i] == '-') {
        sign2 = 1;
        ++i;
    }
    for (epow = 0.0; isdigit(s[i]); i++)
        epow = 10.0 * epow + (s[i] - '0');
    if (sign2)
        return sign * val / power / pows(10, epow);
    return sign * val / power * pows(10, epow);
}

int pows(int base, int exp)
{
    int i;
    i = 1;
    while (exp > 0) {
        i *= base;
        exp--;
    }
}

