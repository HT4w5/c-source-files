#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Structure for storing rational numbers.
 * num: numerator
 * denom: denominator
 *
 */
typedef unsigned int uint;
typedef struct Rational
{
    uint num;
    uint denom;
} rational_t;

rational_t *r_new();
rational_t *r_add(const rational_t *a, const rational_t *b);
rational_t *r_mul(const rational_t *a, const rational_t *b);
void r_numden(rational_t *r);
uint gcd(uint a, uint b);
void r_print(const rational_t *r);

int main(void)
{
    // Input rationals.
    rational_t *a = r_new();
    rational_t *b = r_new();
    scanf("%d%d%d%d", &a->num, &a->denom, &b->num, &b->denom);

    // Print results.
    rational_t *sum = r_add(a, b);
    rational_t *prod = r_mul(a, b);
    r_print(sum);
    r_print(prod);

    // Free memory.
    free(a);
    free(b);
    free(sum);
    free(prod);
    return 0;
}

rational_t *r_new()
{
    rational_t *r = (rational_t *)malloc(sizeof(rational_t));
    // If r->denom == 0 , then marked as uninitalized.
    memset(r, 0, sizeof(rational_t));
    return r;
}

rational_t *r_add(const rational_t *a, const rational_t *b)
{
    rational_t *res = r_new();
    res->num = a->num * b->denom + a->denom * b->num;
    res->denom = a->denom * b->denom;
    // Numden.
    r_numden(res);
    return res;
}

rational_t *r_mul(const rational_t *a, const rational_t *b)
{
    rational_t *res = r_new();
    res->num = a->num * b->num;
    res->denom = a->denom * b->denom;
    // Numden.
    r_numden(res);
    return res;
}

void r_numden(rational_t *r)
{
    uint d = gcd(r->num, r->denom);
    r->num = r->num / d;
    r->denom = r->denom / d;
}

uint gcd(uint a, uint b)
{
    if (a == b)
    {
        return a;
    }

    int temp;
    do
    {
        if (a < b) // Make sure a is greater.
        {
            temp = a;
            a = b;
            b = temp;
        }

        a -= b;
    } while (a != b);

    return a;
}

void r_print(const rational_t *r)
{
    printf("%d %d\n", r->num, r->denom);
}