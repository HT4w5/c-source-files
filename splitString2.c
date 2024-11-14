#include <stdio.h>
#include <stdlib.h>
#define MAX_SRC_SIZE 2000
#define MAX_DLIM_SIZE 2000

/*
    Return NULL if dlim does not exist.
    Return address after dlim in source.
*/
const char *find_dlim(const char *s1, const char *dlim)
{
    const char *s2 = dlim;
    const char *next;
    while (*s1 != '\0')
    {
        if (*s1 == *s2)
        {
            s1++;
            s2++;
        }
        else
        {
            if (*s2 == '\0')
            {
                // Recurse to find all dlims.
                if ((next = find_dlim(s1, dlim)) == s1)
                {
                    return s1;
                }
                else if (next)
                {
                    return next;
                }
                else
                {
                    return s1;
                }
            }
            else
            {
                return NULL;
            }
        }
    }
    return s1;
}

void append_tgt(char tgt[][100], const int tgt_i, const char *start, const char *end)
{
    int len = end - start + 1;
    for (int i = 0; i < len; i++)
    {
        tgt[tgt_i][i] = start[i];
    }
    tgt[tgt_i][len] = '\0';
}

void split_string(char tgt[][100], const char *src, const char *dlim)
{
    /*
      fsp:     fast source pointer.
      ssp:     slow source pointer.
      next:    next address after dlim in source string.
    */
    const char *fsp = src, *ssp = src;
    int tgt_i = 0;
    const char *next = NULL;
    while (*fsp != '\0')
    {
        if (*fsp != *dlim)
        {
            fsp++;
        }
        else
        {
            if ((next = find_dlim(fsp, dlim)))
            {
                // Don't append if src starts with dlim.
                if (fsp != ssp)
                {
                    append_tgt(tgt, tgt_i, ssp, fsp - 1);
                    tgt_i++;
                }
                ssp = next;
                fsp = next;
            }
            else
            {
                fsp++;
            }
        }
    }
    if (fsp != next || next == NULL)
    {
        append_tgt(tgt, tgt_i, ssp, fsp - 1);
    }
}

int main(void)
{
    char src[MAX_SRC_SIZE + 1];
    char dlim[MAX_DLIM_SIZE + 1];
    // Fill src with NULL.
    for (int i = 0; i < MAX_SRC_SIZE + 1; i++)
    {
        src[i] = '\0';
    }
    // Input data.
    scanf("%s", src);
    scanf("%s", dlim);

    // Split string.
    char tgt[20][100];
    // Null terminate all empty strings.
    for (int i = 0; i < 20; i++)
    {
        tgt[i][0] = '\0';
    }
    split_string(tgt, src, dlim);

    // Print results.
    for (int i = 0; i < 20; i++)
    {
        if (tgt[i][0] != '\0')
        {
            printf("%s\n", tgt[i]);
        }
    }
    return 0;
}