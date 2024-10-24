#include <stdio.h>

int main(void)
{
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if (c == '\n')
        {
            printf("LF");
        }
        else if (c == '\r')
        {
            printf("CR");
        }
        else
        {
            printf("%c", c);
        }
    }
    return 0;
}