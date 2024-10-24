#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

typedef struct
{
    int size;
    int count;
    char **denom;
} point_map_t;

point_map_t *point_map_init(int n)
{
    point_map_t *new_map = (point_map_t *)malloc(sizeof(point_map_t));
    new_map->size = n;
    new_map->count = 0;
    new_map->denom = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        new_map->denom[i] = (char *)malloc(sizeof(char) * n);
        memset(new_map->denom[i], 0, sizeof(char) * n);
    }
    return new_map;
}

void point_map_append(point_map_t *map, int denom, int num)
{
    int gcd1 = gcd(denom, num);
    denom /= gcd1;
    num /= gcd1;

    if (*(map->denom[denom - 1] + num - 1) == 0)
    {
        *(map->denom[denom - 1] + num - 1) = 1;
        map->count++;
    }
}

void point_map_destroy(point_map_t *map)
{
    for (int i = 0; i < map->size; i++)
    {
        free(map->denom[i]);
    }
    free(map);
}

int getPoint(int N)
{
    point_map_t *map1 = point_map_init(N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            point_map_append(map1, i, j);
        }
    }
    int count = map1->count * 8;
    point_map_destroy(map1);
    return count;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    printf("%d", getPoint(N));
    return 0;
}