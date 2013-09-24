#include <stdio.h> 
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100      /* maximum depth of val stack */
#define MAXVAR 26 /* maximum number of variables available */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
double vars[MAXVAR]; /* variable stack */
char line[MAXVAL];  /* string to hold input line */
int j; /* keeps track of position in external array line */

int getop(char []);
void push(double);
double pop(void);
void showtop(void);
void duptop(void);
void swaptop(void);
void clearstack(void);
int getlines(void);

/* reverse Polish calculator */
main()
{
    int type, last_var;
    double op2, last_print;
    char s[MAXOP];

    for (type=0; type < MAXVAR; ++type) /* initalize vars to 0 */
        vars[type] = 0.0;

    while (getlines() != 0) {
        while ((type = getop(s)) != '\0') {
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
    int i = 0;
    while ((s[0] = line[j++]) == ' ' || s[0] == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(s[0]) && s[0] !='.' && s[0] !='-')
        return s[0]; /* not a number */
    if (s[0] == '-') 
       if (line[j]  == ' ' || line[j] == '\n') 
            return s[0]; // '-' is binary operator
        else 
            s[++i] = line[j++]; // '-' is unary operator
    if (isdigit(s[i])) /* collect integer part*/
        while (isdigit(line[j]))
            s[++i] = line[j++];
    if (s[i] == '.') {  /*collect fraction part*/
        while (isdigit(line[j]))
            s[++i] = line[j++];
    }
    s[++i] = '\0';
    return NUMBER;
}

/* getlines: reads input line into external variabe line */
int getlines(void)
{
    int i, c;
    j = 0;

    for (i=0; (c = getchar()) != '\n'; i++)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';

    return --i;
}
