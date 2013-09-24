#include <stdio.h>
#define LINE_MAX 1000 /* maximum input line size */

int getlines(char line[], int limit);
void strip(char line[]);

main()
{
    char line[LINE_MAX];
    int len;

    while ((len = getlines(line, LINE_MAX)) > 0) {
        strip(line);
        if (line[0] != '\n')
            printf("%s", line);
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

/* strip: remove trailing blanks and tabs from lines */
void strip(char line[])
{
    int end_word, i;

    end_word = -1;
    for (i=0; line[i]!='\n'; ++i) 
        if ((line[i] == ' ' || line[i] == '\t') && end_word == -1) 
            end_word = i;
        else if (line[i] != ' ' && line[i] != '\t') 
            end_word = -1;

    if (end_word != -1) {
        line[end_word] = 'X';
        line[++end_word] = '\n';
        line[++end_word] = '\0';
    }
}
