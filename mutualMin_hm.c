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

int main(void)
{
    int m, n, buffer;
    scanf("%d %d", &m, &n);
    hash_map_t *map = hash_map_create();
    int *arr2 = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &buffer);
        hash_map_insert(map, buffer);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (hash_map_query(map, arr2[i]) == 1)
        {
            printf("%d", arr2[i]);
            return 0;
        }
    }
    printf("-1");

    return 0;
}