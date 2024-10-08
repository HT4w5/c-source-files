#include<stdio.h>

void swap(int * n1, int * n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

int main()
{
    int num[100];
    for(int i = 1; i <= 5; i ++)
    {
        scanf("%d,", &num[i - 1]);
        //printf("num[%d]:%d\n", i-1, num[i - 1]);
    }
    for(int i = 1; i <= 5; i ++)
    {
        for(int j = i; j <= 5; j ++)
        {
            if(num[i - 1] < num[j - 1])
            {
                swap(&num[i - 1], &num[j - 1]);
            }
        }
    }
    printf("%d", num[0]);
    return 0;
}