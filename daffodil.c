#include<stdio.h>
#include<math.h>

int getLength(int n)
{
    int i = 0;
    while(n != 0)
    {
        i++;
        n /= 10;
    }
    return i;
}

int getOnes(int n)
{
    return n - (n / 10) * 10;
}

int daff(int n)
{
    int digits = getLength(n);
    int sum = 0;
    for(int i = 1; i <= digits; i++)
    {
        sum += pow(getOnes(n), digits);
        n /= 10;
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d",&n);
    if(n == daff(n))
    {
        printf("Y");
    }
    else
    {
        printf("N");
    }
    return 0;
}