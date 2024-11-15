#include <stdio.h>
#include <stdlib.h>

typedef struct CharStackNode
{
    char value;
    struct CharStackNode *next;
} csnode_t;

typedef struct CharStack
{
    csnode_t *head;
    unsigned int len;
} cstack_t;

csnode_t *create_csnode()
{
    csnode_t *new_node = (csnode_t *)malloc(sizeof(csnode_t));
    new_node->value = '\0';
    new_node->next = NULL;
    return new_node;
}

cstack_t *create_cstack()
{
    cstack_t *new_stack = (cstack_t *)malloc(sizeof(cstack_t));
    new_stack->head = NULL;
    new_stack->len = 0;
    return new_stack;
}

void cstack_push(cstack_t *stack, char value)
{
    if (stack != NULL)
    {
        csnode_t *new_node = create_csnode();
        new_node->next = stack->head;
        new_node->value = value;
        stack->head = new_node;
        stack->len++;
    }
    else
    {
        perror("Stack not initialized");
        exit(EXIT_FAILURE);
    }
}

char cstack_pop(cstack_t *stack)
{
    if (stack != NULL)
    {
        if (stack->head == NULL)
        {
            return '\0';
        }
        else
        {
            char value = stack->head->value;
            csnode_t *new_head = stack->head->next;
            free(stack->head);
            stack->head = new_head;
            stack->len--;
            return value;
        }
    }
    else
    {
        perror("Stack not initialized");
        exit(EXIT_FAILURE);
    }
}

void cstack_destroy(cstack_t *stack)
{
    if (stack != NULL)
    {
        if (stack->head == NULL)
        {
            free(stack);
            return;
        }
        else
        {
            csnode_t *curr_node = NULL;
            while (stack->head != NULL)
            {
                curr_node = stack->head;
                stack->head = stack->head->next;
                free(curr_node);
            }
            return;
        }
    }
    else
    {
        perror("Stack not initialized");
        exit(EXIT_FAILURE);
    }
}

void exit_with_result(const char result)
{
    printf("%c", result);
    exit(EXIT_SUCCESS);
}

int main(void)
{
    // Create stacks to store strings.
    cstack_t *str1 = create_cstack();
    cstack_t *str2 = create_cstack();

    // Input strings.
    char buf;
    while ((buf = getchar()) >= ' ')
    {
        if (buf == '#')
        {
            cstack_pop(str1);
        }
        else
        {
            cstack_push(str1, buf);
        }
    }

    // Discard LF.
    getchar();

    while ((buf = getchar()) >= ' ')
    {
        if (buf == '#')
        {
            cstack_pop(str2);
        }
        else
        {
            cstack_push(str2, buf);
        }
    }

    // Compare strings.
    if (str1->len == str2->len)
    {
        int len = str1->len;
        for (int i = 0; i < len; i++)
        {
            if (cstack_pop(str1) != cstack_pop(str2))
            {
                exit_with_result('N');
            }
        }
        exit_with_result('Y');
    }
    else
    {
        exit_with_result('N');
    }
}