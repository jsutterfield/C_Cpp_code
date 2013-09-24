#include<stdio.h>
#define ARRAY_SIZE 1000

void strncpy2(char *s, char *t, int n);
void strncat2(char *s, char *t, int n);
int strncmp2(char *s, char *t, int n);

main()
{
    char s[ARRAY_SIZE] = "Myaname is ";
    char t[ARRAY_SIZE] = "Myz name are ";
    printf("%d\n", strncmp2(s, t, 2));
}

/* strncpy2: copies up to n characters of string s to string t */
void strncpy2(char *s, char *t, int n)
{
    int i;
    for (i = 0; (*t = *s) && i < n-1; s++, t++, i++)
        ;
    (*++t) = '\0';
}

/* strncat2: concats up to n chars of t to s */
void strncat2(char *s, char *t, int n)
{
    int i = 0;
    while(*s++) /* move pointer to end of s */
        ;
    s--;
    while((i++ < n) && (*s++ = *t++)) /* copy t to end of s */
        ;
    *++s = '\0';
}

/* strncmp2: return <0 if s<t, 0 if s==t, >0 if s>t up to n chars of t */
int strncmp2(char *s, char *t, int n)
{
    printf("n is now %d\n", n);
    for (;(n > 1) && (*s == *t); s++, t++, n--) {
        printf("inside for loop\n");
        printf("n is now %d, *s is %c and *t is %c\n", n, *s, *t);
        if (*s == '\0')
            return 0;
    }

        printf("FINALLY n is now %d, *s is %c and *t is %c\n", n, *s, *t);
        return *s - *t;
}

