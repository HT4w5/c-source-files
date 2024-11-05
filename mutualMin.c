#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int *arr1 = (int *)malloc(m * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1[i] == arr2[j])
            {
                printf("%d", arr1[i]);
                return 0;
            }
        }
    }
    printf("-1");

    return 0;
}