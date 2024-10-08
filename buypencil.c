#include<stdio.h>

void swap(int * n1, int * n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

void sort(int * num[3])
{
    for(int i = 0; i <= 2; i++)
    {
        for(int j = i + 1; j <= 2; j++)
        {
            //printf("num: %d %d ",*num[i],*num[j]);
            if(*num[i] > *num[j])
            {
                swap(num[i],num[j]);
            }
        }
    }
}

int main()
{
    int n, a, b, price[3];
    scanf("%d",&n);
    for(int i = 0; i <= 2; i++)
    {
        scanf("%d%d",&a,&b);
        price[i] = ((n - 1) / a + 1) * b;
        printf("%d%d%d",price[0],price[1],price[2]);
    }
    sort(price);
    printf("%d",price[0]);
    return 0;
}