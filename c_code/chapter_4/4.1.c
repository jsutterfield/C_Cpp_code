#include <stdio.h>
#include <string.h>
#define MAXLINE 1000    /* maximum input line length */

int getlines(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "and"; /* pattern to search for */

/* find all lines matching pattern */
main()
{
    char line[MAXLINE];
    int found = 0;
    while (getlines(line, MAXLINE) > 0)
        if (strrindex(line, pattern) >= 0) {
            printf( "%s", line);
            found++;
        }
    return found;
}

/* getlines: get line into s, return length */
int getlines(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim> 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strrindex: return position of rightmost occurence of t in s */
int strrindex(char s[], char t[])
{
    int i, j, k;
    for (i = strlen(s) - 1; i >= 0 && i > strlen(t); i--) {
        for (j=i, k=strlen(t) - 1; k >= 0 && s[j]==t[k]; j--, k--)
            ;
        if (k < 0)
            return i - (strlen(t) - 1);
    }
    return -1;
}
