#include <stdio.h>
#include <string.h>

typedef struct Record
{
    char name[20];
    int score;
} record_t;

typedef unsigned int uint;

void swap_record(record_t *a, record_t *b);
int is_present(record_t records[], const char *name);
uint read_record_entry(record_t records[], int index);
void sort_record(record_t records[], uint size);
void print_record_entry(record_t record);

int main(void)
{
    uint n_ent = 0, n_rec = 0;
    scanf("%d", &n_ent);
    record_t records[20];
    memset(&records, 0, sizeof(records));


    for (uint i = 0; i < n_ent; i++)
    {
        n_rec += read_record_entry(records, n_rec);
    }

    sort_record(records, n_rec);

    for (uint i = 0; i < n_rec; i++)
    {
        print_record_entry(records[i]);
    }

    return 0;
}

void swap_record(record_t *a, record_t *b)
{
    record_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int is_present(record_t records[], const char *name)
{
    for (int i = 0; records[i].name[0] != '\0'; i++)
    {
        if (strcmp(records[i].name, name)==0)
        {
            return i;
        }
    }
    return -1;
}

uint read_record_entry(record_t records[], int index)
{
    char name[20];
    int score, ent_i;
    scanf("%s%d", name, &score);
    ent_i = is_present(records, name);
    if (ent_i < 0)
    {
        strcpy(records[index].name, name);
        records[index].score = score;
        return 1;
    }
    else
    {
        records[ent_i].score += score;
        return 0;
    }
}

void sort_record(record_t records[], uint size)
{
    // Use bubble sort to achieve stable sort.
    for (uint i = 0; i < size - 1; i++)
    {
        for (uint j = i + 1; j < size; j++)
        {
            if (records[i].score < records[j].score)
            {
                swap_record(&records[i], &records[j]);
            }
        }
    }
}

void print_record_entry(record_t record)
{
    printf("%s %d\n", record.name, record.score);
}