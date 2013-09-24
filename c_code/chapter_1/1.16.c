#include <stdio.h>
#define MAXLINE 10 /* maximum input line size */

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
    int len;            /* current line length */
    int max;            /* current length seen so far */
    char line[MAXLINE]; /* current line saved here */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = getlines(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)    /* there was a line */
        printf("Length of longest line: %d\n", max);
        printf("Snippet of longest line: %s\n", longest);
    return 0;
}

/* getline: read a line into s, return length */
int getlines(char s[], int limit)
{
    int c, i;

    for (i=0; i<limit-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    if (i == limit - 1)
        for (i; (c=getchar())!=EOF && c!='\n'; i++)
            ;
    return i;
}

/* copy: copy 'from' into 'to': assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
            ++i;
}
