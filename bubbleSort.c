// bubbleSort.c: implemention of bubble sort.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*compar_fn_t)(const void *, const void *);

void bsort(void *base, size_t nmemb, size_t size, __compar_fn_t compar);
void memswap(void *dest, void *src, size_t size);
int int_compare(const void *a, const void *b);

int main(void)
{
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    bsort(nums, n, sizeof(int), int_compare);
    for (int i = 0; i < n; i++)
    {
        printf("%d", nums[i]);
    }
    return 0;
}

/**
 * Bubble sort any array according to compare function.
 *
 * @param base Pointer to array.
 * @param nmemb Number of members in array.
 * @param size Size of each member in bytes.
 * @param compar Function to provide comparison. Commence swap if return value is positive.
 */
void bsort(void *base, size_t nmemb, size_t size, compar_fn_t compar)
{
    char next = 1;
    void *former = NULL;
    void *latter = NULL;
    while (next)
    {
        next = 0;
        for (int i = 0; i < nmemb; ++i)
        {
            former = base + i * size;
            latter = former + size;
            if (compar(former, latter))
            {
                memswap(former, latter, size);
                next = 1;
            }
        }
    }
}

/**
 * Swap two memory segments. Two segments must be of the same size.
 *
 * @param dest Pointer to destination segment.
 * @param src Pointer to source segment.
 * @param size Size of segments.
 */
void memswap(void *dest, void *src, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, src, size);
    memcpy(src, dest, size);
    memcpy(dest, temp, size);
    free(temp);
}

// Example function displaying usage of bsort().
int int_compare(const void *a, const void *b)
{
    int *c = NULL, *d = NULL;
    c = (int *)a;
    d = (int *)b;

    // Sort in acsending order.
    return *c - *d;
}
