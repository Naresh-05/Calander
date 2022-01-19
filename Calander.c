#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int isLeapYear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
int validateDate(int day,int month,int year)
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    days[2] += isLeapYear(year);
    return ((month >= 1 && month <= 12) && (day >= 1 && day <= days[month]));
}
int monthCode(int month,int year)
{
    int monthCode[13] = {0, 1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
    monthCode[1] -= isLeapYear(year);
    monthCode[2] -= isLeapYear(year);
    return monthCode[month];
}
int centuryCode(int century)
{
    int centuryCode[4] = {6, 4, 2, 0};
    return centuryCode[century % 4];
}

int main()
{
    char Month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "Augest", "September", "October", "November", "December"};
    char Day[7][10] = {"saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    char Date[4][3] = {"th", "st", "nd", "rd"};
    int day,month,year,century,leapYear;
    char str[5];
    printf("Enter the Date in Formate DD-MM-YYYY: ");
    scanf("%d-%d-%s", &day, &month,str);
    year = atoi(&str[2]);
    str[2]='\0';
    century = atoi(str);
    if(!validateDate(day,month,year))
    {
        printf("INVALID DATE?");
        return 0;
    }
    leapYear = year / 4;
    int result = (day + monthCode(month, year) + year + leapYear + centuryCode(century)) % 7;
    int date = ((day % 10)<=3&&!(day>=11&&day<=13))?day%10:0;
    printf("\"%02d%s %s %02d%02d\" (%02d-%02d-%02d%02d) is \"%s\"", day, Date[date], Month[month - 1], century, year, day, month, century, year, Day[result]);
}