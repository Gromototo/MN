#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"

int main (int argc, char **argv)
{
  pgraphe_t g ;
  int nc ;
  
  if (argc != 2)
    {
      fprintf (stderr, "erreur parametre \n") ;
      exit (-1) ;
    }

  /*
    la fonction lire_graphe alloue le graphe (matrice,...) 
    et lit les donnees du fichier passe en parametre
  */
  
  
  lire_graphe (argv [1], &g) ;

  /*
    la fonction ecrire_graphe affiche le graphe a l'ecran
  */  
  
  printf ("nombre de sommets du graphe %d nombre arcs %d \n", nombre_sommets (g), nombre_arcs (g)) ;
  fflush (stdout) ;
  
  ecrire_graphe (g) ;      

  nc = colorier_graphe (g) ;
  
  printf ("nombre chromatique graphe = %d\n", nc) ;

  ecrire_graphe_colorie (g) ;

  int visites[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int last_index = -1;

  last_index = visiter(2, visites, last_index);
  printf("deja visité ? %d \n", deja_visite(2, visites, last_index));
  printf("VISITES : ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", visites[i]);
  }
  printf("FIN VISITES\n");


  printf("degre maximal graphe %d\n", degre_maximal_graphe(g));
  printf("degre minimal grpahe %d\n", degre_minimal_graphe(g));
  printf("graphe indepedantn %d\n", independant(g));
  printf("graphe complet %d \n", complet(g));
  printf("graphe regulier %d \n", regulier(g));

  psommet_t s = g;
  while (s!=NULL) {
    printf("sommet %d\n", s->label);
    printf("degre sortant %d\n", degre_sortant_sommet(g, s));
    printf("degre entrant %d\n", degre_entrant_sommet(g, s));

    s = s->sommet_suivant;
  }

  printf("Afficher graphe Largeur : \n");
  afficher_graphe_largeur(g, 1);


  printf("Afficher graphe profondeur : \n");
  afficher_graphe_profondeur(g, 1);
  

}
