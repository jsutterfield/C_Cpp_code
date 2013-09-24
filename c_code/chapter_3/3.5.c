#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LIM 1000
#define VALUES "0123456789abcdefghijklmnopqrstuvwxyz"

void itob(int n, char s[], int b);
void reverse(char s[]);

main()
{
    char s[STRING_LIM];
    itob(-123456789, s, 29);
    printf("%s\n", s);
    
    return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itob: convert decimal n into base b and write to string s */
void itob(int n, char s[], int b)
{
    if (b > 36){
        printf("itob can only handle up to base 36\n");
        exit(EXIT_FAILURE);
    }

    int i, sign;

    if ((sign=n) < 0)
        n = -n;

    i = 0;
    do {
        s[i++] = VALUES[n % b];
        n /= b;
    } while (n > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}
