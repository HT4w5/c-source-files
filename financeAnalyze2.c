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

int get_month(int n, int t)
{
    int count = 0, income = 0;

    // Initialize hashmap.
    hash_map_t *prefix_map = hash_map_create();

    // Insert zero for later iterations.
    hash_map_insert(prefix_map, 0);

    int current_sum = 0, max_sum = 0;

    for (int i = 0; i < n; ++i)
    {
        // Calculate current sum.
        scanf("%d", &income);
        current_sum += income;
        if (current_sum > max_sum)
        {
            max_sum = current_sum;
        }

        // Calculate valid segments.
        for (int j = current_sum - t + 1; j <= max_sum; ++j)
        {
            count += hash_map_query(prefix_map, j);
        }

        // Store sum in hashmap.
        hash_map_insert(prefix_map, current_sum);
    }

    hash_map_destroy(prefix_map);

    return count;
}

int main(void)
{
    int n, t;
    scanf("%d%d", &n, &t);
    /*int *incomes = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", incomes + i);
    }*/
    printf("%d", get_month(n, t));
    // free(incomes);
    return 0;
}