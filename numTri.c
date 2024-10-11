#include <stdio.h>

int lastNum = 0;

int getNum()
{
    return ++lastNum;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = n; i != 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%02d", getNum());
        }
        printf("\n");
    }
}