#include<stdio.h>

void swap(int * n1, int * n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

int getMin(int num[])
{
    int min = 1;
    for(int i = 0; i <= 2; i++)
    {
        for(int j = i; j <= 2; j++)
        {
            if(num[i] > num[j])
            {
                swap(&num[i], &num[j]);
            }
        }
    }
    return num[0];
}


int main()
{
    int n, a, b, price[3];
    scanf("%d",&n);
    for(int i = 0; i <= 2; i++)
    {
        scanf("%d%d",&a,&b);
        price[i] = ((n - 1) / a + 1) * b;
        //printf("%d%d%d",price[0],price[1],price[2]);
    }
    printf("%d",getMin(price));
    return 0;
}