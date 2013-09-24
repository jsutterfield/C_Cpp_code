#include<stdio.h>

#define swap(t,x,z) { t _z_ = x; x = z; z = _z_; }

main()
{
    char a = 'a';
    char b = 'b';
    printf("a = %c and b = %c\n", a, b);
    swap(char, a, b);
    printf("a = %c and b = %c\n", a, b);
}

