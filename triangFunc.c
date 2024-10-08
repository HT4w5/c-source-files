#include<stdio.h>

int numden(int a, int b)
{
    int r;
    r = a > b ? b : a;
    while(1)
    {
        if(a % r == 0 && b % r == 0)
        {
            break;
        }
        r --;
    }
    return r;
}

void swap(int * n1, int * n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

void sort3(int * n1, int * n2, int * n3)
{
    int n[3];
    n[0] = *n1;
    n[1] = *n2;
    n[2] = *n3;

    for(int i = 0; i <= 2; i++)
    {
        for(int j = i; j <= 2; j ++)
        {
            if(n[i] < n[j])
            {
                swap(&n[i], &n[j]);
            }
        }
    }
    *n1 = n[0];
    *n2 = n[1];
    *n3 = n[2];
}

int main(void)
{
    int a, b, c, r;
    scanf("%d%d%d", &a, &b, &c);
    sort3(&a, &b, &c);
    r = numden(a, c);
    c /= r;
    a /= r;
    printf("%d/%d", c, a);
    return 0;
}