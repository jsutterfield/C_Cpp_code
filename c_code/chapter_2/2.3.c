#include <stdio.h>
#include <ctype.h>
#define LINEMAX 1000
#define CONVERT_TO_HEX 55

int atoi(char s[]);
int power(int base, int exp);

main()
{
    char string[] = "0x466DBEE";
    printf("%s == %d\n", string, atoi(string));
    return 0;
}

/* atoi: Convert string of characters to hexadecimal value. Throws error if
 * string not a valid hex number */
int atoi(char s[])
{
    char temp_line[LINEMAX];
    int i, j, valid, result;

    // Skip optional '0x' or '0X' if present
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;
    else
        i = 0;

    for (j=0; s[i]!='\0'; ++i, ++j) {
        s[i] = toupper(s[i]); // Tranform all chars to uppercase, digits unaffected
        if ((s[i] >= '0' && s[i] <= '9')) 
            temp_line[j] = s[i] - '0'; // Store actual digit value, not ascii value
        else if (s[i] >= 'A' && s[i] <= 'F') 
            temp_line[j] = s[i] - CONVERT_TO_HEX; // Store hexadecimal value
        else {
           printf("INVALID hexadecimal value in string: '%c'\n", s[i]);
           return -1;
        }
    }

    i = j - 1;
    result = 0;
    for (j=0; i>=0; ++j, --i)
        result += power(16, i) * temp_line[j];
    
    return result;
}

/* power: Raise base to the power of exp */
int power(int base, int exp)
{
    int result = 1;
    while(exp) { 
        result *= base;
        exp--;
    }
    return result;
}
