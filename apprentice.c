#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************
 Apprentice structure functions
******************************/

struct ApprEntry
{
    unsigned short ts;
    char name[9];
    unsigned char s1;
    unsigned char s2;
    unsigned char s3;
};

struct ApprEntry *create_appr_entry()
{
    struct ApprEntry *new_entry = (struct ApprEntry *)malloc(sizeof(struct ApprEntry));
    memset(new_entry, 0, sizeof(new_entry));
    return new_entry;
}

void parse_appr_entry(struct ApprEntry *entry)
{
    scanf("%s%d%d%d", &entry->name, &entry->s1, &entry->s2, &entry->s3);
    entry->ts = entry->s1 + entry->s2 + entry->s3;
}

int main(void)
{
    int n_appr;
    scanf("%d", &n_appr);

    // Init appr_list.
    struct ApprEntry **appr_list = (struct ApprEntry **)malloc(sizeof(struct ApprEntry *) * n_appr);
    for (int i = 0; i < n_appr; i++)
    {
        appr_list[i] = create_appr_entry();
        parse_appr_entry(appr_list[i]);
    }

    unsigned short max_ts = 0;
    unsigned char best_appr_index[100];
    memset(&best_appr_index, 255, sizeof(best_appr_index));

    // Find largest ts.
    for (int i = 0; i < n_appr; i++)
    {
        if (appr_list[i]->ts > max_ts)
        {
            max_ts = appr_list[i]->ts;
        }
    }

    // Find all apprs with largest ts.
    int appr_i_i = 0;
    for (int i = 0; i < n_appr; i++)
    {
        if (appr_list[i]->ts == max_ts)
        {
            best_appr_index[appr_i_i] = i;
            appr_i_i++;
        }
    }

    // Print results.
    struct ApprEntry *curr_entry = NULL;
    for (int i = 0; i <= appr_i_i; i++)
    {
        if (best_appr_index[i] != 255)
        {
            curr_entry = appr_list[best_appr_index[i]];
            printf("%s %d %d %d\n", curr_entry->name, curr_entry->s1, curr_entry->s2, curr_entry->s3);
        }
    }

    // Free memory.
    for (int i = 0; i < n_appr; i++)
    {
        free(appr_list[i]);
    }
    free(appr_list);
    return 0;
}