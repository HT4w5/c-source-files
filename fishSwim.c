#include<stdio.h>

int main()
{
    int x, d, r;
    scanf("%d%d",&x,&d);
    r = d % 7;
    d = (d / 7) * 5;
    //simulate
    for(int i = 0; i <= r; i ++)
    {
        switch(x + i)
        {
            case 1 ... 5:
                d ++;
                break;
            case 7:
                x -= 7;
            case 6:
                break;
        }
    }
    printf("%d", d);
    return 0;
}