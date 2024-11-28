#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], size_t len, int tgt);

int main(void)
{
    printf("Enter array size:\n");
    size_t nmemb;
    if (scanf("%d", &nmemb) <= 0)
    {
        perror("Invalid input");
        exit(EXIT_FAILURE);
    }

    printf("Enter target:\n");
    int tgt;
    if (scanf("%d", &tgt) <= 0)
    {
        perror("Invalid input");
        exit(EXIT_FAILURE);
    }

    // Input array.
    printf("Enter acsending integer array:\n");
    int arr[nmemb];
    for (size_t i = 0; i < nmemb; ++i)
    {
        if (scanf("%d", &arr[i]) <= 0)
        {
            perror("Invalid input");
            exit(EXIT_FAILURE);
        }
    }

    int result = binary_search(arr, nmemb, tgt);

    // Print result.
    if (result < 0)
    {
        printf("Target not found");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Target found. Index: %d", result);
        exit(EXIT_SUCCESS);
    }
}

int binary_search(int arr[], size_t len, int tgt)
{
    size_t lowi = 0, highi = len - 1, mid = 0;

    int guess;

    while (lowi <= highi) // When lowi == highi, there are still two elements in array.
    {
        mid = (lowi + highi) / 2;
        guess = arr[mid];
        if (guess == tgt)
        {
            return mid;
        }
        else if (guess < tgt)
        {
            lowi = mid + 1;
        }
        else
        {
            highi = mid - 1;
        }
    }
    return -1;
}