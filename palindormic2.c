#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MAP_SIZE 10007

typedef struct HashMapNode
{
    unsigned int key;
    int count;
    struct HashMapNode *next;
} hash_map_node_t;

typedef struct HashMap
{
    hash_map_node_t *nodes[HASH_MAP_SIZE];
} hash_map_t;

typedef struct LinkNode
{
    char value;
    struct LinkNode *next;
} lnode_t;

typedef struct CharStack
{
    int length;
    lnode_t *head;
} cstack_t;

unsigned int keygen(char *str)
{
    unsigned int len=strlen(str);
    return len * 31 + str[0] * 13 + str[len / 2] * 7 + str[len - 1] * 5;
}

unsigned int hash(unsigned int key)
{
    return key % HASH_MAP_SIZE;
}

hash_map_node_t *hash_map_node_create()
{
    hash_map_node_t *node = (hash_map_node_t *)malloc(sizeof(hash_map_node_t));
    memset(node, 0, sizeof(hash_map_node_t));
    return node;
}

hash_map_t *hash_map_create()
{
    hash_map_t *map = (hash_map_t *)malloc(sizeof(hash_map_t));
    memset(map, 0, sizeof(hash_map_t));
    return map;
}

void hash_map_insert(hash_map_t *map, int key)
{
    unsigned int index = hash(key);
    hash_map_node_t *newEntry = map->nodes[index];

    // Look for existing entry.
    while (newEntry != NULL)
    {
        if (newEntry->key == key)
        {
            newEntry->count++;
            return; // Entry found.
        }
        newEntry = newEntry->next;
    }

    // Create new entry.
    newEntry = hash_map_node_create();
    newEntry->key = key;
    newEntry->count = 1;
    // Insert new entry to top of chain.
    newEntry->next = map->nodes[index];
    map->nodes[index] = newEntry;
}

int hash_map_query(hash_map_t *map, int key)
{
    unsigned int index = hash(key);
    hash_map_node_t *entry = map->nodes[index];

    while (entry != NULL)
    {
        if (entry->key == key)
        {
            return entry->count;
        }
        entry = entry->next;
    }
    // Not found.
    return 0;
}

void hash_map_destroy(hash_map_t *map)
{
    // Free nodes.
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
    {
        hash_map_node_t *entry = map->nodes[i];
        if (entry == NULL)
        {
            continue;
        }
        while (entry->next != NULL)
        {
            hash_map_node_t *prev_entry = entry;
            entry = entry->next;
            free(prev_entry);
        }
        free(entry);
    }
}

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
                cstack_destroy(letters);
                return 0;
            }
        }
        cstack_destroy(letters);
        return 1;
    }
}

int palindormic_count(char *str)
{
    int len = strlen(str);
    char temp_str[11];
    int count = 0;
    hash_map_t *pd_map = hash_map_create();
    for (size_t i = 1; i <= len; ++i)
    {
        // Iterate through every string length.
        for (int j = 0; j <= len - i; ++j)
        {
            // Iterate through every substring of length i.
            memcpy(temp_str, str + j, i);
            // Null terminate string.
            temp_str[i] = '\0';
            if (hash_map_query(pd_map, keygen(temp_str)))
            {
                ++count;
            }
            else if (is_palindormic(temp_str))
            {
                hash_map_insert(pd_map, keygen(temp_str));
                ++count;
            }
        }
    }
    hash_map_destroy(pd_map);
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