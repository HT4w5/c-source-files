#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    unsigned short len;
    unsigned short d;
    unsigned int sn;
} pipe_t;

pipe_t *parse_pipe()
{
    pipe_t *pipe = (pipe_t *)malloc(sizeof(pipe_t));
    scanf("%d%d%d", &pipe->len, &pipe->d, &pipe->sn);
    return pipe;
}

int find_max_pipe(int n_pipes, pipe_t *pipes[])
{
    unsigned short max_len = 0, min_d = USHRT_MAX;
    unsigned short n_longest = 0, n_thinnest = 0;
    unsigned short longest_i[n_pipes], thinnest_i[n_pipes];
    int min_sn = 0;

    // Find longest.
    for (int i = 0; i < n_pipes; i++)
    {
        if ((*pipes[i]).len > max_len)
        {
            max_len = (*pipes[i]).len;
        }
    }
    for (int i = 0; i < n_pipes; i++)
    {
        if ((*pipes[i]).len == max_len)
        {
            longest_i[n_longest] = i;
            n_longest++;
        }
    }

    // Find thinnest.
    for (int i = 0; i < n_longest; i++)
    {
        if (pipes[longest_i[i]]->d < min_d)
        {
            min_d = pipes[longest_i[i]]->d;
        }
    }
    for (int i = 0; i < n_longest; i++)
    {
        if (pipes[longest_i[i]]->d == min_d)
        {
            thinnest_i[n_thinnest] = i;
            n_thinnest++;
        }
    }

    // Find newest.
    for (int i = 0; i < n_thinnest; i++)
    {
        if (pipes[longest_i[thinnest_i[i]]]->sn > min_sn)
        {
            min_sn = pipes[longest_i[thinnest_i[i]]]->sn;
        }
    }
    return min_sn;
}

int main(void)
{
    int n_pipes;
    scanf("%d", &n_pipes);
    pipe_t *pipes[n_pipes];

    // Input.
    for (int i = 0; i < n_pipes; i++)
    {
        pipes[i] = parse_pipe();
    }

    printf("%d", find_max_pipe(n_pipes, pipes));

    for (int i = 0; i < n_pipes; i++)
    {
        free(pipes[i]);
    }

    return 0;
}
