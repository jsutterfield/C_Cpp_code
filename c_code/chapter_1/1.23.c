#include <stdio.h>
#define LINE_MAX 1000

int getlines(char line[], int limit);
void remove_comments(char in_line[]);

main()
{
    //char in_line[LINE_MAX];
    int len;

    //while ((len = getlines(in_line, LINE_MAX)) > 0) {
    //    remove_comments(in_line); 
    //}
    char in_line[] = "This should show \"/* this shouldn't */ and this should as well\n";

    remove_comments(in_line);
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

/* Remove all comments */
void remove_comments(char in_line[])
{
    int in_comments, previous, current, i, in_quotes;

    previous = current = in_quotes = in_comments = 0;
    for (i=0; in_line[i]!='\0';  ++i) {
        previous = current;
        current = in_line[i];

        /* See if currently inside quotes */
        if (in_quotes == 0) {
            if (in_comments == 0 && current == '"' && previous != '\\') {
                in_quotes = 1;
                putchar(previous);
                continue;
            }
        }
        else if (current == '"' && previous != '\\')
            in_quotes = 0;
        else {
            putchar(previous);
            continue;
        }
        
        /* See if currently inside comments */
        if (in_comments == 0) {
            if (current == '*' && previous == '/')
               in_comments = 1;
        }
        else if (previous == '*' && current == '/') {
            previous = in_line[++i]; 
            current = in_line[++i];
            in_comments = 0;
            if (current == '\0') {
                putchar(previous);
                break;
            }
        }

        if (in_comments == 0)
            putchar(previous);
    }
    putchar(current);
}
