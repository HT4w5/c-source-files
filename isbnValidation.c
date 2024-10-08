#include<stdio.h>

int main()
{
    int n[9], sum = 0;
    char chksum;
    scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5], &n[6], &n[7], &n[8], &chksum);

    //calculate chksum
    for(int i = 1; i <= 9; i ++)
    {
        sum += i * n[i - 1];
    }
    sum %= 11;
    if(sum == 10)
    {
        sum = 88;
    }
    else
    {
        sum += 48;
    }
    

    //validate chksum
    if(((int) chksum) == sum)
    {
        printf("Right");
    }
    else
    {
        printf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c", n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], sum);
    }
    return 0;
}