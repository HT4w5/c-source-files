#include<stdio.h>

int main()
{
    int w;
    float p = 0;
    scanf("%d", &w);
    p += w * 0.03;
    w -= 200000;
    if(w > 0)
    {
        p -= w * 0.005;
        w -= 300000;
        if(w > 0)
        {
            p -= w * 0.005;
        }
    }
    printf("%.3f",p);
    return 0;

}