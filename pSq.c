#include <stdio.h>

int minSqFactorCount(int num)
{
    int maxSqrt = 1, count = 0;
    // Find max square.
    while (num >= maxSqrt * maxSqrt)
    {
        ++maxSqrt;
    }
    --maxSqrt;

    // Turncate num.
    while (num > 0)
    {
        if (num >= maxSqrt * maxSqrt)
        {
            num -= maxSqrt * maxSqrt;
            ++count;
        }
        else
        {
            --maxSqrt;
        }
    }
    return count;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", minSqFactorCount(n));
    return 0;
}