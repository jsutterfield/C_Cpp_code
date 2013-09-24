#include <stdio.h>

void squeeze(char s1[], char s2[]);

main()
{
    char s1[] = "Hello there";
    char s2[] = "thrH";
    squeeze(s1, s2);
    printf("%s\n", s1);
}

/* squeeze: Delete any chars from s1 that are found in s2 */
void squeeze(char s1[], char s2[])
{
    int i;

    for (i=0; s2[i] != '\0'; ++i) {
        int j, k;

        for (j=k=0; s1[j] != '\0'; ++j)
            if (s1[j] != s2[i])
                s1[k++] = s1[j];
        s1[k] = '\0';
    }
}
