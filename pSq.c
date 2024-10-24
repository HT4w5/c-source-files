#include <stdio.h>

int maxSqFactorCount(int num)
{
    int minCount = num;
    for (int i = 2; num >= i * i; i++)
    {
        if (num % (i * i) == 0)
        {
            minCount = num / (i * i);
        }
    }
    return minCount;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", maxSqFactorCount(n));
    return 0;
}