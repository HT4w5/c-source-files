#include <stdio.h>

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void selSort(int *arr, int length)
{
    int *max;
    for (int i = 0; i < length; ++i)
    {
        max = &arr[i];
        for (int j = i; j < length; ++j)
        {
            if (arr[j] > *max)
            {
                max = &arr[j];
            }
        }
        if (max != &arr[i])
        {
            swap(max, &arr[i]);
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num[i]);
    }
    selSort((int *)num, n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d", num[i]);
        if (i != n - 1)
        {
            printf(" ");
        }
    }
    return 0;
}