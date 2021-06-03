#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "courbe.h"
#include "Geometrie.h"
#include "Liste.h"
#include "STL.h" 

    
// PROTOTYPE DE LA FONCTION CALCUL DISTANCE
float calculer_Distance_Cubes(float a, float b)
{
    return fmax(    fmax(    fabs(f[0].x(a)-f[0].x(b))  ,fabs(f[0].y(a)-f[0].y(b))   )  , fabs(f[0].z(a)-f[0].z(b))     );
}


// PROTOTYPE DE LA FONCTION DICHOTOMIE
float dichotomie(float taille_cube, float t, float seuil, float delta, Centre cubes, Liste_t *liste)
{
        
    float distance=0.0;
    float distance1=0.0;
    float t0=t;
    delta/=10;
    float t1=t+delta;
    distance = calculer_Distance_Cubes(t0, t1);
    float tm=0.0;
    bool myCondition=true;
    //printf("t= %f\ntaille_cube= %f\nepsilon= %f\ndelta= %f\n", t,taille_cube,epsilon,delta);
    // printf("t0= %f\ntm= %f\nt1= %f\ndistance= %f\n", t0,tm,t1,distance);
    

    while (distance > (seuil) && myCondition) 
    {
        tm= (t0+t1)/2.0;  
        // tm= (t0+t1)/2.0;
        //printf("t0= %f\ntm= %f\nt1= %f\ndistance= %f\n", t0,tm,t1,distance);
        distance1=calculer_Distance_Cubes(t0, tm);
        //printf("t0= %f\ntm= %f\nt1= %f\ndistance1= %f\n", t0,tm,t1,distance1);
        if (distance1 < seuil)
        {   
            myCondition=false;
            t0=tm;
        }
        else
        {  
            t1=tm;
        }

        distance = calculer_Distance_Cubes(t0, t1);

    }

    tm=t1;
    
    while (distance < seuil && myCondition)
    {   

        t1= tm + delta;
    
        // tm= (t0+t1)/2.0;
        //printf("t0= %f\ntm= %f\nt1= %f\ndistance= %f\n", t0,tm,t1,distance);
        distance1=calculer_Distance_Cubes(t0, t1);
        //printf("t0= %f\ntm= %f\nt1= %f\ndistance1= %f\n", t0,tm,t1,distance1);
        if (distance1 > seuil)
        {   
            myCondition=false;
        }
        else
        {  
            tm=t1;
        }
        //distance = calculer_Distance_Cubes(t0, t1);
    }
    cubes.x=f[0].x(t1);
    cubes.y=f[0].y(t1);
    cubes.z=f[0].z(t1);
        printf("t1: %f\n\n",t1);

    InsertionFin(liste, cubes); 
    return t1;
}
        

int main(void)
{

    float t_min=f[0].t_min;
    float t_max=f[0].t_max;
    float t_pas=f[0].t_pas; // variable pour incrémenter le pas car on a (pas*t): ce qui rapproche les cubes  
    float t=0.0;
    float taille_cube=f[0].cote;
    float epsilon=(taille_cube*2.0)/100.0;
    float seuil=taille_cube+epsilon;
    float i=0; // variable pour la boucle

    printf("t_min= %f\nt_max= %f\nt_pas= %f\n", t_min,t_max,t_pas);

    // creation d'une variable intermediaire de type Centre represenatnt les coordonéees xyz du centre du cube et la taille    
    Centre cubes={0.0, 0.0, 0.0,taille_cube}; // centres de cubes et leur taille
    Liste_t *liste=CreerListe(); // creer un type liste qui pointe vers le 1er et le derneier element de la liste

    
    for(i=t_min; i<t_max;i+=t_pas) // ... points(centres des cubes) à récupérer dans cubes
    // f[0] est la premiere courbe (ellipse)    
    {                            
        //InsertionFin(liste, cubes);            
        if(liste->dernier==NULL)
        {
            cubes.x=f[0].x(i);
            cubes.y=f[0].y(i);
            cubes.z=f[0].z(i);
            InsertionFin(liste, cubes);
        }
        else 
        {
            
            i=dichotomie(taille_cube,i-t_pas,seuil,t_pas,cubes,liste);
        }
                printf("i: %f\n\n",i);

    }
    creer_fichier_stl_ascii(liste);
    
    return 0;
}

    
    
    
   