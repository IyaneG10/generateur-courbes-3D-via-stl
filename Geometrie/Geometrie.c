#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
#include "Geometrie.h"



void calculer_Normal(Points Coord, Points point1, Points point2, Points point3)
{
    Coord.x=(point2.y-point1.y)*(point3.z-point1.z)-(point2.z-point1.z)*(point3.y-point1.y);
    Coord.y=(point2.z-point1.z)*(point3.x-point1.x)-(point2.x-point1.x)*(point3.z-point1.z);
    Coord.z=(point2.x-point1.x)*(point3.y-point1.y)-(point2.y-point1.y)*(point3.x-point1.x);
}


  