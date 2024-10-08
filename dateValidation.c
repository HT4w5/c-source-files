#include <stdio.h>
#include <math.h>

int getLength(int n)
{
    int i = 0;
    while (n != 0)
    {
        i++;
        n /= 10;
    }
    return i;
}

int getOnes(int n)
{
    return n - (n / 10) * 10;
}

int isLargeMonth(int mth)
{
    int i = 0;
    switch (mth)
    {
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        i = 1;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        // day += 30;
        break;
    }
    return i;
}

int isLeap(int yr)
{
    int leap = 0;
    if (yr % 100 == 0)
    {
        if (yr % 400 == 0)
            leap = 1;
    }
    else
    {
        if (yr % 4 == 0)
            leap = 1;
    }
    return leap;
}

int main()
{
    int buff, length, yr = 0, mth = 0, day = 0, invalid = 0;
    scanf("%d", &buff);
    length = getLength(buff);
    for (int i = 1; i <= 2; i++)
    {
        day += getOnes(buff) * pow(10, i - 1);
        buff /= 10;
    }
    for (int i = 1; i <= 2; i++)
    {
        mth += getOnes(buff) * pow(10, i - 1);
        buff /= 10;
    }
    for (int i = 1; i <= length - 4; i++)
    {
        yr += getOnes(buff) * pow(10, i - 1);
        buff /= 10;
    }
    // determine whether mth is over 2
    switch (mth)
    {
    case 1:
        if (day > 31)
        {
            invalid = 1;
        }
        break;
    case 2:
        // determine whether yr is leap yr
        if (isLeap(yr))
        {
            if (day > 29)
            {
                invalid = 1;
            }
        }
        else
        {
            if (day > 28)
            {
                invalid = 1;
            }
        }
        day += 31;
        break;
    case 3 ... 12:
        // simulate
        if (isLargeMonth)
        {
            if (day > 31)
            {
                invalid = 1;
            }
        }
        else
        {
            if (day > 30)
            {
                invalid = 1;
            }
        }
        while (mth > 2)
        {
            if (isLargeMonth(mth))
            {
                day += 31;
            }
            else
            {
                day += 30;
            }
            mth--;
        }
        if (isLeap(yr))
        {
            day += 29;
        }
        else
        {
            day += 28;
        }
        break;
    default:
        invalid = 1;
        break;
    }
    if (invalid == 1)
    {
        printf("Invalid");
    }
    else
    {
        printf("%d", day);
    }
    return 0;
}