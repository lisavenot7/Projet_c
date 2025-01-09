#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableaud.h"



//Initialisation du tableau         
struct tabd* tableau_init(int c,int taille){
    if(c<=0){
        return NULL;
    }
    struct tabd *t=(struct tabd*)malloc(sizeof(struct tabd));
    if(t==NULL){
        return NULL;
    }
    t->coef=c;
    t->t=0;
    t->tmax=taille;
    t->tab=(void**)malloc(t->tmax*sizeof(void*));
    if((t->tab)==NULL){
        return NULL;
        free (t);
    }
    for(int i=0;i<(t->tmax);i++){
        (t->tab)[i]=NULL;
    }
    return t;
}

//Suppression d'un tableau
void tab_supp(struct tabd *t){
    free(t->tab);
    free(t);
}

//Lecture et écriture d'un élément du tableau à une position donnée
void* tab_get(struct tabd *t,int i){
    if(i<(t->tmax)){
        return (t->tab)[i];
    }
    return NULL;
}

//Ajout d'un nouvel élément en fin de tableau
void tab_addFin(struct tabd *t,void* elt){
    if ((t->t)==t->tmax){
        t->tmax=(t->coef)*(t->tmax);
        t->tab=(void**)realloc(t->tab,(t->tmax)*sizeof(void*));
        for(int j=(t->t);j<(t->tmax);j++){
            (t->tab)[j]=NULL;
        }
    }
    (t->tab)[t->t]=elt;
    t->t=(t->t)+1;
}

//Ajout d'un nouvel élément au loin
void tab_addLoin(struct tabd *t,void* elt, int i){
    if (i>=t->tmax){
        t->tmax=(t->coef)*(t->tmax);
        t->tab=(void**)realloc(t->tab,(t->tmax)*sizeof(void*));
        for(int j=(t->t);j<(t->tmax);j++){
            (t->tab)[j]=NULL;
        }
    }
    (t->tab)[i]=elt;
    t->t=i+1;
}

//Insertion d'un élément dans le tableau à une position donnée
//Les éléments sont décalés
void tab_addDecal(struct tabd *t,void* elt, int i){
    if (i>=t->tmax){
        t->tmax=(t->coef)*(t->tmax);
        t->tab=(void**)realloc(t->tab,(t->tmax)*sizeof(void*));
        for(int j=(t->t);j<(t->tmax);j++){
            (t->tab)[j]=NULL;
        }
    }
    for(int k=(t->tmax);k>i;k--){
        (t->tab)[k]=(t->tab)[k-1];
    }
    (t->tab)[i]=elt;
    t->t=(t->t)+1;
}

//Insertion d'un élément dans le tableau à une position donnée
//L'ancien élément est écrasé
void tab_addEcras(struct tabd *t,void* elt, int i){
    if (i>=t->tmax){
        t->tmax=(t->coef)*(t->tmax);
        t->tab=(void**)realloc(t->tab,(t->tmax)*sizeof(void*));
        for(int j=(t->t);j<(t->tmax);j++){
            (t->tab)[j]=NULL;
        }
    }
    
    (t->tab)[i]=elt;
}

//a changer
//Recherche de la position d'un élément du tableau
int tab_searchpos(struct tabd *t,void* elt, int (*compare)(void*,void*)){
    for(int i=0;i<(t->tmax);i++){
        if((t->tab)[i]!=NULL){
            if(compare((t->tab)[i],elt)==1){
                return i;
            }
        }
    }
    return -1;
}

























