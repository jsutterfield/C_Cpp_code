#include <stdio.h>
#define MAXLINE 1000

int getlines(char in_line[], int limit);

main()
{
    char in_line[MAXLINE];
    int len;

    while ((len = getlines(in_line, MAXLINE)) > 0)
        printf("%s", in_line);

    return 0;
}

int getlines(char in_line[], int limit)
{
    int c, i;
   
    i = 0;
    while (i<limit-1) {
        c = getchar();
        if (c == '\n')
            break;
        else if (c == EOF)
            break;

        in_line[i] = c;
        ++i;
    }
    if (c == '\n') {
        in_line[i] = c;
        ++i;
    }
    in_line[i] = '\0';

    return i;
}
