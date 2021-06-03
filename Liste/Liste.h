#ifndef H_LISTE
#define H_LISTE
#include <stdbool.h>
#include "Liste.h"
#include "Geometrie.h"

typedef struct Element_s{
    Centre item;
    struct Element_s *suivant;
    struct Element_s *precedant;
} Element_t;


typedef struct Liste_s
{
    unsigned int  taillelist;
     Element_t *premier;
     Element_t *dernier;
}Liste_t;

Liste_t *CreerListe();
void InsertionFin(Liste_t *liste, Centre nwCentre);
Element_t* ParcourirListe(Liste_t *liste, Element_t *actuel);
void AfficherListe(Liste_t *liste);


#endif
