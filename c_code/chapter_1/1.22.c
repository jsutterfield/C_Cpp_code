#include <stdio.h>
#define FOLD_LIMIT 20
#define LINE_MAX 1000

int getlines(char line[], int limit);
void fold_line(char in_line[]);

main()
{
    char in_line[] = "Hello there this is a very long line which will be split upon limits of 10 because that is what we're going for\n";
    int len;

    //while ((len = getlines(in_line, LINE_MAX)) > 0) {
    //    fold_line(in_line); 
    //}
    fold_line(in_line);

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

/* fold_line: adds newlines to input line at the last possible space char before
 * given limit */
void fold_line(char in_line[])
{
    int i, j, line_length;

    // Get length of the line;
    for (line_length=0; in_line[line_length]!='\0'; ++line_length)
        ;

    i = FOLD_LIMIT - 1;
    while (line_length > FOLD_LIMIT - 1) {
        if (in_line[i] == ' ' || in_line[i] == '\t') {
            in_line[i] = '\n';
            for (j=0; j<= i; ++j) // print line up to space
                putchar(in_line[j]); 
            line_length -= i + 1;
            for (j=0, ++i; in_line[i]!='\0'; ++j, ++i) // remove that part of lien
                in_line[j] = in_line[i];
            in_line[j] = in_line[i]; // add null character
            i = FOLD_LIMIT - 1;
            continue;
        }
        // no space was found
        else if (i == 0) {
            for (j=0, i=FOLD_LIMIT - 1; j<= i; ++j) // print line up to space
                putchar(in_line[j]); 
            putchar('\n');
            line_length -= FOLD_LIMIT;
            for (j=0, ++i; in_line[i]!='\0'; ++j, ++i) // remove that part of lien
                in_line[j] = in_line[i];
            in_line[j] = in_line[i]; // add null character
            i = FOLD_LIMIT - 1;
            continue;
        }
        --i;
    }
    for (j=0; in_line[j]!='\0'; ++j) // print the remaining line
        putchar(in_line[j]);
    putchar(in_line[j]);
}
