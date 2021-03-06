#include <stdio.h>
#include <string.h>
#include "alloc.c"

#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
main()
{
    int nlines;     /* number of input lines read */
    int million;

    for (million = 1000000; million >= 0; million--) {
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
            qsort(lineptr, 0, nlines-1);
            writelines(lineptr, nlines);
        } else {
            printf("error: input too big to sort\n");
            return 1;
        }
    }
    return 0;
}

#define MAXLEN 1000
/* max length of any input line */
int getlines(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getlines(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy (p, line) ;
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* qsort: sort v[left] ... v[right] into increasing order*/
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)  /* do nothing if array contains */
        return;         /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp= v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* getlines: read in lines from stdin */
int getlines(char *s, int max)
{
    char temp;
    int omax = max;
    while ((temp = getchar()) != EOF && temp != '\n' && max > 1) {
        *s++ = temp;
        max--;
    }
    if (temp == '\n')
        *s++ = temp;
    *s = '\0';
    return omax - max;
}
