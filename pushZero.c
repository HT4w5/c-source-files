#include <stdio.h>

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void pushZero(int *arr, int length)
{
    int *ptr = arr;
    int *subPtr = NULL;
    for (int i = 0; i < length; ++i)
    {
        if (*ptr != 0)
        {
            ptr++;
        }
        else
        {
            if (ptr == arr)
            {
                ptr++;
                break;
            }
            subPtr = ptr - 1;
            while (*subPtr != 0)
            {
                if (subPtr == arr)
                {
                    break;
                }
                subPtr--;
            }
            swap(ptr, subPtr + 1);
            ptr++;
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num[i]);
    }
    pushZero((int *)num, n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d", num[i]);
        if (i != n - 1)
        {
            printf(" ");
        }
    }
    return 0;
}