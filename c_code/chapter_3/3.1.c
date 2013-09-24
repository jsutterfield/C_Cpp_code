#include <stdio.h>
#define ARRAY_LIMIT 1000000

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

main()
{
    int array[ARRAY_LIMIT];
    int i;

    for (i=0; i < ARRAY_LIMIT; ++i)
        array[i] = i;
    
    printf("%d\n", binsearch(45000, array, ARRAY_LIMIT));
    printf("%d\n", binsearch2(45000, array, ARRAY_LIMIT));

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid -1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/* binsearch2: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n -1;
    for (; low <= high; (x < v[mid]) ? high = mid -1 : low = mid + 1) {
        mid = (low + high) / 2;
        if (x == v[mid])
            return mid;
    }
    return -1;
}
