#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    char value;
    struct lnode *next;
} lnode_t;

typedef struct cstack
{
    int length;
    lnode_t *head;
} cstack_t;

void lnode_init(lnode_t **tgt)
{
    *tgt = (lnode_t *)malloc(sizeof(lnode_t));
    (*tgt)->value = 0;
    (*tgt)->next = NULL;
}

void cstack_init(cstack_t **tgt)
{
    *tgt = (cstack_t *)malloc(sizeof(cstack_t));
    (*tgt)->head = NULL;
    (*tgt)->length = 0;
}

void cstack_push(cstack_t *tgt, char c)
{
    lnode_t *node;
    lnode_init(&node);
    if (tgt->head == NULL)
    {
        node->next = NULL;
        tgt->head = node;
    }
    else
    {
        node->next = tgt->head;
        tgt->head = node;
    }
    tgt->length++;
    tgt->head->value = c;
}

char cstack_pop(cstack_t *tgt)
{
    if (tgt->head != NULL)
    {
        char c = tgt->head->value;
        lnode_t *head = tgt->head;
        tgt->head = tgt->head->next;
        free(head);
        return c;
    }
    else
    {
        return '0';
    }
}

void cstack_destroy(cstack_t *tgt)
{
    while (tgt->head != NULL)
    {
        lnode_t *head = tgt->head;
        tgt->head = tgt->head->next;
        free(head);
    }
    free(tgt);
}

int main(void)
{
    char c;
    cstack_t *quote_stack;
    cstack_init(&quote_stack);

    while ((c = getchar()) >= 32)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            cstack_push(quote_stack, c);
        }
        else
        {
            switch (c)
            {
            case ')':
                if (cstack_pop(quote_stack) != '(')
                {
                    printf("no");
                    return 0;
                }
                break;

            case ']':
                if (cstack_pop(quote_stack) != '[')
                {
                    printf("no");
                    return 0;
                }
                break;

            case '}':
                if (cstack_pop(quote_stack) != '{')
                {
                    printf("no");
                    return 0;
                }
                break;

            default:
                break;
            }
        }
    }

    printf("yes");
    return 0;
}