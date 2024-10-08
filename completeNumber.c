#include <stdio.h>

int lastPrime = 1;

int intSqrt(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int i = 1;
        while (i * i <= n)
        {
            i++;
        }
        return i - 1;
    }
}

int isPrime(int n)
{
    int ul = intSqrt(n);
    for (int i = 2; i <= ul; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int getPrime(void)
{
    lastPrime++;
    while (!isPrime(lastPrime))
    {
        lastPrime++;
    }
    return lastPrime;
}

int isCompleteNum(int orig)
{
    int p, sum = 0, n = orig;
    // scanf("%d", &n);
    // printf("%d=", n);
    while (n != 1)
    {
        p = getPrime();
        while (n % p == 0)
        {
            n /= p;
        }
        sum += p;
    }
    lastPrime = 1;
    if (sum + 1 == orig)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    for (int i = 1; i <= 1000; i++)
    {
        if (isCompleteNum(i))
        {
            printf("%d", i);
            if (i != 1000)
            {
                printf(" ");
            }
        }
    }
    return 0;
}