#include<stdio.h>
#include<stdlib.h>

void swap(int*a,int*b)
{
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

int main()
{
    int n;
    scanf("%d",&n);
    int*num=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",num+i);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(*(num+i)>*(num+j))
            {
                swap(num+i,num+j);
            }
        }
    }
    printf("%d",*num);
    free(num);
    return 0;

}