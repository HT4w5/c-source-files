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
    if (n <= 0)
    {
        printf("0\n");
        return 0;
    }
    int *score1 = (int *)malloc(n * sizeof(int));
    int *score2 = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score2[i]);
    }
    quick_sort(score1, n);
    quick_sort(score2, n);

    // Start comparasion
    int count = 0;
    int *p1 = score1, *p2 = score2;

    while (1)
    {
        if (*p1 > *p2)
        {
            count++;
            p1++;
            p2++;
        }
        else
        {
            p2++;
        }
        if (p1 >= score1 + n || p2 >= score2 + n)
        {
            break;
        }
    }

    printf("%d\n", count);
    free(score1);
    free(score2);
    return 0;
}