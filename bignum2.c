#include <stdio.h>
#include <string.h>
#define PRECISION 60

typedef char bigInt[PRECISION + 1];

void clear(bigInt *ptr)
{
    for (int i = 0; i < PRECISION + 1; i++)
    {
        (*ptr)[i] = 0; // Fill up with zero.
    }
}

void readbigInt(bigInt *ptr)
{
    static char buffer[PRECISION + 1];
    scanf("%s", &buffer);
    clear(ptr);
    // Reverse string.
    int len = strlen(buffer);
    for (int i = 0; i < len; i++)
    {
        (*ptr)[i] = buffer[len - i - 1];
    }
    (*ptr)[len] = '\0';
}

void printbigInt(bigInt big)
{
    int len = strlen(big);
    for(int i=len-1;i>=0;i--)
    {
        putchar(big[i]);
    }
}

int main()
{
    bigInt a;
    readbigInt(&a);
    printbigInt(a);
    return 0;
}