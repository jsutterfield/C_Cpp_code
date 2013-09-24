#include <stdio.h>
#define TABSTOP 4
#define LINE_MAX 1000

int getlines(char line[], int limit);
void entab(char in_line[], char out_line[]);

main()
{
    char in_line[LINE_MAX];
    char out_line[LINE_MAX];
    int len;

    while ((len = getlines(in_line, LINE_MAX)) > 0) {
        entab(in_line, out_line); 
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

/* entab: replace spaces with tabs when possible */
void entab(char in_line[], char out_line[])
{
   int i, j;
   int start_space, next_space;
   int subbed_char;

   start_space = -1; /* initialize to dummy values */
   next_space = 0;
   for (i=j=0; in_line[i]!='\0'; ++i, ++j) {
       subbed_char = 0;
       if (in_line[i] == ' ' && start_space == -1) 
               start_space = i;
       else if (in_line[i] == ' ') {
           next_space = i;
           if (next_space - start_space == TABSTOP - 1) {
               j = start_space;
               out_line[j] = '\t';
               start_space = -1;
               subbed_char = 1;
            }
       }
       else {
           start_space = -1;
           next_space = 0;
       }

       if (subbed_char != 1) /* outline already filled with \t char */
           out_line[j] = in_line[i];
    }

    out_line[j] = in_line[i]; /* add the null character */
}
