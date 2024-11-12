#include <stdio.h>
#include <stdlib.h>

void findCombinations(int* nums, int size, int target, int start, int* current, int currentSize, int results[][100], int* returnSize) {
    if (target == 0) {
        // 找到一个组合，存储到结果中
        for (int i = 0; i < currentSize; i++) {
            results[*returnSize][i] = nums[current[i]];
        }
        (*returnSize)++;
        return;
    }

    for (int i = start; i < size; i++) {
        if (nums[i] > target) {
            break; // 因为数组是递增的，可以提前结束
        }
        current[currentSize] = i; // 记录当前元素的索引
        findCombinations(nums, size, target - nums[i], i + 1, current, currentSize + 1, results, returnSize);
    }
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);
    
    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int results[100][100]; // 假设最多有 100 个组合，每个组合最多 100 个元素
    int returnSize = 0;
    int current[100]; // 当前组合的索引数组

    findCombinations(nums, n, target, 0, current, 0, results, &returnSize);

    printf("%d\n", returnSize); // 输出组合的数量
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < 100 && results[i][j] != 0; j++) {
            printf("%d ", results[i][j]);
        }
        printf("\n");
    }

    free(nums);
    return 0;
}
