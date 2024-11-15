#include <stdio.h>
#include <stdlib.h>
#define MAX_STR_LEN 20

int main(void)
{
    char *str1 = (char *)malloc(MAX_STR_LEN + 1);

    // Input str1.
    char buf;
    int len1 = 0;
    while ((buf = getchar()) >= ' ')
    {
        str1[len1] = buf;
        len1++;
    }
    str1[len1] = '\0';

    // Discard LF.
    getchar();

    // Input str2.
    int letter_map[26] = {0};
    while ((buf = getchar()) >= ' ')
    {
        letter_map[buf - 97]++;
    }

    for (int i = 0; i < len1; i++)
    {
        letter_map[str1[i] - 97]--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (letter_map[i] < 0)
        {
            printf("N");
            return 0;
        }
    }
    printf("Y");
    return 0;
}