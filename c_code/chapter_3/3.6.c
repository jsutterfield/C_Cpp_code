#include <stdio.h>
#include <string.h>
#include <limits.h>
#define STRING_LIM 1000

void itoa(int n, char s[], int w);
void reverse(char s[]);

main()
{
    int x = 123;
    char s[STRING_LIM];
    itoa(x, s, 2);

    printf("'%s'\n", s);
}

/* itoa: convert n to characters in s padded in field w */
void itoa(int n, char s[], int w)
{
    int i, sign, lowest_neg;

    lowest_neg = 0;
    if (n == INT_MIN) // check if largest negative number
        lowest_neg = n++;
    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */
    i = 0;
    do {        /* generage digits in reverse order */
        s[i++] = n % 10 + '0';      /* get next digit */
    } while ((n /= 10) > 0);        /* delete it */
    if (sign < 0)
        s[i++] = '-';
    if (lowest_neg)
        s[0]++; 
    s[i] = '\0';
    reverse(s);

    int dif;
    if ((dif = w - i) > 0) {    /* len of s is < width w */
        for(; i >= 0; --i)
            s[i + dif] = s[i];     /* shift s to the right of width w */
        for (++i; i < dif; ++i)
            s[i] = ' ';         /* pad w/ spaces on the left */
    }
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
