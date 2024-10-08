#include <stdio.h>

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