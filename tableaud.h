#ifndef _STRTABLEAUD_H_
#define _STRSTABLEAUD_H_

//Structure du tableau dynamique
struct tabd {
    int coef;   //facteur d'aggrandissement
    int t;      //nombre de cases utilisé
    int tmax;
    void** tab;
};

//Création d'un tableau
struct tabd* tableau_init(int coef, int taille);

//Suppression d'un tableau
void tab_supp(struct tabd *t);

//Lecture et écriture d'un élément du tableau à une position donnée
void* tab_get(struct tabd *t,int i);

//Ajout d'un nouvel élément en fin de tableau
void tab_addFin(struct tabd *t,void* elt);

//Ajout d'un nouvel élément au loin
void tab_addLoin(struct tabd *t,void* elt, int i);

//Insertion d'un élément dans le tableau à une position donnée
//Les éléments sont décalés
void tab_addDecal(struct tabd *t,void* elt, int i);

//Insertion d'un élément dans le tableau à une position donnée
//L'ancien élément est écrasé
void tab_addEcras(struct tabd *t,void* elt, int i);

//comparaison de valeur de  pointeur
int compare(void* elt1,void* elt2);

//Recherche de la position d'un élément du tableau
int tab_searchpos(struct tabd *t,void* elt, int (*compare)(void*,void*));

#endif