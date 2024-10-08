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

int main()
{
    int n, length, sum = 0;
    scanf("%d", &n);
    length = getLength(n);
    for(int i = 1; i <= length; i++)
    {
        sum += getOnes(n) * pow(10, (length - i));
        n /= 10;
    }
    printf("%d",sum);
    return 0;
}