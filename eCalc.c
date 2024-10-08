#include <stdio.h>

// factorial
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int sum = 1;
        for (int i = 1; i <= n; i++)
        {
            sum *= i;
        }
        return sum;
    }
}

int main()
{
    double eps, n = 0;
    scanf("%lf", &eps);
    for (int i = 0; 1.0 / fact(i) >= eps; i++)
    {
        n += 1.0 / fact(i);
    }
    printf("%.8lf", n);
    return 0;
}