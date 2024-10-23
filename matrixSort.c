#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Get size.
    int n, m, maxSum = 0, sum;    // TODO:
    scanf("%d%d", &n, &m);

    // Create matrix.
    int **mat = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        mat[i] = malloc(sizeof(int) * m);
    }

    // Get matrix.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", *(mat + i) + j);
        }
    }

    // Calc rows.
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            sum = 0;
            for (int j = 0; j < m; j++)
            {
                sum += (*(mat + i))[j] + (*(mat + k))[j];
            }
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }

    // Calc columns.
    for (int i = 0; i < m; i++)
    {
        for (int k = i + 1; k < m; k++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += (*(mat + j))[i] + (*(mat + j))[k];
            }
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }

    // Free memory.
    for (int i = 0; i < n; i++)
    {
        free(mat[i]);
    }
    free(mat);

    printf("%d", maxSum);
    return 0;
}