#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    if (a == b)
    {
        return;
    }
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int *get_median(int *arr, int len)
{
    int first = arr[0];
    int last = arr[len - 1];
    int mid = arr[len / 2];
    if ((first > mid) ^ (first > last))
    {
        return arr;
    }
    else if ((last > mid) ^ (last > first))
    {
        return arr + len - 1;
    }
    else
    {
        return arr + len / 2;
    }
}

void quick_sort(int *arr, int len)
{
    if (len <= 1)
    {
        return;
    }
    swap(arr, get_median(arr, len));
    int pivot = *arr;
    int *low = arr, *high = arr + len - 1;
    while (low < high)
    {
        while (*high <= pivot && high > low)
        {
            high--;
        }
        while (*low >= pivot && low < high)
        {
            low++;
        }
        swap(low, high);
    }
    swap(arr, high);

    int *right = high + 1;
    int *left = arr;
    int left_len = high - arr;
    int right_len = len - left_len - 1;
    quick_sort(left, left_len);
    quick_sort(right, right_len);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n - 1)
        {
            printf(" ");
        }
    }
    free(arr);
    return 0;
}