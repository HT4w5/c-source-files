#include <stdio.h>
#include <string.h>
#define PRECISION 60

typedef struct
{
    int length;
    int sign;
    char value[PRECISION];
} bigInt;

void zeroInit(bigInt *tgt, int digits)
{
    for (int i = 0; i < digits; i++)
    {
        tgt->value[i] = 0;
    }
}

bigInt createBigInt(void)
{
    bigInt a;
    a.length = 0;
    a.sign = 0;
    return a;
}

bigInt readBigInt(void)
{
    bigInt result = createBigInt();
    char input[PRECISION + 2];
    // char len;
    scanf("%s", &input);
    if (input[0] == '-')
    {
        result.sign = 1;
        result.length = strlen(input) - 1;
        for (int i = 0; i < result.length; i++)
        {
            result.value[i] = input[result.length - i] - '0';
        }
    }
    else
    {
        result.length = strlen(input);
        for (int i = 0; i < result.length; i++)
        {
            result.value[i] = input[result.length - i - 1] - '0';
        }
    }
    return result;
}

void printBigInt(bigInt out)
{
    if (out.sign)
    {
        putchar('-');
    }
    for (int i = out.length - 1; i >= 0; i--)
    {
        putchar(out.value[i] + '0');
    }
}

bigInt bigAdd(bigInt a, bigInt b)
{
    bigInt sum = createBigInt();
    int lL, gL;
    // Determine greater and lesser lengths.
    if (a.length > b.length)
    {
        gL = a.length;
        lL = b.length;
    }
    else
    {
        lL = a.length;
        gL = b.length;
    }
    zeroInit(&sum, gL);
    // Add a.
    if (a.sign)
    {
        for (int i = 0; i < a.length; i++)
        {
            sum.value[i] -= a.value[i];
        }
    }
    else
    {
        for (int i = 0; i < a.length; i++)
        {
            sum.value[i] += a.value[i];
        }
    }

    // Add b.
    if (b.sign)
    {
        for (int i = 0; i < b.length; i++)
        {
            sum.value[i] -= b.value[i];
        }
    }
    else
    {
        for (int i = 0; i < b.length; i++)
        {
            sum.value[i] += b.value[i];
        }
    }

    // Process carry
    for (int i = 0; i < PRECISION; i++)
    {
        if (sum.value[i] > 9)
        {
            sum.value[i] -= 10;
            sum.value[i + 1] += 1;
        }
    }
    for (int i = PRECISION - 1; i >= 0; i--)
    {
        if (sum.value[i] < 0)
        {
            sum.value[i] -= 10;
            sum.value[i + 1] += 1;
        }
    }
}

int main(void)
{
    bigInt a = readBigInt();
    printBigInt(a);
    return 0;
}