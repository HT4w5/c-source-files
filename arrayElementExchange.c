#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b)
{
    if (a != b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    // Find max and min.
    int max = INT_MIN, min = INT_MAX;
    int *max_ptr = NULL, *min_ptr = NULL;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_ptr = arr + i;
        }
    }
    swap(arr + n - 1, min_ptr);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_ptr = arr + i;
        }
    }
    swap(arr, max_ptr);
    // Print the result.
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}