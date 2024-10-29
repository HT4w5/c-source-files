#include <stdio.h>

int getMaxScore(int score[], int n)
{
    int tScore = 0, maxTScore = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            tScore = score[i] + score[j] + i - j;
            if (maxTScore < tScore)
            {
                maxTScore = tScore;
            }
        }
    }

    return maxTScore;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int score[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &score[i]);
    }
    printf("%d", getMaxScore(score, n));
    return 0;
}