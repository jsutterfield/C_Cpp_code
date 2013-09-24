#include <stdio.h>
#include <limits.h>

void print_from_header();
void print_from_cal();

main()
{
    print_from_header();
}

void print_from_header()
{
    printf("Ranges of C's various data types\n");
    printf("--------------------------------\n");
    printf("Unsigned CHAR Min: %d\n", CHAR_MIN);
    printf("Unsigned CHAR Max: %d\n", UCHAR_MAX);
    printf("Signed CHAR Min: %d\n", SCHAR_MIN);
    printf("Signed CHAR Max: %d\n", SCHAR_MAX);
    printf("Unsigned SHORT Min: %d\n", 0);
    printf("Unsigned SHORT Max: %d\n", USHRT_MAX);
    printf("Signed SHORT Min: %d\n", SHRT_MIN);
    printf("Signed SHORT Max: %d\n", SHRT_MAX);
    printf("Unsigned INT Min: %d\n", 0);
    printf("Unsigned INT Max: %d\n", UINT_MAX);
    printf("Signed INT Min: %d\n", INT_MIN);
    printf("Signed INT Max: %u\n", INT_MAX);
    printf("Unsigned LONG Min: %d\n", 0);
    printf("Unsigned LONG Max: %ld\n", ULONG_MAX);
    printf("Signed LONG Min: %ld\n", LONG_MIN);
    printf("Signed LONG Max: %ld\n", LONG_MAX);
}

void print_from_cal()
{
    unsigned int i;

    i = ~0;
    i >>= 1;
    printf("%d\n", i);
    printf("%d\n", -i -1);
}

/* This works becuase of two compliment, aka, the way most computers represent
 * positive and negative numbers. To get the negative of an int, you do one's
 * compliment (invert the bits) and add 1. eg, 011 = 3, to get negative 3 you
 * invert the bits, 100, and add 1, 101. That's -3 in 2s compliment. The ~ is
 * a bitwise operator which inverts the bits, the >>= is an assignment operator
 * which shifts all the bits to the right 1 (leaving a default 0 on the far left)
 * and assigns it. So, you declare a unsigned data type (unsigned int 1) which
 * is allocated a certain number of bits in memory. You assign that to ~0, aka
 * all 1's, then shift the bits left giving you a leading 0. The result is 
 * 01111111, or however many bits the datatype can hold. That pattern, a 0
 * followed by all 1s will always result in the maximum positive value for a given
 * datatype using twos compliment. To get the bottom range, you're trying to
 * reorganize the bits into a pattern like this -- 10000000. Given that our current
 * pattern is 011111111, we convert it to negative (aka, take two compliment),
 * which results in 100000000, followed by 100000001. Then we subtract 1 to yeild
 * 100000000. Easy!
 *
 * Also worth noting, c will assume all integral datatypes are signed unless
 * otherwise noted */
