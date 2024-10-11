#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRECISION 60

typedef struct
{
    int length;
    char value[PRECISION];
} bigInt;

bigInt add(bigInt a, bigInt b)
{
    bigInt *greater = a.length > b.length ? &a : &b;
    bigInt *lesser = a.length < b.length ? &a : &b;
    bigInt bigSum;
    bigSum.length = 0;
    int digit = 0;
    int sum, carry = 0;
    for (int i = 1; i <= lesser->length; i++)
    {
        sum = a.value[digit] + b.value[digit] + carry - 96;
        if (sum > 9)
        {
            carry = 1;
            sum -= 10;
        }
        else
        {
            carry = 0;
        }
        bigSum.value[digit] = sum + 48;
        digit++;
    }
    for (int i = 1; i <= greater->length - lesser->length; i++)
    {
        sum = greater->value[digit] + carry - 48;
        if (sum > 9)
        {
            carry = 1;
            sum -= 10;
        }
        else
        {
            carry = 0;
        }
        bigSum.value[digit] = sum + 48;
        digit++;
    }
    if (carry == 1)
    {
        bigSum.value[++digit] = '1';
    }
    bigSum.length = digit + 1;
    return bigSum;
}

int main()
{
    // int n;
    // scanf("%d", &n);

    bigInt a;
    a.length = 5;
    a.value[0] = '1';
    a.value[1] = '2';
    a.value[2] = '3';
    a.value[3] = '4';
    a.value[4] = '5';

    bigInt b;
    b.length = 3;
    b.value[0] = '3';
    b.value[1] = '9';
    b.value[2] = '4';

    
}