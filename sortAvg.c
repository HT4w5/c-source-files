#include <stdio.h>

int main()
{
    int n, k, n_a = 0, n_b = 0, sum_a = 0, sum_b = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            n_a++;
            sum_a += i;
        }
        else
        {
            n_b++;
            sum_b += i;
        }
    }
    printf("%.1f %.1f", sum_a * 1.0 / n_a, sum_b * 1.0 / n_b);
    return 0;
}