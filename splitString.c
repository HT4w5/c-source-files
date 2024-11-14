#include <stdio.h>
#include <stdlib.h>
#define MAX_SRC_SIZE 2000
#define MAX_DLIM_SIZE 2000

void split_string(char tgt[][100], const char *src, const char *dlim)
{
    const char *lsp = src, *hsp = src, *sp = src, *dp = dlim;
    char *src_mask = (char *)malloc(MAX_SRC_SIZE + 1);

        while ()
    {
        if (*hsp != *dp)
        {
            hsp++;
        }
        else
        {
            sp = hsp;
            dp = dlim;
            while ()
            {
                sp++;
                dp++;
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
}
