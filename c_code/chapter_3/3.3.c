#include <stdio.h>
#define STRING_MAX 1000

void expand(char s1[], char s2[]);

main()
{
    char s1[] = "-a-b-c-d-";
    char s2[STRING_MAX];
    
    expand(s1, s2);
    printf("%s\n", s2);
    
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, k, trailing;
    i = j = trailing = 0;

    for (k=0; s1[k]!='\0'; k++) // get length of string
        ;

    if (s1[--k] == '-') { // Make note if last char is a trailing '-'
        trailing = 1;     // and remove it
        s1[k] = '\0';
    }

    if (s1[0] == '-') 
        s2[j++] = s1[i++]; // Copy over leading '-' if present

    while (s1[i] != '\0') {

        for(k = s1[i]; k <= s1[i+2]; ++k)
            s2[j++] = k;

        if (s1[i + 3] == '-') { // Check if next part of string has format
            --j;                // a-b-c
            i += 2;
        } else                  // Otherwise, assume it's a-bA-z 
            i += 3;
    }

    if (trailing)
        s2[j++] = '-';

    s2[j] = s1[i];
}
