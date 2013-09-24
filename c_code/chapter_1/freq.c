/*
#include <stdio.h>
#define ARRAY_LENGTH 20

main()
{

    int c, longest_word_length, current_word_length, index;
    int words[ARRAY_LENGTH];
    int i, j;
    index = longest_word_length = current_word_length = 0;

    while((c = getchar()) != EOF) {
        if (index > ARRAY_LENGTH)
            break;
        if (c == '\t' | c == ' ' | c == '\n') {
           words[index] = current_word_length;
           ++index;
           current_word_length = 0;
        }
        else {
            ++current_word_length;
            if (current_word_length > longest_word_length)
                longest_word_length = current_word_length;
        }
    }

    for (i = longest_word_length; i > 0; --i) {
        for (j = 0; j < index; ++j) {
            if (words[j] >= i)
                putchar('#');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}
*/
#include <stdio.h>
#define ARRAY_LENGTH 93
#define BOTTOM_ASCII 33 // Subtract this from every char so ! starts at array index 0
#define TOP_ASCII 125

main() {
    int chars[ARRAY_LENGTH];
    int i, c;
    int index = 0;

    for (i = 0; i < ARRAY_LENGTH; ++i)
        chars[i] = 0;

    while((c = getchar()) != EOF)
        ++chars[c - BOTTOM_ASCII];

    for (i = BOTTOM_ASCII; i <= TOP_ASCII; i++){
        printf("%c: ", i);
        printf("%d\n", chars[index]);
        ++index;
    }
}
