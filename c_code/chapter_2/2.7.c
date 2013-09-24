#include <stdio.h>
#include <ctype.h>


main()
{
    int x = 120;
    int p = 5;
    int n = 3;
    printf("%d\n", ~x >> (p+1-n));// & ~(~0 << n) << (p+1-n) | (x >> p << p) | (~(~0 << n ) & x));
}
// | ~(~0 << p + 1 - n));

