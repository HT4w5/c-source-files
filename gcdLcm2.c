#include<stdio.h>

int gcd(int a, int b)
{
    while(a != b)
    {
        if(a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int a, b;
    scanf("%d,%d", &a, &b);
    printf("最大公约数是%d\n最小公倍数是%d", gcd(a, b), lcm(a, b));
    return 0;
}