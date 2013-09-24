#include <stdio.h>
#define LINE_MAX 1000 /* maximum input line size */

int getlines(char line[], int limit);
void reverse(char line[]);

main()
{
    char line[LINE_MAX];
    int len;

    while ((len = getlines(line, LINE_MAX)) > 0) {
        reverse(line);
        printf("%s\n", line);
    }
}       

/* getline: read a line into s */
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

void reverse(char s[])
{
    int lower, upper, holder, i;

    /* Find index of last char in string */
    for (i=0; s[i]!='\0'; ++i) 
        ;

    upper = i-1;
    for (lower=0; upper-lower>0; --upper, ++lower) {
        holder = s[upper];
        s[upper] = s[lower];
        s[lower] = holder;
    }
}
