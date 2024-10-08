#include<stdio.h>

int intPow(int base, int pow)
{
    int res = base;
    for(; pow > 1; pow--)
    {
        res *= base;
    }
    return res;
}

void swap(int * n1, int * n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

int getLength(int n)
{
    int i = 0;
    while(n != 0)
    {
        i++;
        n /= 10;
    }
    return i;
}

int main(void)
{
    int a, b;
    scanf("%d,%d", &a, &b);
    if(a < b)
    {
        swap(&a, &b);
    }
    a *= intPow(10, getLength(b));
    printf("%d", a + b);
    return 0;
}
