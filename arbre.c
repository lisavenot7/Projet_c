#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.h"

//Creation d'un arbre
struct arbre* arbre_init(const char * m){
    struct arbre *a=(struct arbre*)malloc(sizeof(struct arbre));
    if(a==NULL){
        return NULL;
    }
    a->noeud=node_init(m);
    if((a->noeud)==NULL){
        free(a);
        return NULL;
    }
    return a;
}

struct noeud* node_init(const char * m ){
    struct noeud *n=(struct noeud*)malloc(sizeof(struct noeud));
    if(n==NULL){
        return NULL;
    }
    n->occurence=1;
    n->mot=m;
    n->tab_noeud=tableau_init(2,2);
    if((n->tab_noeud)==NULL){
        free(n);
        return NULL;
    }
    return n;
}

//Cherche un ngramme dans l'arbre
//peut completé l'arbre si il manque des mots a certains niveaux
//retourne un pointeur vers un noeud
struct noeud* cherche_ngramme(struct arbre *a){
    struct noeud *n=((a)->noeud);
    struct tabd *t=((n)->tab_noeud);

    while(sequence_itHasNext()==1){
        const char * mot=sequence_itNext();
        int indice=tab_searchpos(t,(char*)mot,&compare);
        if(indice!=-1){
            n=tab_get(t,indice);
        }
        else{
            struct noeud *n2=node_init(mot);
            if(n2==NULL){
                return NULL;
            }
            tab_addFin(t,n2);
            n=n2;
        }
    }
    return n;
}

//Cherche un mot dans les noeuds feuilles depuis le noeud final
//du chemin d'un N-gramme
//si il existe son occurence sera incrémenté de 1
//sinon on le créera et mettra son occurence à 1
const char* cherche_mot(struct noeud *n,const char* m){
    const char * mot;
    for(int i=0; i<((n->tab_noeud)->t) ;i++){
        if((n->mot)==m){
            mot=(n->mot);
            (n->occurence)=(n->occurence)+1;
        }
    }
    if (mot==NULL){
        struct noeud *n2=node_init(mot);
        if(n2==NULL){
            return NULL;
        }
        tab_addFin((n->tab_noeud),n2);      
    }
    return mot;
}

//Cherche le mot avec le plus d'occurences
//dans les noeuds feuilles depuis le noeud final du chemin
//d'un N-gramme
const char* cherche_mot_max(struct noeud *n){
    struct noeud *node=(tab_get((n->tab_noeud),0));
    const char * m=(node->mot);
    int oc_max=(node->occurence);
    for(int i=1; i<((n->tab_noeud)->t) ;i++){
        node=(tab_get((n->tab_noeud),i));
        if((node->occurence)>oc_max){
            m=(node->mot);
            oc_max=(node->occurence);
        }
    }
    return m;
}
