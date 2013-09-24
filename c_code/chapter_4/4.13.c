#include<stdio.h>

void reverse(char s[]);

main()
{
    char s[] = "Will this entire string be reversed?";    
    reverse(s);

    printf("%s\n", s);
}

void reverse(char s[])
{
    static int left = 0;
    static int right = 0;
    int temp;

    if (left == 0) { /* First time calling */
        while(s[right++] != '\0')
            ;
        right -= 2;
    }

    if (right > left) {
        int temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
        reverse(s);
    }
}
