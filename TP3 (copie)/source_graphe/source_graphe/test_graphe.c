#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"
#include <assert.h>

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
  

  //DS 2021 TESTS


  lire_graphe ("data/gr3", &g) ;


  assert(graphe_eulerien(g) == 0);
  chemin_t chemin;


  parc_t arc2 = (parc_t) malloc(sizeof(arc_t));

  //arc 5 vers 1
  arc2->arc_suivant = NULL;
  arc2->poids = 1;
  arc2->dest = chercher_sommet(g, 1);
  


  chemin.arcs = arc2;
  chemin.debut = 5;
  chemin.nb_arcs = 1;

  assert(elementaire(g, chemin) == 1);
  printf("TEST 1 OK\n");
  //arc 1 vers 5
  parc_t arc1 = (parc_t) malloc(sizeof(arc_t));

  arc1->poids = 1;
  arc1->arc_suivant = arc2;
  arc1->dest = chercher_sommet(g, 5);


  // (1->5)(5->1)
  chemin.arcs = arc1;
  chemin.debut = 1;
  chemin.nb_arcs = 2;

  assert(elementaire(g, chemin) == 0);
  assert(simple(g, chemin) == 1);

  printf("TEST 2 OK\n");


  //arc 5 vers 1

  parc_t arc0 = (parc_t) malloc(sizeof(arc_t));

  arc0->arc_suivant = arc1;
  arc0->poids = 1;
  arc0->dest = chercher_sommet(g, 1);
  

  // (5->1)(1->5)(5->1) 
  chemin.arcs = arc0;
  chemin.debut = 5;
  chemin.nb_arcs = 3;

  assert(elementaire(g, chemin) == 0);
  assert(simple(g, chemin) == 0);
  assert(eulerien(g, chemin) == 0);
  assert(hamiltonien(g, chemin) == 0);
  
  printf("TEST 3 OK\n");


  lire_graphe ("data/gr2", &g) ;

  assert(graphe_eulerien(g) == 1);


  //arc 1 vers 2
  parc_t arc4 = (parc_t) malloc(sizeof(arc_t));
  
  arc4->arc_suivant = NULL;
  arc4->poids = 8;
  arc4->dest = chercher_sommet(g, 2);

  //arc 2 vers 1
  parc_t arc3 = (parc_t) malloc(sizeof(arc_t));

  arc3->arc_suivant = arc4;
  arc3->poids = 3;
  arc3->dest = chercher_sommet(g, 1);

  //arc 3 vers 2
  arc2->arc_suivant = arc3;
  arc2->poids = 2;
  arc2->dest = chercher_sommet(g, 2);
  
  //arc 1 vers 3
  arc1->poids = 5;
  arc1->arc_suivant = arc2;
  arc1->dest = chercher_sommet(g, 3);

  //arc 1 vers 1
  arc0->arc_suivant = arc1;
  arc0->poids = 2;
  arc0->dest = chercher_sommet(g, 1);
  

  // (1->1)(1->3)(3->2)(2->1)(1->2)
  chemin.arcs = arc0;
  chemin.debut = 1;
  chemin.nb_arcs = 5;

  assert(eulerien(g, chemin) == 1);
  assert(hamiltonien(g, chemin) == 0);
  assert(longueur(g, chemin) == 20);
  printf("TEST 4 OK\n");


  lire_graphe ("data/gr2", &g) ;

  //arc 3 vers 2
  arc2->arc_suivant = NULL;
  arc2->poids = 2;
  arc2->dest = chercher_sommet(g, 2);
  
  //arc 1 vers 3
  arc1->poids = 5;
  arc1->arc_suivant = arc2;
  arc1->dest = chercher_sommet(g, 3);

  // (1->3)(3->2)
  chemin.arcs = arc1;
  chemin.debut = 1;
  chemin.nb_arcs = 2;

  lire_graphe ("data/gr2", &g) ;
  assert(hamiltonien(g, chemin) == 1);
  printf("TEST 5 OK\n");


  lire_graphe ("data/gr2", &g) ;
  assert(graphe_hamiltonien(g) == 1);
  printf("TEST 6 OK\n");


  lire_graphe ("data/gr3", &g) ;
  assert(graphe_hamiltonien(g) == 0);
  printf("TEST 7 OK\n");


  lire_graphe ("data/gr4", &g) ;
  assert(graphe_hamiltonien(g) == 1);
  printf("TEST 8 OK\n");

  lire_graphe ("data/gr0", &g) ;
  assert(graphe_hamiltonien(g) == 1);
  printf("TEST 9 OK\n");

  lire_graphe ("data/gr1", &g) ;

  assert(distance(g, 1,2) == 1);
  assert(distance(g, 2,3) == 2);


  lire_graphe ("data/gr4", &g) ;
  assert(distance(g, 1,5) == 7);

  lire_graphe ("data/gr2", &g) ;


  //c'est fait exprès mais voir avec MEHAUT si c'est ce qu'il attend.
  //sinon plonger dans la fonction distance et distance_rec pour trouver
  //ce qu'il faut modifier pour que ça marche comme lehaut le veut
  assert(distance(g, 1, 1)==0);

  //cas particulier ça n'est pas une erreur, plus rapide de prendre détour que direct
  assert(distance(g, 1, 2)==7);
  assert(excentricite(g, 1) == 7);
  assert(diametre(g) == 8);

  printf("TEST 10 OK\n");


  printf("\n  ALL TESTS PASSED  \n");
  printf("\nIn God we trust. The rest we test.\n");


}
