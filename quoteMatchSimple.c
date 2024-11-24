#include <stdio.h>

#define MAX_EXP_LEN 20

int main(void)
{
    char stack[MAX_EXP_LEN + 1];
    int stack_i = 0;

    // Input expression.
    char buf;

    while ((buf = getchar()) >= ' ') // ASCII larger than space character.
    {
        if (buf == '(' || buf == '[' || buf == '{')
        {
            stack[stack_i] = buf;
            stack_i++;
        }
        else
        {
            // When right hand quote found.
            if (buf == ')')
            {
                if (stack[stack_i - 1] != '(')
                {
                    printf("no");
                    return 0;
                }
                stack_i--;
            }
            else if (buf == ']')
            {
                if (stack[stack_i - 1] != '[')
                {
                    printf("no");
                    return 0;
                }
                stack_i--;
            }
            else if (buf == '}')
            {
                if (stack[stack_i - 1] != '{')
                {
                    printf("no");
                    return 0;
                }
                stack_i--;
            }
        }
    }

    // Check whether stack is empty.
    if (stack_i == 0)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }

    return 0;
}