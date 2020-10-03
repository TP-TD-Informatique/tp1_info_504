#include <stdio.h>
#include <stdbool.h>

bool est_bissextile(int annee)
{
  return (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
}

int main()
{
  printf("Quelle année souhaitez vous tester ?\n");
  int annee;
  scanf("%d", &annee);

  if (est_bissextile(annee))
  {
    printf("L'année %d est une année bissextile\n", annee);
  }
  else
  {
    printf("L'année %d n'est pas une année bissextile\n", annee);
  }
}
