#include <stdio.h>
#include <stdlib.h>

char* timeConversion(char* s)
{
    int hour = (s[0] - '0') * 10 + (s[1] - '0');

    if (s[8] == 'A')
    {
        if (hour == 12)
        {
            hour = 0;
        }
    }
    else
    {
        if (hour != 12)
        {
            hour += 12;
        }
    }

    s[0] = (hour / 10) + '0';
    s[1] = (hour % 10) + '0';

    s[8] = '\0';

    return s;
}
