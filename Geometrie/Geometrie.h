#ifndef H_GEOMETRIE
#define H_GEOMETRIE

typedef struct Centre{ 
    float x;
    float y;
    float z;
    float taille;
} Centre;

typedef struct Points{ 
    float x;
    float y;
    float z;
} Points;

void calculer_Normal(Points Coord, Points point1, Points point2, Points point3);


#endif
