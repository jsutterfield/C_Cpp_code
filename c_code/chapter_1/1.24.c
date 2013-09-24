#include <stdio.h>
#define LINE_MAX 1000

int getlines(char line[], int limit);
void remove_comments(char in_line[]);
void syntax_check(char in_line[]);
void pop_items(char in_line[], int first, int second);

main()
{
    char in_line[LINE_MAX];
    int len, count;

    count = 0;
    while ((len = getlines(in_line, LINE_MAX)) > 0) {
        remove_comments(in_line); 
        syntax_check(in_line);
        printf("Line count: %d -- ", count);
        ++count;
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
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* Remove all comments and quoted strings */
void remove_comments(char in_line[])
{
    int in_comments, i, in_quotes, j;
    int previous, current, next;
    char temp_line[LINE_MAX];

    j = in_quotes = in_comments = 0;
    for (i=0; in_line[i]!='\0';  ++i) {
        previous = in_line[i-1];
        current = in_line[i];
        next = in_line[i+1];

        // If '//' comments are used, remainder of line is commented out
        if (current == '/' && next == '/' && previous !='\\')
            break;

        /* See if currently inside quotes */ 
        if (in_quotes == 0) {
            if (in_comments == 0 && (current == '"' || current == '\'') 
                                 && previous != '\\') {
                in_quotes = 1;
                temp_line[j] = current;
                ++j;
                continue;
            }
        }
        else if ((current == '"' || current == '\'') && previous != '\\')
            in_quotes = 0;
        else
            // uncomment the 2 lines below to include quoted strings
            /* temp_line[j] = current;
             ++j; */
            continue;
        
        /* See if currently inside comments */
        if (in_comments == 0) {
            if (current == '/' && next == '*' && previous != '\\')
               in_comments = 1;
        }
        else if (current = '*' && next == '/') {
           ++i;
           in_comments = 0;
           continue;
        }

        if (in_comments == 0) {
            temp_line[j] = current;
            ++j;
        }
    }

    temp_line[j] = '\0';
  
    // Write temp_line to new_line
    for (i=0; i<=j; ++i)
        in_line[i] = temp_line[i];
}

void syntax_check(char in_line[])
{
    char temp_line[LINE_MAX];
    int i, j, errors_found;

    // Collect all the characters to be matched for syntax
    for (i=j=0; in_line[i]!='\0'; ++i) {
        if (in_line[i] == '(' || in_line[i] == ')' || in_line[i] == '{' \
            || in_line[i] == '}' || in_line[i] == '[' || in_line[i] == ']' \
            || in_line[i] == '\'' || in_line[i] == '"') {

            temp_line[j] = in_line[i];
            ++j;
        }
    }
    temp_line[j] = '\0';

    // Check for mismatched sytnax characters
    errors_found = i = 0;
    while (temp_line[i] != '\0') {
        for(j=1; temp_line[j]!='\0'; ++j) {
            if (temp_line[i] == '(' && temp_line[j] == ')')
                break;
            else if (temp_line[i] == '{' && temp_line[j] == '}')
                break;
            else if (temp_line[i] == '[' && temp_line[j] == ']')
                break;
            else if (temp_line[i] == '"' && temp_line[j] == '"')
                break;
            else if (temp_line[i] == '\'' && temp_line[j] == '\'')
                break;
        }
        // A match was not found
        if (temp_line[j] == '\0') {
            printf("SYTNAX ERROR: Mismatched %c\n", temp_line[i]);
            pop_items(temp_line, i, 0);
            errors_found = 1;
            continue;
        }
        pop_items(temp_line, i, j);
    }

    if (errors_found == 0) {
        printf("No syntax errors found\n");
    }
}

void pop_items(char in_line[], int first, int second)
{
    int i, j;

    for (i=j=0; in_line[i]!='\0'; ++i, ++j) {
        if (i == first || i == second) {
            --j;
            continue;
        }
        in_line[j] = in_line[i];
    }

    in_line[j] = in_line[i]; // Write the null character
}

