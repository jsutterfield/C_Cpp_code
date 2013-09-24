#include<stdio.h>
#define ARRAY_SIZE 1000

void strcat2(char *s, char *t);

main()
{
    char s[ARRAY_SIZE] = "hello";
    char t[ARRAY_SIZE] = " there";
    strcat2(s, t);
    printf("%s\n", s);
}

void strcat2(char *s, char *t)
{
    int n = 0;
    while(*s++) /* move pointer to end of s */
        ;
    s--;
    while(*s++ = *t++) /* copy t to end of s */
        ;
}

