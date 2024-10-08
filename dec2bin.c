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

int dec2bin(int n)
{
    int r = 0;
    for (int i = 0; n != 0; i++)
    {
        r += n % 2 * intPow(10, i);
        n /= 2;
        // r *= 10;
    }
    //r /= 10;
    return r;
}

int main()
{
    int dec;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &dec);
        printf("%d\n", dec2bin(dec));
    }
    return 0;
}