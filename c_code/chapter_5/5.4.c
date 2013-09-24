#include<stdio.h>
#define ARRAY_SIZE 1000

int strend(char *s, char *t);

main()
{
    char s[ARRAY_SIZE] = "My name is harry hello there";
    char t[ARRAY_SIZE] = "x hello there";
    printf("%d\n", strend(s, t));
}

int strend(char *s, char *t)
{
    char *ot = t;
    while(*s++) /* find end of s */
        ;
    while(*t++) /* find end of t */
        ;
    s--;
    t--;
    while(*t-- == *s-- && *t >= 0)
        ;
    t+=2;
    return (t == ot) ? 1 : 0;
}
