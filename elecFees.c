#include<stdio.h>

int main()
{
    int w;
    float p = 0;
    scanf("%d", &w);
    p += w * 0.4463;
    w -= 150;
    if(w > 0)
    {
        p += w * 0.02;
        w -= 250;
        if(w > 0)
        {
            p += w * 0.1;
        }
    }
    printf("%.1f",p);
    return 0;

}