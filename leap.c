#include <stdio.h>

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

int main(void)
{
    int yr;
    scanf("%d", &yr);
    if (isLeap(yr))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}