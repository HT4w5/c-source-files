#include <stdio.h>

int isCompleteNum(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    if (sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    for (int i = 1; i <= 1000; i++)
    {
        if (isCompleteNum(i))
        {
            printf("%d", i);
            if (i != 496)
            {
                printf(" ");
            }
        }
    }
    return 0;
}