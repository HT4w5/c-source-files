#include<stdio.h>

int main()
{
    char c;
    int l = 0, n = 0, s = 0, o = 0;
    while(1)
    {
        c = getchar();
        if(c == '\n' || c == '\r')
        {
            break;
        }
        switch(c)
        {
            case 65 ... 90:
            case 97 ... 122:
                l++;
                break;

            case 48 ... 57:
                n++;
                break;

            case 32:
                s++;
                break;
            
            default:
                o++;
                break;
        }
    }
    printf("%d %d %d %d", l, n, s, o);

    return 0;
}