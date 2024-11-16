#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  mcake_t:
  inv: inventory.
  tp:  total price.
  up:  unit price.
*/
typedef struct
{
  double up;
  double inv;
  double tp;
} mcake_t;

mcake_t *mcake_create(void)
{
  mcake_t *new_mcake = (mcake_t *)malloc(sizeof(mcake_t));
  memset(new_mcake, 0, sizeof(mcake_t));
  return new_mcake;
}

void mcake_calc_up(mcake_t *mcake)
{
  if (mcake->inv != 0 && mcake->tp != 0)
  {
    mcake->up = mcake->tp / mcake->inv;
  }
  else
  {
    perror("Empty Mcake");
    exit(EXIT_FAILURE);
  }
}

// Compare function for mcake_t in qsort().
int mcake_compare(const void *a, const void *b)
{
  if (((mcake_t *)a)->up == 0 || ((mcake_t *)b)->up == 0)
  {
    perror("Invalid unit price");
    exit(EXIT_FAILURE);
  }
  return (int)((mcake_t *)a)->up - ((mcake_t *)b)->up;
}

double max_income(mcake_t *mcakes[], int n_cat, int demand)
{
  // Sort mcakes.
  qsort(mcakes,sizeof(mcakes)/sizeof())
}

int main(void)
{
  int n_cat, demand;
  scanf("%d%d", &n_cat, &demand);

  mcake_t mcakes[n_cat];
  memset(mcakes,0)

  // Input mooncake stats.
  for (int i = 0; i < n_cat; i++)
  {
    mcakes[i] = mcake_create();
    scanf("%d", &mcakes[i]->inv);
  }
  for (int i = 0; i < n_cat; i++)
  {
    scanf("%d", &mcakes[i]->tp);
    mcake_calc_up(mcakes[i]);
  }
  // Input mooncake stats finish.

  printf("%.2lf", max_income(mcakes, n_cat, demand));

  for (int i = 0; i < n_cat; i++)
  {
    free(mcakes[i]);
  }

  return 0;
}