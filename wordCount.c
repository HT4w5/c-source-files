#include <stdio.h>

int main(void)
{
    char c;
    while (1)
    {
        while ((c = getchar()) == ' ')
            ;
        while ((c = getchar()) != ' ' || c >= 32)
            ;
        
    }
}