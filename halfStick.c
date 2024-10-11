#include <stdio.h>

// simulate

int main()
{
    int a, count = 1;
    scanf("%d", &a);
    while (a != 1)
    {
        a /= 2;
        count++;
    }
    printf("%d", count);
    return 0;
}