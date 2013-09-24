#include<stdio.h>
int fact(int i);

main()
{
    printf("%d\n", fact(5));
}

int fact(int i)
{
    return (i > 1) ? i * fact(i-1) : i;
}
