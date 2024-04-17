LEITAO--PEREIRA DIAS Rodrigue
SANFILIPPO Jessy
MAZERATY Julian



TP ALG Graphes


Ensembles de fonctions développées et testées (cas positif et négatif) :


tests à la main :
  void afficher_graphe_profondeur (pgraphe_t g, int r) ;
  void afficher_graphe_largeur (pgraphe_t g, int r) ;

?void algo_dijkstra (pgraphe_t g, int r) ;

tests automatises (non fait) :

int degre_sortant_sommet (pgraphe_t g, psommet_t s);
int degre_entrant_sommet (pgraphe_t g, psommet_t s);
int degre_maximal_graphe (pgraphe_t g);
int degre_minimal_graphe (pgraphe_t g);
int independant (pgraphe_t g);
int complet (pgraphe_t g);
int regulier (pgraphe_t g);

tests automatisés cas positif et négatif :
int elementaire ( pgraphe_t g , chemin_t c ); 
int simple ( pgraphe_t g , chemin_t c );
int eulerien ( pgraphe_t g , chemin_t c );
int hamiltonien ( pgraphe_t g , chemin_t c );
int graphe_eulerien ( pgraphe_t g); 
int graphe_hamiltonien( pgraphe_t g); 
int distance (pgraphe_t g, int x, int y); 
int excentricite (pgraphe_t g, int n); 
int diametre( pgraphe_t g);
int longueur(pgraphe_t g, chemin_t c);


Description algorithmique individuelle des fonctions de l'examen de 2017 :


int elementaire(pgraphe_t g, chemin_t c) :







