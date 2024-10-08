#include<stdio.h>

int main()
{
    int n, dayInWeek = 1, dayInMth = 1;
    scanf("%d", &n);

    //print title
    printf("mon tue wed thu fri sat sun\n");

    for(int i = 1; i <= n - 1; i++)
    {
        printf("   -");
        dayInWeek++;
        //dayInMth++;
    }
    while(dayInMth <= 31)
    {
        printf("%4d", dayInMth);
        if(dayInWeek == 7)
        {
            printf("\n");
            dayInWeek = 0;
        }
        dayInMth++;
        dayInWeek++;
    }
    return 0;
}