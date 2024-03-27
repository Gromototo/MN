#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pile.h"
#include <stdbool.h>


void afficher_graphe_profondeur (pgraphe_t g, int r)
{
  /*
    afficher les sommets du graphe avec un parcours en profondeur
  */
  
    psommet_t s = chercher_sommet(g,r);
    ppile_t avisiter = creer_pile();

    int dejavisite[nombre_sommet(g)];
        
    int dejavisiteindex = 0;

    empiler(s, avisiter);
    while (!est_vide(avisiter))
        {
            psommet_t t = pop(avisiter);
            printf("%i", t->label);
            dejavisiteindex++;

                for(int j = 0; j<dejavisiteindex; j++)
                {
                    if (!deja_visite(t->liste_arcs[j]->dest->label, dejavisite, dejavisiteindex))
                    {
                        empiler(avisiter, t->liste_arcs[j]->dest);
                    }
                }
        }
        
  return;
}
 

 