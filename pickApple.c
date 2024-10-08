#include<stdio.h>

int main()
{
    int h[10], H, n = 0;
    for(int i = 0; i <= 9; i++)
    {
        scanf("%d",&h[i]);
    }
    scanf("%d",&H);
    H += 30;
    for(int i = 0; i <= 9; i++)
    {
        n += h[i] > H ? 0 : 1;
    }
    printf("%d",n);
    return 0;
}