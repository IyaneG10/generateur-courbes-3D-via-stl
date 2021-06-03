#include <stdio.h>  
#include <stdlib.h>
#include <stdio.h>
#include "Geometrie.h"
#include "Liste.h"

void calculer_Normal(Points coord_vect_normal, Points point1, Points point2, Points point3)
{
    coord_vect_normal.x=(point2.y-point1.y)*(point3.z-point1.z)-(point2.z-point1.z)*(point3.y-point1.y);
    coord_vect_normal.y=(point2.z-point1.z)*(point3.x-point1.x)-(point2.x-point1.x)*(point3.z-point1.z);
    coord_vect_normal.z=(point2.x-point1.x)*(point3.y-point1.y)-(point2.y-point1.y)*(point3.x-point1.x);
}


void creer_fichier_stl_ascii(Liste_t *liste) // prototype de la fonction
{
 
    FILE *fichier_stl_ascii = NULL;
    const char nom_fichier_ascii[]="stl_ascii.stl";  
    fichier_stl_ascii=fopen(nom_fichier_ascii,"w"); // fichier texte stl
    
    Centre centres_cubes={0.0, 0.0, 0.0,0.0};
           
     Points coord_vect_normal={0.0, 0.0, 0.0}, pointA={0.0, 0.0, 0.0}, pointB={0.0, 0.0, 0.0}, pointC={0.0, 0.0, 0.0},
        pointD={0.0, 0.0, 0.0}, pointAa={0.0, 0.0, 0.0}, pointBb={0.0, 0.0, 0.0}, pointCc={0.0, 0.0, 0.0}, pointDd={0.0, 0.0, 0.0};
    Element_t * avancer=liste->premier; // pour parcourir la liste a prtir du debut
    if(fichier_stl_ascii!=NULL)
    {
        
        fputs("solid Default\n",fichier_stl_ascii); 
        while(avancer!=NULL)
        {
                centres_cubes=avancer->item; //récupérer le centre(item)
            //calcul des coordonnées des 8 points de chaque cube à partir de celles du centre 
                pointA.x= (centres_cubes.x - (centres_cubes.taille / 2));
                pointA.y= (centres_cubes.y- (centres_cubes.taille / 2));
                pointA.z= (centres_cubes.z - (centres_cubes.taille / 2));

                pointB.x=pointA.x+centres_cubes.taille;
                pointB.y=pointA.y;
                pointB.z=pointA.z;

                pointC.x=pointB.x;
                pointC.y=pointB.y+centres_cubes.taille;
                pointC.z=pointB.z;

                pointD.x=pointC.x-centres_cubes.taille;
                pointD.y=pointC.y;
                pointD.z=pointC.z;

                pointAa.x=pointA.x;
                pointAa.y=pointA.y;
                pointAa.z=pointA.z+centres_cubes.taille;

                pointBb.x=pointB.x;
                pointBb.y=pointB.y;
                pointBb.z=pointB.z+centres_cubes.taille;

                pointCc.x=pointC.x;
                pointCc.y=pointC.y;
                pointCc.z=pointC.z+centres_cubes.taille;

                pointDd.x=pointD.x;
                pointDd.y=pointD.y;
                pointDd.z=pointD.z+centres_cubes.taille;
            
            
                
                
                //Face 1
                calculer_Normal(coord_vect_normal,pointAa, pointB, pointA);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointAa.x,pointAa.y,pointAa.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointA.x,pointA.y,pointA.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointB.x,pointB.y,pointB.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);

                calculer_Normal(coord_vect_normal,pointAa, pointBb, pointB);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointAa.x,pointAa.y,pointAa.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointB.x,pointB.y,pointB.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointBb.x,pointBb.y,pointBb.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);

                //Face 2
                calculer_Normal(coord_vect_normal,pointD, pointA, pointB);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointD.x,pointD.y,pointD.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointB.x,pointB.y,pointB.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointA.x,pointA.y,pointA.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);

                calculer_Normal(coord_vect_normal,pointD, pointB, pointC);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointD.x,pointD.y,pointD.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointC.x,pointC.y,pointC.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointB.x,pointB.y,pointB.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);

                //Face 3
                calculer_Normal(coord_vect_normal,pointDd, pointAa, pointA);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointDd.x,pointDd.y,pointDd.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointA.x,pointA.y,pointA.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointAa.x,pointAa.y,pointAa.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);

                calculer_Normal(coord_vect_normal,pointDd, pointAa, pointD);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointDd.x,pointDd.y,pointDd.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointD.x,pointD.y,pointD.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointA.x,pointA.y,pointA.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);

                //Face 4
                calculer_Normal(coord_vect_normal,pointDd, pointBb, pointAa);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointDd.x,pointDd.y,pointDd.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointAa.x,pointAa.y,pointAa.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointBb.x,pointBb.y,pointBb.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);

                calculer_Normal(coord_vect_normal,pointDd, pointCc, pointBb);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointDd.x,pointDd.y,pointDd.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointBb.x,pointBb.y,pointBb.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointCc.x,pointCc.y,pointCc.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);

                //Face 5
                calculer_Normal(coord_vect_normal, pointBb, pointCc, pointB);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointBb.x,pointBb.y,pointBb.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointB.x,pointB.y,pointB.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointCc.x,pointCc.y,pointCc.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);

                calculer_Normal(coord_vect_normal, pointCc, pointC, pointB);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointCc.x,pointCc.y,pointCc.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointB.x,pointB.y,pointB.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointC.x,pointC.y,pointC.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);

                //Face 6
                calculer_Normal(coord_vect_normal, pointD, pointCc, pointDd);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointD.x,pointD.y,pointD.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointDd.x,pointDd.y,pointDd.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointCc.x,pointCc.y,pointCc.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);

                calculer_Normal(coord_vect_normal, pointD, pointC, pointCc);
                fprintf(fichier_stl_ascii,"  facet normal %e %e %e\n", coord_vect_normal.x, coord_vect_normal.y, coord_vect_normal.z);
                fputs("    outer loop\n",fichier_stl_ascii);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointD.x,pointD.y,pointD.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointCc.x,pointCc.y,pointCc.z);
                fprintf(fichier_stl_ascii,"      vertex %e %e %e\n",pointC.x,pointC.y,pointC.z);
                fputs("    endloop\n",fichier_stl_ascii);
                fputs("  endfacet\n",fichier_stl_ascii);
                
                avancer=ParcourirListe(liste, avancer); // on recupere le prochain element de la liste
            }
            
            fprintf(fichier_stl_ascii,"endsolid Default");
            fclose(fichier_stl_ascii);
    }
}
