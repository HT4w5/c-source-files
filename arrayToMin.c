#include <stdio.h>

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void arrSort5(int *arr)
{
    // Bubble sort.
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr + i, arr + j);
            }
        }
    }
}

int toMin(int num)
{
    int length = 0, digits[5] = {9, 9, 9, 9, 9}, min = 0;
    // Split digits.
    for (int i = 0; num != 0; i++)
    {
        digits[i] = num - num / 10 * 10;
        ++length;
        num /= 10;
    }
    // Sort digits.
    arrSort5((int *)digits);

    // Compose num.
    for (int i = 0; i < length; i++)
    {
        min += digits[0];
        min *= 10;
    }
    return min / 10;
}

int main(void)
{
    int n, num, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        sum += toMin(num);
    }

    printf("%d", sum);
    return 0;
}