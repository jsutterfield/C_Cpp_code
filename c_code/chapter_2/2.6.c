#include <stdio.h>

int setbits(int x, int p, int n, int y);

main()
{
    int x, y, p, n;
    x = 165;
    y = 91;
    p = 5;
    n = 3;

    printf("%d\n", setbits(x, p, n, y));
}

/* Return x with the n bits that begin at position p set to the rightmost n bits
 * of y, leaving the other bits unchanged. See comment below for details */
int setbits(int x, int p, int n, int y)
{
    return y & ~(~0 << n) << (p + 1 - n) | (x >> p+1 << p+1) | (x & ~(~0 << n));
}

/* So, that's a big fucking mess of a return statement, but it works. Here's why:
 * First you mask the n right characters of y and turn off all the bits 
 * on the left. Then you shift those bit to position p. Then, in x, you shift
 * to the right up to position p then shift back (effectively changing all bits
 * to the right of position p into 0). Then you use the Or operator to combine
 * the two creating a string of bits that's accurate up to p+n (to the right of
 * that should still be zeros). Then you mask x again for the remaining characters
 * ie, turn those to the left into 0's, and then use the or operator again to combine
 * that with the string of bits you already have. */
