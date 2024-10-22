#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = 0;

int next(int x)
{
    if (x == n - 1)
    {
        x = 0;
    }
    else
    {
        x++;
    }
    return x;
}

int prev(int x)
{
    if (x == 0)
    {
        x = n - 1;
    }
    else
    {
        x--;
    }
    return x;
}

int main(void)
{
    // Get mat size.
    scanf("%d", &n);

    // Init 0 mat.
    int mat[n][n];
    memset(mat, -1, sizeof(mat));

    // Start creation.
    int row = 0, col = (n - 1) / 2;
    for (int i = 1; 1; i++)
    {
        mat[row][col] = i;
        if (mat[prev(row)][next(col)] == -1)
        {
            row = prev(row);
            col = next(col);
        }
        else if (mat[next(row)][col] == -1)
        {
            row = next(row);
        }
        else
        {
            break;
        }
    }

    // Print result.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", mat[i][j]);
            if (j != n - 1)
            {
                printf(" ");
            }
        }
        if (i != n - 1)
        {
            printf("\n");
        }
    }

    return 0;
}
