#include <stdio.h>
#include <stdlib.h>
#include "Liste.h"
#include "Geometrie.h"


Liste_t *CreerListe()
{
    Liste_t *liste = malloc(sizeof(*liste));

    if (liste == NULL )
    {
        exit(EXIT_FAILURE);
    }
    liste->taillelist=0;
    liste->dernier = NULL;
    liste->premier = NULL;

    return liste;
}


void InsertionFin(Liste_t *liste, Centre nwCentre)
{
    // Création du nouvel élément
    Element_t *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL && nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->item = nwCentre;
    //nouveau->suivant = NULL;

    if (liste->dernier == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
    {
        nouveau->precedant = liste->premier;
        nouveau->suivant = liste->premier;
        liste->premier = nouveau;
        liste->dernier = nouveau;
    }
    else
    {
        nouveau->precedant = liste->dernier;
        nouveau->suivant = NULL;

        liste->dernier->suivant = nouveau;
        liste->dernier = nouveau;
    }
    //printf("\n\n%p\n\n",liste->dernier);
    liste->taillelist++;
}

Element_t* ParcourirListe (Liste_t *liste, Element_t *actuel)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    actuel = actuel->suivant;

    return actuel;
}

void AfficherListe(Liste_t *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element_t *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("x: %f, y: %f, z: %f \n", actuel->item.x, actuel->item.y, actuel->item.z);
        actuel = actuel->suivant;
    }
}
