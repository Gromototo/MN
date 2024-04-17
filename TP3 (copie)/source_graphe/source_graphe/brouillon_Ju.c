#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "graphe.h"
#include "file.h"

psommet_t* to_array(pgraphe_t g){
  psommet_t s_parcours = g;
  psommet_t tab[nombre_sommets(g)];
  int cpt = 0;
  while ( s_parcours != NULL)
  {
    tab[cpt]=s_parcours;
    cpt++;
    s_parcours = s_parcours->sommet_suivant;
  }
  return tab;
}

/* Extrait l'element (non NULL) de la liste avec le poids de Dijkstra le plus faible */
psommet_t extraire_min_liste(int* nb_sommets, psommet_t sommets[*nb_sommets]){
  psommet_t sommet_min ;
  int min = NULL;
  int indice=-1;
  psommet_t current;
  for (int i=0; i<*nb_sommets; i++){
    current = sommets[i];
    if ( min == NULL || indice == -1 ){
      if (!(sommets[i]->traite) && sommets[i]->poids_dijkstra != INT_MAX){
        indice = i;
        min = sommets[i]->poids_dijkstra;
        sommet_min = sommets[i];
      }
    }
    else{
      if (sommets[i]->poids_dijkstra < min){
        min = sommets[i]->poids_dijkstra;
        current = sommets[i];
        indice = i;
      }
    }
  }
  if (min==NULL){
    printf("Graphe impossible à parcourir en entier");
    return NULL;
  }
  psommet_t nv_liste[*nb_sommets - 1];
  for (int i=0; i<indice-1; i++){
    nv_liste[i]=sommets[i];
  }
  for (int i=indice; i<nb_sommets-1; i++){
    nv_liste[i]=sommets[i+1];
  }
  sommets = nv_liste;
  (*nb_sommets)--;
  return &current;
}

void algo_dijkstra (pgraphe_t g, int r)
{
  /*
    algorithme de dijkstra
    des variables ou des chanmps doivent etre ajoutees dans les structures.
  */
  psommet_t g = chercher_sommet(g, r); //on est sur le sommet r
  if (g==NULL){
    printf("Impossile de trouver le sommet avec ce label\n");
    return;
  }
  psommet_t* sommets = to_array(g);
  while (sommets != NULL){
    (*sommets)->traite=false;
    (*sommets)->poids_dijkstra=INT_MAX;
    (*sommets) = (*sommets)->sommet_suivant;
  }
  sommets = to_array(g);
  g->poids_dijkstra=0;
  boucle_dijkstra(g, nombre_sommets(g), sommets);
}

void boucle_dijkstra (pgraphe_t g, int nb_sommets_tot, psommet_t a_visiter[nb_sommets_tot]){
  psommet_t tmp = extraire_min_liste(&nb_sommets_tot,a_visiter);
  if (tmp==NULL){
    printf("Graphique vide");
    return;
  }
  else{
    bool fini=false;
    while (!fini){
      tmp->traite=true;
      arc_t* arc_parcours = tmp->liste_arcs;
      while (arc_parcours != NULL){
        if (!arc_parcours->dest->traite && tmp->poids_dijkstra + arc_parcours->poids < arc_parcours->dest->poids_dijkstra) {
          arc_parcours->dest->poids_dijkstra = tmp->poids_dijkstra + arc_parcours->poids;
          arc_parcours->dest->sommet_precedent = tmp;
          arc_parcours->dest->arc_precedent = arc_parcours;
        }
        arc_parcours = arc_parcours->arc_suivant;
      }
      psommet_t tmp = extraire_min_liste(&nb_sommets_tot,a_visiter);
      if (tmp==NULL){
        fini=true;
      }
    }
  }
}