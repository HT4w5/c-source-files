#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int is_palindormic(char *str)
{
    int len = strlen(str);
    if (len == 0)
    {
        perror("Empty string.");
        return -1;
    }
    else if (len == 1)
    {
        return 1;
    }
    else
    {
        cstack_t *letters;
        cstack_init(&letters);
        int i = 0;
        for (; i < len / 2; ++i)
        {
            cstack_push(letters, str[i]);
        }
        if (len / 2 * 2 != len)
        {
            ++i;
        }
        for (; i < len; ++i)
        {
            if (cstack_pop(letters) != str[i])
            {
                return 0;
            }
        }
        return 1;
    }
}

int palindormic_count(char *str)
{
    int len = strlen(str);
    char temp_str[11];
    int count = 0;
    for (size_t i = 1; i <= len; ++i)
    {
        // Iterate through every string length.
        for (int j = 0; j <= len - i; ++j)
        {
            // Iterate through every substring of length i.
            memcpy(temp_str, str + j, i);
            // Null terminate string.
            temp_str[i] = '\0';
            if (is_palindormic(temp_str))
            {
                ++count;
            }
        }
    }
    return count;
}

int main(void)
{
    // Switch to fully buffered stdout.
    setvbuf(stdout, NULL, _IOFBF, 0);
    int n;
    char string[11];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", string);
        printf("%d\n", palindormic_count(string));
    }
    return 0;
}