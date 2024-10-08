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
    int i = 1;
    while (lastPrime < 97)
    {
        printf("%d", getPrime());
        if (i % 5 == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
        i++;
    }
    return 0;
}
