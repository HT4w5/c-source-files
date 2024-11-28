#include <stdio.h>

void int_swap(int *a, int *b);

int main(void)
{
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    // Bubble sort.
    int next_it = 1;
    while (next_it)
    {
        next_it = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                int_swap(&nums[i], &nums[i + 1]);
                next_it = 1;
            }
        }
    }

    // Print results.
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}

void int_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}