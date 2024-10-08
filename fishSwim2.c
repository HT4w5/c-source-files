#include<stdio.h>

int main()
{
    unsigned long long int n, sum = 0;
    unsigned short int x;
    scanf("%d%d",&x,&n);
    while(n > 0)
    {
        if(!(x == 6 || x == 7))
        {
            sum += 1;
        }
        if(x == 7)
        {
            x = 1;
        }
        else
        {
            x ++;
        }
        n --;
    }
    printf("%d",250 * sum);
    return 0;

}