#include <stdio.h>

int recsum(int *arr, int len);

int main(void)
{
    int n;
    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &nums[i]);
    }

    printf("%d", recsum(nums, sizeof(nums)/sizeof(nums[0])));

    return 0;
}

int recsum(int *arr, int len)
{
    if (len == 1) // Base case.
    {
        return *arr;
    }
    else // Recursive case.
    {
        return recsum(arr + 1, len - 1) + *arr;
    }
}