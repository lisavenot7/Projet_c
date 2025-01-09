#ifndef _STRARBRE_H_
#define _STRARBRE_H_

#include "sequence.h"
#include "tableaud.h"

struct noeud{
    struct tabd *tab_noeud;
    int occurence;
    const char * mot;
};

struct arbre{
    struct noeud *noeud;
};
//Initialisation d'un arbre
struct arbre* arbre_init(const char * m);

//Initialisation d'un noeud
struct noeud* node_init(const char *m);

//Cherche un ngramme dans l'arbre
//peut completé l'arbre si il manque des mots a certains niveaux
//retourne un pointeur vers un noeud
struct noeud* cherche_ngramme(struct arbre *a); //ngramme=sequence_printInTab()

//Cherche un mot dans les noeuds feuilles depuis le noeud final
//du chemin d'un N-gramme
//si il existe son occurence sera incrémenté de 1
//sinon on le créera et mettra son occurence à 1
const char* cherche_mot(struct noeud *n,const char* mot);

//Cherche le mot avec le plus d'occurences
//dans les noeuds feuilles depuis le noeud final du chemin
//d'un N-gramme
const char* cherche_mot_max(struct noeud *n);

#endif