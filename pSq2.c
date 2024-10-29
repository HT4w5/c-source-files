#include <stdio.h>
#include <limits.h>

int minSqFactorCount(int num)
{
    int dp[num + 1];

    // Initiate dp with INT_MAX
    for (int i = 1; i <= num; ++i)
    {
        dp[i] = INT_MAX;
    }

    dp[0] = 0; // 0 squares for 0.

    // Find min square.
    for (int i = 1; i <= num; ++i)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (dp[i - j * j] + 1 < dp[i])
            {
                dp[i] = dp[i - j * j] + 1;
            }
        }
    }

    return dp[num];
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", minSqFactorCount(n));
    return 0;
}
