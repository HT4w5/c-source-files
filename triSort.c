#include<stdio.h>

void swap(int * n1, int * n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

void sort(int * n1, int * n2, int * n3)
{
    int num[3] = {*n1, *n2, *n3};
    for(int i = 0; i <= 2; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            if(num[i] > num[j])
            {
                swap(&num[i], &num[j]);
            }
        }
    }
    *n1 = num[0];
    *n2 = num[1];
    *n3 = num[2];
}

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    sort(&a,&b,&c);
    //printf("%d%d%d",a,b,c);

    //begin determination
    if(a >= b + c)
    {
        printf("Not triangle\n");
    }
    else
    {
        int s;
        s = a * a - (b * b + c * c);
        if(s == 0)
        {
            printf("Right triangle\n");
        }
        else 
        {
            if(s < 0)
            {
                printf("Acute triangle\n");
            }
            else
            {
                printf("Obtuse triangle\n");
            }
            if(a == b || b == c)
            {
                printf("Isosceles triangle\n");
                if(a == c)
                {
                    printf("Equilateral triangle");
                }
            }
            
        }
    }
    return 0;
}