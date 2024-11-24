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

void mcake_calc_up(mcake_t *mcake)
{
  //if (mcake->inv != 0 && mcake->tp != 0)
  if (1) // Disabled after debug.
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
  //if (((mcake_t *)a)->up == 0 || ((mcake_t *)b)->up == 0)
  if (0) // Disabled after debug.
  {
    perror("Invalid unit price");
    exit(EXIT_FAILURE);
  }
  // Compare.
  if (((mcake_t *)a)->up > ((mcake_t *)b)->up)
  {
    return -1;
  }
  else if (((mcake_t *)a)->up < ((mcake_t *)b)->up)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

double max_income(mcake_t mcakes[], int n_cat, double demand)
{
  // Sort mcakes.
  size_t mcake_size = sizeof(mcake_t);
  // Sort in acsending order.
  qsort(mcakes, n_cat, mcake_size, mcake_compare);

  // Calc income.
  double income = 0;
  for (int i = 0; i < n_cat; i++)
  {
    if (mcakes[i].inv < demand)
    {
      demand -= mcakes[i].inv;
      income += mcakes[i].inv * mcakes[i].up;
    }
    else
    {
      income += demand * mcakes[i].up;
      break;
    }
  }

  return income;
}

int main(void)
{
  int n_cat;
  double demand;
  scanf("%d%lf", &n_cat, &demand);

  mcake_t mcakes[n_cat];
  memset(mcakes, 0, sizeof(mcake_t) * n_cat);

  // Input mooncake stats.
  for (int i = 0; i < n_cat; i++)
  {
    scanf("%lf", &mcakes[i].inv);
  }
  for (int i = 0; i < n_cat; i++)
  {
    scanf("%lf", &mcakes[i].tp);
    mcake_calc_up(&mcakes[i]);
  }
  // Input mooncake stats finish.

  printf("%.2lf", max_income(mcakes, n_cat, demand));

  return 0;
}