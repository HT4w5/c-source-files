// sortTest.c: This sort method that I'm not sure about.
#include <stdio.h>

void int_swap(int *a, int *b);

int main(void)
{
    /**
     * nums[][0]: value.
     * nums[][1]: sequence.
     *
     */
    int n_nums;
    scanf("%d", &n_nums);
    int nums[n_nums][2];

    // Input nums.
    for (int i = 0; i < n_nums; ++i)
    {
        scanf("%d", &nums[i][0]);
        nums[i][1] = i + 1;
    }

    // Sort.
    for (int i = 0; i < n_nums; ++i)
    {
        for (int j = i + 1; j < n_nums; ++j)
        {
            // Sort in acsending order.
            // Commence swap if a>b.
            if (nums[i][0] > nums[j][0])
            {
                int_swap(&nums[i][0], &nums[j][0]);
                int_swap(&nums[i][1], &nums[j][1]);
            }
        }
    }

    // Output nums.
    for (int i = 0; i < n_nums; ++i)
    {
        printf("%d(%d) ", nums[i][0], nums[i][1]);
    }
    printf("\n");

    return 0;
}

void int_swap(int *a, int *b)
{
    if (*a != *b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}