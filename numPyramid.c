#include<stdio.h>

void printSpace(int n)
{
    for(int i = 1; i <= n; i++)
    {
        printf(" ");
    }
}

int main(void)
{
    int n, length, a = 10; //a records numbers being used.
    scanf("%d", &n);
    length = 4 * n - 2; //Length of pyramid base.
    for(int i = 1; i <= n; i++)
    {
        printSpace((length - (i * 4 - 2))/2);
        for(int j = 1; j <= i; j++)
        {
            printf("%d", a);
            if(j < i)
            {
                printf("  ");
            }
            a++;
        }
        if(i < n)
        {
            printf("\n");
        }
    }
    return 0;
}