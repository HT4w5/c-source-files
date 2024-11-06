#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    int n, tgt;
    scanf("%d", &n);
    int *nums = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &tgt);

    quick_sort(nums, n);

    int *low, *high;
    int sum = 0, closest_sum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        low = nums + i + 1;
        high = nums + n - 1;
        while (low < high)
        {
            sum = *low + *high + nums[i];
            if (abs(sum - tgt) < abs(closest_sum - tgt))
            {
                closest_sum = sum;
            }

            if (sum < tgt)
            {
                high--;
            }
            else if (sum > tgt)
            {

                low++;
            }
            else
            {
                printf("%d\n", sum);
                free(nums);
                return 0;
            }
        }
    }

    printf("%d\n", closest_sum);
    free(nums);
    return 0;
}