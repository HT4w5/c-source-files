#include<stdio.h>

int main(void)
{
    char c;
    for(c = getchar(); c != EOF; c = getchar())
    {
        printf("%c",c);
    }
    return 0;
}