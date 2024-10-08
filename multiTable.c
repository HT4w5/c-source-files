#include <stdio.h>

void printUnit(int a, int b)
{
    printf("%d*%d=%d", a, b, a * b);
}

void printRow(int i)
{
    for (int j = 1; j <= i; j++)
    {
        printUnit(i, j);
        if (j != i)
        {
            printf(" ");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printRow(i);
        if (i != n)
        {
            printf("\n");
        }
    }
    return 0;
}