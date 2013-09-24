#include <stdio.h>
#define PRINT_MIN 10 /* minimum length to print line */
#define LINE_MAX 15 /* maximum input line size */

int getlines(char line[], int limit);

/* print lines greater than 80 chars */
main()
{
    int len;            /* current line length */
    char line[LINE_MAX]; /* current line saved */

    while ((len = getlines(line, LINE_MAX)) > 0)
        if (len > PRINT_MIN) 
           printf("%s", line);

    return 0;
}

/* getline: read a line into s, return length */
int getlines(char s[], int limit)
{
    int c, i;

    for (i=0; i<limit-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
