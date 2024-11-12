#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_combinations_recursive(int *nums, int size, int target, int *combo[100], int *combo_size, int num_num, int *num_combo)
{
    *num_combo = 0;
    for (int i = 0; i < size; i++)
    {
        while (target <= nums[i] && num_num < 1000)
        {
            if (target == nums[i])
            {
                combo[(*num_combo) - 1][num_num] = nums[i];
                combo_size[(*num_combo) - 1] = current_size + 1;
            }
        }
    }
}

int main(void)
{
    int n, target;
    scanf("%d %d", &n, &target);
    int *nums = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int combo[100][1000];
    int combo_size[100];
    int count = 0;
    find_combinations_recursive(nums, target, 0, combo, count);
    return 0;
}