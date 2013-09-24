#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
    char s1[] = "Hrllo dsdfhere";
    char s2[] = "xxx";
    printf("%d\n", any(s1, s2)); 
}

/* any: Return the first location in s1 where any character from s2 occurs.
 * -1 otherwise */
int any(char s1[], char s2[])
{
    int i, j, not_found;

    not_found = -1;
    for (i=0; s1[i] != '\0'; i++) 
        for (j=0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;

    return not_found;
}
