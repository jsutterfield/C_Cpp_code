#include <stdio.h>

int lower(int c);

main()
{
    printf("%c\n", lower('B'));
}

/* lower: covert c to lower case; ASCII only */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
