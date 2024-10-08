#include <stdio.h>

int intPow(int base, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    else
    {
        int res = base;
        for (; pow > 1; pow--)
        {
            res *= base;
        }
        return res;
    }
}

int getNum(int n, int a)
{
    int sum = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        sum += a * intPow(10, i);
    }
    return sum;
}

int main()
{
    int n, a, sum = 0;
    scanf("%d%d", &n, &a);
    for (int i = 1; i <= n; i++)
    {
        sum += getNum(i, a);
    }
    printf("%d", sum);
    return 0;
}