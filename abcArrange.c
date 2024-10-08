#include<stdio.h>

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

int main()
{
    char ch;
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    sort3(&c, &b, &a);
    for(int i = 1; i <= 3; i ++)
    {
        scanf("\n%c",&ch);
        switch(ch)
        {
            case 'A':
                printf("%d", a);
                break;

            case 'B':
                printf("%d", b);
                break;

            case 'C':
                printf("%d", c);
                break;
        }
        printf(" ");
    }
    return 0;
}