#include <stdio.h>
#include <limits.h>

int minSqFactorCount(int num)
{
    int maxSqrt = 1, count = 0, minCount = INT_MAX, sqrt, numT;
    // Find max square.
    while (num >= maxSqrt * maxSqrt)
    {
        ++maxSqrt;
    }
    --maxSqrt;

    for (; maxSqrt > 0; --maxSqrt)
    {
        sqrt = maxSqrt;
        numT = num;
        count = 0;
        // Turncate num.
        while (numT > 0)
        {
            if (numT >= sqrt * sqrt)
            {
                numT -= sqrt * sqrt;
                ++count;
            }
            else
            {
                --sqrt;
            }
        }
        if (count < minCount)
        {
            minCount = count;
        }
    }

    return minCount;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", minSqFactorCount(n));
    return 0;
}