void AnalyseStructureArbre (Arbre234 a, int *feuilles, int *noeud2, int *noeud3, int *noeud4)
{
  if (a==NULL){
    printf("Arbre NULL !\n");
    return;
  }
  noeud234 node_parcours = *a;
  if (node_parcours.t==0){
    printf("l'arbre est seulement une feuille !\n");
    exit(-1);
  }
}