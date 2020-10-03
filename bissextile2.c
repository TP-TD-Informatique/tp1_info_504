#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool est_bissextile(int annee)
{
  return (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
}

int main(int argc, char** argv)
{
  if (argc >= 2)
  {
    int annee = atoi(argv[1]);

    if (est_bissextile(annee))
    {
      printf("L'année %d est une année bissextile\n", annee);
    }
    else
    {
      printf("L'année %d n'est pas une année bissextile\n", annee);
    }
  }
}
