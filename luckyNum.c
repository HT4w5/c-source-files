#include <stdio.h>
#include <stdlib.h>

int *createArray(int length)
{
    int *arr = malloc(sizeof(int) * length);
    return arr;
}

int main()
{
    int n, luckyNum = -1, curr, times;
    scanf("%d", &n);
    int *arr = createArray(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < n; i++)
    {
        curr = *(arr + i);
        *(arr + i) = -1;
        times = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (curr == *(arr + j))
            {
                times++;
                *(arr + j) = -1;
            }
        }
        if (curr == times && curr > luckyNum)
        {
            luckyNum = curr;
        }
    }
    printf("%d", luckyNum);
    free(arr);
    return 0;
}