#include <stdio.h>

/* count characters in input; 1st version 
main()
{
    long nc;
     nc = 0;
     while(getchar() != EOF)
        ++nc;
     printf("%ld\n", nc);
}
*/

/* count characters in input; 2nd version
main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
*/

/* count lines in input 
main()
{
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}

main()
{
    int c, nl, tabs, sp;

    nl = 0;
    tabs = 0;
    sp = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        if (c == ' ')
            ++sp;
        if (c == '\t')
            ++tabs;
    }
    printf("newlines: %d\n", nl);
    printf("spaces: %d\n", sp);
    printf("tabs: %d\n", tabs);
}
*/

/* Copies input to output, eliminating extra spaces 
main()
{
    int c, space_char;

    space_char = 0;

    c = getchar();
    while(c != EOF){
        if (c == ' '){
            if (space_char == 0) {
                putchar(c);
                space_char = 1;
            }
        } else {
            space_char = 0;
            putchar(c);
        }
        c = getchar();
    }
}


main()
{
    int c;

    while((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}
*/

main()
{
    int c, space_char;

    space_char = 0;
    while((c = getchar()) != EOF) {
        if (c == '\t' | c == ' ') {
            if (space_char == 0) {
                putchar('\n');
                space_char = 1;
            }
        }
        else {
            putchar(c);
            space_char = 0;
        }   
    }
}
