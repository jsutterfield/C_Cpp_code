#include <stdio.h>
#include <stdlib.h>
#define LINE_MAX 1000

int getlines(char line[], int limit);
void entab(char in_line[], char out_line[], int tabStop);

int main(int argc, char *argv[])
{
    char in_line[LINE_MAX];
    char out_line[LINE_MAX];
    int len, tabStop;

    if ( argc != 2 ) {
        printf("ERROR: Usage ./a.out <tabsize>\n");
        exit(1);
    }

    tabStop = atoi( argv[1] );

    while ((len = getlines(in_line, LINE_MAX)) > 0) {
        entab(in_line, out_line, tabStop); 
        printf("%s", out_line);
    }

    return 0;
}       

/* getline: read a line into s */
int getlines(char s[], int limit)
{
    int c, i;

    for (i=0; i<limit-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i - 1;
}

/* entab: replace spaces with tabs when possible */
void entab(char in_line[], char out_line[], int tabStop)
{
    int i, j, spaces;

    for (i = j = spaces = 0; in_line[i] != '\0'; i++, j++) {
        out_line[j] = in_line[i];
        if (in_line[i] == ' ') {
            spaces++;
            if ( spaces % tabStop == 0 ) {
                j -= tabStop - 1;
                out_line[j] = '\t';
            }
        } else {
            spaces = 0;
        }
    }
    
    out_line[j] = in_line[i]; /* add the null character */
}
