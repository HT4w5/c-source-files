#include <stdio.h>

void quick_sort(int *arr, size_t len);
int *get_pivot(const int *arr, size_t *len);
void int_swap(int *a, int *b);

int main(void)
{
    size_t len;
    scanf("%d", &len);

    int arr[len];

    for (size_t i = 0; i < len; ++i)
    {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, len);

    for (size_t i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quick_sort(int *arr, size_t len)
{
    int *low = arr;
    int *high = arr + len - 1;

    int_swap(low, get_pivot(arr, len));

    while(low<high)
    {
        low++;
        while()
    }
}