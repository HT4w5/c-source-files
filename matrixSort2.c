#include <stdio.h>
#include <limits.h>

int main(void)
{
    // Get matrix size.
    int n, m;
    scanf("%d%d", &n, &m);

    // Get matrix.
    int mat[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    int maxSum = INT_MIN, sum1 = 0, sum2 = 0;

    // Compare row sum.
    for (int i = 0; i < n - 1; i++)
    {
        sum1 = 0;
        for (int j = 0; j < m; j++)
        {
            sum1 += mat[i][j];
        }
        for (int j = i + 1; j < n; j++)
        {
            sum2 = sum1;
            for (int k = 0; k < m; k++)
            {
                sum2 += mat[j][k];
            }
            if (maxSum < sum2)
            {
                maxSum = sum2;
            }
        }
    }

    // Compare column sum.
    for (int i = 0; i < m - 1; i++)
    {
        sum1 = 0;
        for (int j = 0; j < n; j++)
        {
            sum1 += mat[j][i];
        }
        for (int j = i + 1; j < m; j++)
        {
            sum2 = sum1;
            for (int k = 0; k < n; k++)
            {
                sum2 += mat[k][j];
            }
            if (maxSum < sum2)
            {
                maxSum = sum2;
            }
        }
    }

    printf("%d", maxSum);
    return 0;
}