#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

int stack[STACK_SIZE];
int stack_index = 0;

int main(int argc, char *argv[])
{
    int temp;
    argc--;
    argv++;

    while (argc > 0) {
        switch(*argv[0]) 
        {
            case '+':
                temp = stack[stack_index - 2] + stack[stack_index - 1];
                stack[stack_index - 2] = temp;
                stack_index--;
                break;
            case '/':
                temp = stack[stack_index - 2] / stack[stack_index - 1];
                stack[stack_index - 2] = temp;
                stack_index--;
                break;
            /* For some reason this dumb fucking thing won't recongize '*'... */
            case 'x': 
                temp = stack[stack_index - 2] * stack[stack_index - 1];
                stack[stack_index - 2] = temp;
                stack_index--;
                break;
            default:
                /* also couldn't figure out how to use pointer arithmetic
                 * for argv[0][1] -- BOO */
                if (*argv[0] == '-' && argv[0][1] == '\0') {
                    temp = stack[stack_index - 2] - stack[stack_index - 1];
                    stack[stack_index - 2] = temp;
                    stack_index--;
                } else 
                    stack[stack_index++] = atoi(*argv);
                break;
        }
        argv++;
        argc--;
    }
    printf("%d\n", stack[--stack_index]);
    return 0;
}

