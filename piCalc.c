#include<stdio.h>

int main()
{
    double eps, n = 0;
    scanf("%lf", &eps);
    for(int i = 1; 1.0 / (2 * i - 1) >= eps; i++)
    {
        n = i % 2 ? n + 1.0 / (2 * i - 1) : n - 1.0 / (2 * i - 1);
    }
    printf("%.8lf", n * 4);
    return 0;
}