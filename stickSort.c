#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, maxCirc = 0, Circ;
    scanf("%d", &n);
    int *sticks = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", sticks + i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (*(sticks + i) + *(sticks + j) > *(sticks + k) && *(sticks + i) + *(sticks + k) > *(sticks + j) && *(sticks + j) + *(sticks + k) > *(sticks + i))
                {
                    Circ = *(sticks + i) + *(sticks + j) + *(sticks + k);
                    if (Circ > maxCirc)
                    {
                        maxCirc = Circ;
                    }
                }
            }
        }
    }

    free(sticks);
    
    printf("%d", maxCirc);
    return 0;
}