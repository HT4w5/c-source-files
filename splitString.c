#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SRC_SIZE 2000
#define MAX_DLIM_SIZE 2000

// Return value: 1:same; 2:different.
int compare_dlim(const char *start, const char *dlim, size_t dlim_len)
{
    for (int i = 0; i < dlim_len; i++)
    {
        if (start[i] != dlim[i])
        {
            return 0;
        }
    }
    return 1;
}

void split_string(char tgt[][100], const char *src, const char *dlim)
{
    int index = 0;

    // Get delimiter size.
    size_t dlim_len = 0;
    while (dlim[index] != '\0')
    {
        dlim_len++;
        index++;
    }

    // Get source size.
    size_t src_len = 0;
    index = 0;
    while (src[index] != '\0')
    {
        src_len++;
        index++;
    }

    char *src_mask = (char *)malloc(MAX_SRC_SIZE + 1);
    memset(src_mask, 'c', MAX_SRC_SIZE + 1);

    for (int k = 0; k < src_len;)
    {
        if (src[k] == *dlim && k < src_len - dlim_len + 1)
        {
            if (compare_dlim(src + k, dlim, dlim_len))
            {
                *(src_mask + k) = 'r';
                memset(src_mask + k + 1, 'e', dlim_len - 1);
            }

            k += dlim_len;
        }
        else
        {
            k++;
        }
    }

    // Slice string.
    int tgt_index_x = 0, tgt_index_y = 0;
    for (int i = 0; i < src_len;)
    {
        if (src_mask[i] == 'c')
        {
            tgt[tgt_index_x][tgt_index_y] = src[i];
            tgt_index_y++;
            i++;
        }
        else if (src_mask[i] == 'r')
        {
            tgt_index_x++;
            tgt_index_y = 0;
            while (src_mask[i] == 'e')
            {
                i++;
            }
        }
    }
}

int main(void)
{
    char *src = (char *)malloc(MAX_SRC_SIZE + 1);
    char *dlim = (char *)malloc(MAX_DLIM_SIZE + 1);

    // Input.
    char buf;
    int i = 0;
    while ((buf = getchar()) >= ' ')
    {
        src[i] = buf;
        i++;
    }
    src[i] = '\0';

    getchar();

    i = 0;
    while ((buf = getchar()) >= ' ')
    {
        dlim[i] = buf;
        i++;
    }
    dlim[i] = '\0';

    char tgt[20][100];

    memset(&tgt,'\0',sizeof(tgt));

    split_string(tgt, src, dlim);

    // Print results.
    for(int i=0;tgt[i]!=0)
}
