#include<stdio.h>

int main()
{
    char bit;
    int n = 0;
    for(bit = getchar(); bit != EOF; bit = getchar())
    {
        n *= 2;
        //bit = getchar();
        //printf("bit:%c\n", bit);
        if(bit == '\n')
        {
            break;
        }
        else if(bit == '1')
        {
            n += 1;
        }
    }
    //n /= 2;
    printf("%d %o", n, n);
    return 0;
}