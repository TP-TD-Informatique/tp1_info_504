#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct {
  float x, y; // Coordonnées en x, y
  float t; // Angle en degrées
} Tortue;

void init(Tortue* tortue)
{
  tortue->x = 0.0f;
  tortue->y = 0.0f;
  tortue->t = 0.0f;
}

void avance(Tortue* tortue, float d)
{
  tortue->x = tortue->x + d * cos( tortue->t * M_PI / 180.0 );
  tortue->y = tortue->y + d * sin( tortue->t * M_PI / 180.0 );
}

void affiche(Tortue tortue)
{
  printf( "%f %f\n", tortue.x, tortue.y );
}

void tourneG(Tortue *tortue, float t)
{
  tortue->t = tortue->t + t;
}

void tourneD(Tortue *tortue, float t)
{
  tourneG(tortue, -t);
}

void allezA(Tortue *tortue, float x, float y)
{
  tortue->x = x;
  tortue->y = y;
}

void koch(Tortue* T, float d, int k)
{
  if (k == 0)
  {
    affiche(*T);
    avance(T, d / 3);
    affiche(*T);
  }
  else
  {
    affiche(*T);
    koch(T, d / 3, k-1);
    affiche(*T);

    tourneG(T, 60);
    koch(T, d / 3, k-1);
    affiche(*T);

    tourneD(T, 120);
    koch(T, d / 3, k-1);
    affiche(*T);

    tourneG(T, 60);
    koch(T, d / 3, k-1);
    affiche(*T);
  }
}

int main()
{
  Tortue T;
  init(&T);
  affiche(T);

  koch(&T, 100,  10);
}
