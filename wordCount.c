#include <stdio.h>

int main(void)
{
    char c;
    int count = 0;
    c = getchar();
    while (1)
    {
        if (c == ' ')
        {
            c = getchar();
            continue;
        }
        else if (c < 32)
        {
            break;
        }
        else
        {
            if ((c = getchar()) == ' ' || c < 32)
            {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}