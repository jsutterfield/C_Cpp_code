#include <stdio.h>
#define MAX_STRING 1000

void escape(char s[],char t[]);
void unescape(char s[], char t[]);

main()
{
    char t[] = "This is \\n the start \\t of something \\\" cool";
    char s[MAX_STRING];
    
    unescape(s, t);
    printf("%s\n", s);

    return 0;
}

/* escape: converts characters like newline and tab into visible escape 
 * sequences as it copies string t to s */
void escape(char s[],char t[])
{
    int i, j;

    for (i=j=0; t[i]!='\0'; i++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\a':
                s[j++] = '\\';
                s[j++] = 'a';
                break;
            case '\b':
                s[j++] = '\\';
                s[j++] = 'b';
                break;
            case '\f':
                s[j++] = '\\';
                s[j++] = 'f';
                break;
            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
                break;
            case '\'':
                s[j++] = '\\';
                s[j++] = '\'';
                break;
            case '"':
                s[j++] = '\\';
                s[j++] = '"';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

/* unescape: converts escaped characters into real characters while copying
 * string t to string s */
void unescape(char s[], char t[])
{
    int i, j;

    for (i=j=0; t[i]!='\0'; i++) {
        switch (t[i]) {
            case '\\': {
                switch (t[++i]) {
                    case 'n':
                        s[j++] = '\n';
                        i++;
                        break;
                    case 't':
                        s[j++] = '\t';
                        i++;
                        break;
                    case 'a':
                        s[j++] = '\a';
                        i++;
                        break;
                    case '"':
                        s[j++] = '\"';
                        i++;
                        break;
                    case '\\':
                        s[j++] = '\\';
                        i++;
                        break;
                    default:
                        s[j++] = t[i];
                        break;
                }
            }
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = t[i];
}
