#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "graphe.h"
#include "file.h"

void algo_dijkstra (pgraphe_t g, int r)
{
  /*
    algorithme de dijkstra
    des variables ou des chanmps doivent etre ajoutees dans les structures.
  */
  while (g->label!=r){
    g = g->sommet_suivant;
  } //on est sur le sommet r
  g->poids_dijkstra=0;
  int nb_sommets = nombre_sommets(g);
  sommet_t sommets[nb_sommets] = parcours_graph_init_dijkstra(g);
  boucle_dijkstra(sommets,g,nb_sommets);
}

sommet_t* parcours_graph_init_dijkstra(pgraphe_t g){

}

void boucle_dijkstra(sommet_t* sommets, pgraphe_t g, int nb_sommets){
  while (nb_sommets > 0){
    sommet_t current = extraire_min_liste(&sommets, nb_sommets);
  }
}

sommet_t extraire_min_liste(int nb_sommets, sommet_t sommets[nb_sommets]){
  int min = sommets[0].label;
  int indice=0;
  sommet_t current = sommets[0];
  for (int i=1; i<nb_sommets; i++){
    if (sommets[i].label < min){
      min = sommets[i].label;
      current = sommets[i];

    }
  }
  
  return current;
}