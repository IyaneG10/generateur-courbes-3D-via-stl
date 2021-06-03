#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include "courbe.h"


// variables nécessaires pour mon ellipse
float radius=100.0;
float pas=10.0;
// équations de la courbe 1 (ellipse)
float courbe1_x(float t){ return radius*sin(t); }
float courbe1_y(float t){ return radius*cos(t); }
float courbe1_z(float t){ return pas*t; }

// création d'un tableau de type fonction (contient les équations des courbes) 
struct fonction_s f[]={
  {courbe1_x,courbe1_y,courbe1_z,0,30*M_PI,M_PI/50.0,20}, {NULL}};

  
    
    

