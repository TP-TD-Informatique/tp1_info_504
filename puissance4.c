#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define COLOR(X) printf("\033["X"m")

#define WIDTH 7
#define HEIGHT 6
// caractère 'x'
#define PLAYER1 120
// caractère 'o'
#define PLAYER2 111

typedef char Jeu [HEIGHT][WIDTH];


void affiche(Jeu g)
{
  printf("Etat courant de la partie :\n");
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      printf("| ");
      char c = g[i][j];
      if (c == PLAYER1)
      {
        COLOR("41");
      }
      else if (c == PLAYER2)
      {
        COLOR("43");
      }
      printf("%c", g[i][j]);
      COLOR("0");
      printf(" ");
    }
    printf("|\n");
  }

  printf("\n");
  for (int i = 0; i < WIDTH; i++)
  {
    printf("  %d ", i +1);
  }
  printf("\n\n");
}

void init(Jeu g)
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      g[i][j] = '.';
    }
  }
}

bool n_est_pas_pleine (int c, Jeu g)
{
  return g[0][c] == '.';
}

void joue(int j, int c, Jeu p)
{
  if (n_est_pas_pleine(c, p))
  {
    int i = 0;
    c--;
    while (p[i][c] == '.' && i < HEIGHT) i++;

    i--;
    p[i][c] = j == 1 ? PLAYER1 : PLAYER2;
  }
  else
  {
    printf("C'est impossible\n");
  }
}

int main()
{
  Jeu game;
  init(game);
  affiche(game);
  joue(1,4,game);
  joue(2,3,game);
  joue(1,5,game);
  joue(2,6,game);
  joue(1,4,game);
  joue(2,5,game);
  joue(1,4,game);
  joue(2,4,game);
  affiche(game);
  return 0;
}
