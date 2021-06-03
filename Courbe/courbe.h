#ifndef H_COURBE
#define H_COURBE
typedef struct fonction_s {
  float (*x)(float);// coordonnées x
  float (*y)(float);// coordonnées y
  float (*z)(float);// coordonnées z
  float t_min;// début
  float t_max;// fin
  float t_pas;// échantillonage
  float cote; // taille cube
  } fonction_t;

extern fonction_t f[];

#endif
