#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *str = (char *)malloc(sizeof(char) * 51);
    char *subStr = (char *)malloc(sizeof(char) * 51);
    int count;
    // Get str.
    for (int i = 0; 1; i++)
    {
        if ((str[i] = getchar()) < 32)
        {
            if (str[i] == '\r')
            {
                getchar();
            }
            str[i] = '\0';
            break;
        }
    }

    // Get subStr.
    for (int i = 0; 1; i++)
    {
        if ((subStr[i] = getchar()) < 32)
        {
            subStr[i] = '\0';
            break;
        }
    }

    // Determine count.
    char *strPtr = str, *subStrPtr;

    subStrPtr = subStr;
    do
    {
        if (*subStrPtr != *strPtr)
        {
            if (*subStrPtr == '\0')
            {
                count++;
            }
            else
            {
                strPtr++;
            }
            subStrPtr = subStr;
        }
        else
        {
            subStrPtr++;
            strPtr++;
        }
    } while (*strPtr != '\0');

    if (*subStrPtr == *strPtr)
    {
        count++;
    }

    // Print result.
    printf("%d", count);
    free(str);
    free(subStr);
    return 0;
}