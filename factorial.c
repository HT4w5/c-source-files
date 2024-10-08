#include<stdio.h>

int main()
{
    int n, fsum, sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        fsum = 1;
        for(int j = 1; j <= i; j++)
        {
            fsum *= j;
        }
        sum += fsum;
    }
    printf("sum=%d", sum);
    return 0;
}