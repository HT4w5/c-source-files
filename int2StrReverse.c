#include <stdio.h>
#include <string.h>

void uint_to_str_recursive(int a, char *str, int k)
{
    int ones;
    ones = a - (a / 10) * 10;
    str[k] = ones + '0';
    a /= 10;
    if (a == 0)
    {
        str[k + 1] = '\0';
        return;
    }
    else
    {
        uint_to_str_recursive(a, str, k + 1);
    }
}

void uint_to_str(int a, char *str)
{
    uint_to_str_recursive(a, str, 0);
}

int main(void)
{
    int a;
    scanf("%d", &a);
    // Declare enough characters for int and null terminator.
    char str[11];
    uint_to_str(a, str);
    printf("%s", str);
    return 0;
}
