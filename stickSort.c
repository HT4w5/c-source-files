#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

int main()
{
    int n, num[100];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i - 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (num[i - 1] > num[j - 1])
            {
                swap(&num[i - 1], &num[j - 1]);
            }
        }
    }
    printf("%d", num[0]);
    return 0;
}

int isTriangle(int a,int b,int c)
{

}

int main()
{
    int n, maxCirc = 0;
    scanf("%d", &n);
    int *sticks = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", sticks + i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {

            }
        }
    }
}