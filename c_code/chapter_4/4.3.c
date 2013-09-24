/* NOTE: This a combination of excercises 4.3 to 4.9 */
#include <stdio.h> 
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100      /* maximum depth of val stack */
#define MAXVAR 26 /* maximum number of variables available */
#define BUFSIZE 100


int buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */
int bufchar = EOF;
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
double vars[MAXVAR]; /* variable stack */

int getop(char []);
void push(double);
double pop(void);
void showtop(void);
void duptop(void);
void swaptop(void);
void clearstack(void);
void ungets(char []);
int getch(void);
void ungetch(int);


/* reverse Polish calculator */
main()
{
    int type, last_var;
    double op2, last_print;
    char s[MAXOP];

    for (type=0; type < MAXVAR; ++type) /* initalize vars to 0 */
        vars[type] = 0.0;

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push (pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("error: zero divisor\n");
            break;
        case '~':
            push(sin(pop()));
            break;
        case '!':
            push(exp(pop()));
            break;
        case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '=':
            pop();
            vars[last_var - 'A'] = val[sp-1];
            break;
        case '\n':
            last_print = pop();
            printf("\t%.8g\n",  last_print);
            break;
        case 'p':
            showtop();
            break;
        case 'd':
            duptop();
            break;
        case 's':
            swaptop();
            break;
        case 'c':
            clearstack();
            break;
        case 'z':
            push(last_print);
            break;
        default:
            if (type >= 'A' && type <= 'Z') {
                last_var = type;
                push(vars[type - 'A']);
            }
            else
                printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full. can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* showtop: print the top item of the stack */
void showtop(void)
{
    if (sp > 0)
        printf("Top of stack: %g\n", val[sp - 1]);
    else
        printf("No items in stack\n");
}

/* duptop: duplicate the top element and push it to top of stack */
void duptop(void)
{
    double temp = pop();
    push(temp);
    push(temp);
}

/* swaptop: swap position of top two items in stack without popping them */
void swaptop(void)
{
    double temp = val[sp-1];
    printf("Swapping top two elements: %g, %g\n", val[sp-1], val[sp-2]);
    val[sp-1] = val[sp-2];
    val[sp-2] = temp;
}

/* clearstack: Clears the current stack */
void clearstack(void)
{
    sp = 0;
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i = 0, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c !='.' && c !='-')
        return c; /* not a number */
    if (c == '-') 
        if ((c = getchar()) == ' ' || c == '\n') { // '-' is binary operator
            ungetch(c);
            return s[0];
        }
        else 
            s[++i] = c; // '-' is unary operator
    if (isdigit(c)) /* collect integer part*/
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') {  /*collect fraction part*/
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s [i] = '\0';
    if (c != EOF)
        ungetch (c); // necessary to make sure commands like 'p' and 'd'
    return NUMBER;   // aren't skipped on next iteration
}

/* get a (possibly pushed back) character */
int getch(void) 
{
    int temp;

    if (bufchar != EOF) {
        temp = bufchar;
        bufchar = EOF;
        return temp;
    }
    return getchar();
}

/* push character back on input */
void ungetch(int c) 
{
    if (bufchar != EOF)
        printf("ungetch: too many characters\n");
    else;
        bufchar = c;
}

/* push entire string onto input */
void ungets(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++) // find length of string
        ;

    for (i--; i >= 0; i--)
        ungetch(s[i]);
}
