#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, start, des, cwDist = 0, ccwDist = 0, totalDist = 0;
    scanf("%d%d%d", &n, &start, &des);
    int *stops = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", stops + i);
        totalDist += *(stops + i);
    }

    if (start < des)
    {
        for (int i = start; i < des; i++)
        {
            cwDist += *(stops + i);
        }
        ccwDist = totalDist - cwDist;
    }
    else if (start > des)
    {
        for (int i = des; i < start; i++)
        {
            ccwDist += *(stops + i);
        }
        cwDist = totalDist - ccwDist;
    }
    free(stops);

    printf("%d", cwDist > ccwDist ? ccwDist : cwDist);
    return 0;
}