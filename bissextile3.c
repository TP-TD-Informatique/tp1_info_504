#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool est_bissextile(int annee)
{
  return (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
}

int nb_annees_bissextiles(int debut, int fin)
{
  if (debut <= fin)
  {
    int result = 0;

    for (int i = debut; i <= fin; i++)
    {
      result += est_bissextile(i) ? 1 : 0;
    }

    return result;
  }
  else
  {
    return 0;
  }
}

int main(int argc, char** argv)
{
  if (argc >= 3)
  {
    int debut = atoi(argv[1]);
    int fin = atoi(argv[2]);

    printf("Il y a %d année bissextiles entre %d et %d.\n", nb_annees_bissextiles(debut, fin), debut, fin);
  }

  return 0;
}
