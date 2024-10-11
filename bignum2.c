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
    for (int i = len - 1; i >= 0; i--)
    {
        putchar(big[i]);
    }
}

void bigAdd(bigInt a, bigInt b, bigInt *out)
{
    clear(out);
    for (int i = 0; i < PRECISION; i++)
    {
        (*out)[i] = a[i] + b[i] - '0';
        if ((*out)[i] > '9')
        {
            (*out)[i] -= 10;
            (*out)[i + 1] += 1;
        }
    }
}

int main()
{
    bigInt a, b, sum;
    readbigInt(&a);
    readbigInt(&b);
    bigAdd(a, b, &sum);
    printbigInt(sum);
    return 0;
}