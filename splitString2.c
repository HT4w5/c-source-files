#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SRC_SIZE 2000
#define MAX_DLIM_SIZE 2000

void split_string(char tgt[][100], const char *src, const char *dlim)
{
    
}

int main(void)
{
    char src[MAX_SRC_SIZE + 1];
    char dlim[MAX_DLIM_SIZE + 1];
    // Input data.
    scanf("%s", src);
    scanf("%s", dlim);

    // Split string.
    char tgt[20][100];
    split_string(tgt, src, dlim);

}