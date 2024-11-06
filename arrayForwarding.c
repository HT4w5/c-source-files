#include <stdio.h>
#include <stdlib.h>

typedef struct RingNode
{
    int val;
    struct RingNode *next;
    struct RingNode *prev;
} ring_node_t;

typedef struct Ring
{
    ring_node_t *head;
} ring_t;

ring_node_t *create_ring_node()
{
    ring_node_t *node = (ring_node_t *)malloc(sizeof(ring_node_t));
    node->val = 0;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

ring_t *create_ring()
{
    ring_t *ring = (ring_t *)malloc(sizeof(ring_t));
    ring->head = NULL;
    return ring;
}

void ring_append(ring_t *ring, int val)
{
    if (ring == NULL)
    {
        perror("NULL ring pointer");
        exit(1);
    }
    if (ring->head == NULL)
    {
        ring->head = create_ring_node();
        ring->head->val = val;
        ring->head->next = ring->head;
        ring->head->prev = ring->head;
    }
    else
    {
        ring_node_t *new_node = create_ring_node();
        new_node->val = val;
        new_node->next = ring->head;
        new_node->prev = ring->head->prev;
        ring->head->prev->next = new_node;
        ring->head->prev = new_node;
        ring->head = new_node;
    }
}

void ring_forward(ring_t *ring)
{
    if (ring == NULL)
    {
        perror("NULL ring pointer");
        exit(1);
    }
    if (ring->head == NULL)
    {
        printf("Ring is empty\n");
        return;
    }
    else
    {
        ring->head = ring->head->next;
    }
}

void ring_backward(ring_t *ring)
{
    if (ring == NULL)
    {
        perror("NULL ring pointer");
        exit(1);
    }
    if (ring->head == NULL)
    {
        printf("Ring is empty\n");
        return;
    }
    else
    {
        ring->head = ring->head->prev;
    }
}

void ring_destroy(ring_t *ring)
{
    if (ring == NULL)
    {
        perror("NULL ring pointer");
    }
    else
    {
        if (ring->head == NULL)
        {
            free(ring);
            return;
        }
        else
        {
            ring_node_t *last = ring->head->prev;
            while (ring->head != last)
            {
                ring_node_t *temp = ring->head;
                ring->head = ring->head->next;
                free(temp);
            }
            free(ring);
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    ring_t *ring = create_ring();
    for (int i = 0; i < n; i++)
    {
        int buffer;
        scanf("%d", &buffer);
        ring_append(ring, buffer);
    }

    int offset;
    scanf("%d", &offset);
    for (int i = 0; i < offset; i++)
    {
        ring_forward(ring);
    }

    // Print result.
    for (int i = 0; i < n; i++)
    {
        ring_backward(ring);
        printf("%d", ring->head->val);
        if (i != n - 1)
        {
            printf(" ");
        }
    }

    ring_destroy(ring);
    return 0;
}