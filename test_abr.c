#include <stdio.h>
#include <stdlib.h>

#include "abr.h"

int main (int argc, char**argv)
{
  Arbre_t a ;

  if (argc != 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv[1]) ;
  
  afficher_arbre (a,0) ;

  

  printf("hauteur_arbre_r : %d \n", hauteur_arbre_r(a));
  printf("hauteur_arbre_nr: %d \n\n", hauteur_arbre_nr(a));

  parcourir_arbre_largeur(a);

  printf("nombre cles arbres : %d \n", nombre_cles_arbre_r(a));
  printf("nombre cles arbres nr : %d \n", nombre_cles_arbre_nr(a));
  printf("cle minimum dans arbre : %d\n", trouver_cle_min(a));
   

  afficher_nombre_noeuds_par_niveau(a);


  printf("liste clefs triées :\n");
  imprimer_liste_cle_triee_r(a);

  printf("liste clefs triées :\n");
  imprimer_liste_cle_triee_nr(a);

  printf("Arbre plein ? %d\n", arbre_plein(a));
  printf("Arbre parfait ? %d\n", arbre_parfait(a));
}
