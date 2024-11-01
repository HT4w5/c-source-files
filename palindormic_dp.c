#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct palindormic_matrix
{
    int **matrix;
    int sum;
    int len;
};

struct palindormic_matrix *create_pmatrix(int len)
{
    struct palindormic_matrix *p = malloc(sizeof(struct palindormic_matrix));
    p->matrix = (int **)malloc(len * sizeof(int *));
    for (int i = 0; i < len; ++i)
    {
        p->matrix[i] = (int *)malloc(len * sizeof(int));
        memset(p->matrix[i], 0, len * sizeof(int));
    }
    p->sum = 0;
    p->len = len;
    return p;
}

void destroy_pmatrix(struct palindormic_matrix *p)
{
    for (int i = 0; i < p->len; ++i)
    {
        free(p->matrix[i]);
    }
    free(p->matrix);
    free(p);
}

void pmatrix_mark(struct palindormic_matrix *p, int i, int j)
{
    p->matrix[i][j] = 1;
    p->sum++;
}

int pmatrix_query(struct palindormic_matrix *p, int i, int j)
{
    return p->matrix[i][j];
}

int palindormic_count(char *str)
{
    int len = strlen(str);
    struct palindormic_matrix *p = create_pmatrix(len);
    // Mark all strings of length 1 as palindormic.
    for (int i = 0; i < len; i++)
    {
        pmatrix_mark(p, i, i);
    }
    // Mark all strings of length 2 as palindormic if they are equal.
    for (int i = 0; i < len - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            pmatrix_mark(p, i, i + 1);
        }
    }
    // Mark remaining strings.
    for (int i = 0; i < len - 2; i++)
    {
        for (int j = i + 2; j < len; j++)
        {
            if (str[i] == str[j] && pmatrix_query(p, i + 1, j - 1))
            {
                pmatrix_mark(p, i, j);
            }
        }
    }
    int count = p->sum;
    destroy_pmatrix(p);
    return count;
}

int main(void)
{
    // Switch to fully buffered stdout.
    setvbuf(stdout, NULL, _IOFBF, 0);
    int n;
    char string[11];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", string);
        printf("%d\n", palindormic_count(string));
    }
    return 0;
}