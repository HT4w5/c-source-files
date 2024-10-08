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

int getPrime()
{
    lastPrime++;
    while (!isPrime(lastPrime))
    {
        lastPrime++;
    }
    return lastPrime;
}

int main(void)
{
    int n, p, fact[100], i = 0;
    scanf("%d", &n);
    printf("%d=", n);
    while (n != 1)
    {
        p = getPrime();
        while (n % p == 0)
        {
            n /= p;
            fact[i++] = p;
        }
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d", fact[j]);
        if (j != i - 1)
        {
            printf("*");
        }
    }
    return 0;
}