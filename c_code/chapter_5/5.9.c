#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

main() 
{
    int month, day;
    month_day(2008, 96, &month, &day);
    printf("month = %d\nday = %d\n", month, day);
    printf("%d\n", day_of_year(2013, 1, 32));
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    if (year < 1752 || month < 1 || month > 12 || day < 1)
        return -1;
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (day > daytab[leap][month])
        return -1;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    if (year < 1752 || yearday < 1)
        return -1;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if ((leap && yearday > 366) || (!leap && yearday > 365))
        return -1;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

