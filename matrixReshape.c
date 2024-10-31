#include <stdio.h>
#include <stdlib.h>

int reshape(int *orig, int *new, int orow, int ocol, int row, int col)
{
    if (orow * ocol == row * col)
    {
        for (int i = 0; i < row * col; ++i)
        {
            *(new + i) = *(orig + i);
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    int m, n, r, c;
    scanf("%d%d", &m, &n);
    int mat[m][n];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    scanf("%d%d", &r, &c);

    int new_mat[r][c];
    if (reshape((int *)mat, (int *)new_mat, m, n, r, c))
    {
        r = m;
        c = n;
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            printf("%d", new_mat[i][j]);
            if (j != c - 1)
            {
                printf(" ");
            }
        }
        if (i != r - 1)
        {
            printf("\n");
        }
    }
}