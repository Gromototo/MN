Arbre234 noeud_max(Arbre234 a){
    
    int max = 0;
    Arbre234[] noeuds = malloc(sizeof(Arbre234)*NombreCles(a));

    adios
}

int aux(Arbre234 a, int max){
    if (a == NULL){
        return 0;
    }
    int somme_cle = 0;
    
    for (int i = 0; i<a->t){
        somme_cle += a->cle[i];
    }
    if (somme_cle > max){
        max = somme_cle;
    }

}