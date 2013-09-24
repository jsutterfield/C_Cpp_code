#include <stdio.h>
#define TABSTOP 4
#define LINE_MAX 1000

int getlines(char line[], int limit);
void detab(char in_line[], char out_line[]);

main()
{
    char in_line[LINE_MAX];
    char out_line[LINE_MAX];
    int len;

    while ((len = getlines(in_line, LINE_MAX)) > 0) {
        detab(in_line, out_line); 
        printf("%s", out_line);
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

/* detab: replace tab with TABSTOP spaces */
void detab(char in_line[], char out_line[])
{
   int i, j, k;

   for (i=j=0; in_line[i]!='\0'; ++i, ++j)
       if (in_line[i] == '\t') { 
           for (k=0; k<TABSTOP; ++k, ++j)
               out_line[j] = ' ';
           --j; /* out_lines's index is 1 too high */
       }
       else
           out_line[j] = in_line[i];
    out_line[j] = in_line[i]; /* add the null character */
}
