#include <stdio.h>
#include <stdlib.h>

/*
n_combos: Number of found combos.
combo_indexes: Indexes of numbers in one combo.

*/

void find_combo_rec(int *nums_array, int array_size, int target_sum, int start_index, int *combo_indexes, int combo_size, int combos[][1001], int *n_combos)
{
    // Valid combo found.
    if (target_sum == 0)
    {
        for (int i = 0; i < combo_size; i++)
        {
            // n_combos is index for current combo before increment.
            combos[*n_combos][i] = nums_array[combo_indexes[i]];
        }
        combos[*n_combos][1000] = combo_size;
        (*n_combos)++;
    }
    // Array length exceeded.
    if (start_index >= array_size)
    {
        return;
    }

    for (int i = start_index; i < array_size; i++)
    {
        if (nums_array[i] > target_sum)
        {
            return;
        }
        else
        {
            // combo_size is an independent instance in every iteration.
            // combo_indexes gets overwritten after sub-iteration finishes.
            combo_indexes[combo_size] = i;
            find_combo_rec(nums_array, array_size, target_sum - nums_array[i], i + 1, combo_indexes, combo_size + 1, combos, n_combos);
        }
    }
}

// Shim function on the outmost layer.
void find_combo(int *nums_array, int array_size, int target_sum, int combos[][1001], int *n_combos)
{
    // Declare combo indexes.
    int combo_indexes[100];
    // Invoke recursive function.
    find_combo_rec(nums_array, array_size, target_sum, 0, (int *)&combo_indexes, 0, combos, n_combos);
}

int main(void)
{
    // Input data.
    int n_nums, target;
    scanf("%d%d", &n_nums, &target);
    int *nums = (int *)malloc(sizeof(int) * n_nums);
    for (int i = 0; i < n_nums; i++)
    {
        scanf("%d", &nums[i]);
    }

    // Declare combos array to store found combos.
    int combos[100][1001];
    int n_combos = 0;

    // Find combos.
    find_combo(nums, n_nums, target, combos, &n_combos);

    // Print results.
    printf("%d\n", n_combos);
    for (int i = 0; i < n_combos; i++)
    {
        for (int j = 0; j < combos[i][1000]; j++)
        {
            printf("%d", combos[i][j]);
            if (j < combos[i][1000] - 1)
            {
                printf(" ");
            }
        }
        if (i < n_combos - 1)
        {
            printf("\n");
        }
    }

    return 0;
}