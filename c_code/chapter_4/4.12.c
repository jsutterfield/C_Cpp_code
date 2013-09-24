/* Recursive versions of itoa */
#include<stdio.h>

void itoa(char s[], int n);

main()
{
   char s[100];

    itoa(s, -123);
    printf("%s\n", s); 
}

/* printd: print n in decimal */
void itoa(char s[], int n)
{
    static int i = 0;
    static int neg = 0;

    if (n < 0) {
        neg = 1;
        n = -n;
    }
    if (n / 10)
        itoa(s, n / 10);
    else if (neg)
        s[i++] = '-';
    s[i++] = (n % 10 + '0');
    s[i] = '\0';
}

/* printd: print n in decimal */
int itoa2(char s[], int n)
{
    int i = 0;
    static int neg = 0;

    if (n < 0) {
        neg = 1;
        n = -n;
    }

    if (n / 10) {
        i = itoa2(s, n / 10);
        s[i] = (n % 10 + '0');
        s[i+1] = '\0';
    }
    else {
        if (neg)
            s[i++] = '-';
        s[i] = (n % 10 + '0');

    }

    return ++i;
}

abstration, wall, scope, it doesn't get stuck there anymore! It is QUITE remarkable!
datas in frames. That's the way to go about it. You fooled around with the values
in there. Holy shit...that is finally starting to make sense...That is amazing!

change them mysteriously.

But, every now and again. If you hope very, very hard. Then something veyr very 
cool happens. Ie, if you want to learn how to code, than you fucking cow!
