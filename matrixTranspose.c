#include <stdio.h>

int main()
{
    int mat[4][3];
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            scanf("%d", &mat[i - 1][j - 1]);
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            printf("%d", mat[i - 1][j - 1]);
            j == 3 ?: printf(" ");
        }
        i == 4 ?: printf("\n");
    }
    printf("\n转置矩阵为\n");
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            printf("%d", mat[j - 1][i - 1]);
            j == 4 ?: printf(" ");
        }
        i == 3 ?: printf("\n");
    }

    return 0;
}