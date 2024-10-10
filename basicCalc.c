#include<stdio.h>

int s1, s3;
char s2;

int getCommand()
{
    s1 = -1;
    scanf("%d", &s1);
    if(s1 == -1)
    {
        s1 = getchar();
        if(s1 == 113)
        {
            return 1;
        }
        //return 1;
    }
    s2 = getchar();
    scanf("%d", &s3);
    return 0;
}

int calc(int s1, char s2, int s3)
{
    switch(s2)
    {
        case '+':
            return s1 + s3;
            break;

        case '-':
            return s1 - s3;
            break;
        
        case '*':
            return s1 * s3;
            break;

        case '/':
            return s1 / s3;
            break;
    }
}

int main()
{
    //getCommand();
    while(1)
    {
        if(getCommand() == 1)
        {
            return 0;
        }
        printf("%d\n", calc(s1, s2, s3));
    }
}