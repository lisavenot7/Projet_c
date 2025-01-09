#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.h"

int compare(void* elt1,void* elt2){
    struct noeud *n=elt1;
    if(*(n->mot)==*(const char*)elt2){
        return 1;
    }
    return -1;
}


int main(void){

    //Création d'un premier N_gramme
    struct strhash_table * ht = strhash_create(10);
    sequence_initialize(ht);
    sequence_itStart();
    sequence_addWord("Le",ht);
    sequence_progress();
    sequence_addWord("petit",ht);
    sequence_progress();
    sequence_addWord("chat",ht);
    sequence_progress();
    sequence_addWord("blanc",ht);
    sequence_progress();
    
    struct arbre * a=arbre_init("");
    struct noeud *n=cherche_ngramme(a);

    //Création d'un second N_gramme
    sequence_addWord("Un",ht);
    sequence_progress();
    sequence_addWord("grand",ht);
    sequence_progress();
    sequence_addWord("chat",ht);
    sequence_progress();
    sequence_addWord("noir",ht);
    sequence_progress();

    n=cherche_ngramme(a);

    //Création d'un troisième N_gramme
    sequence_addWord("Un",ht);
    sequence_progress();
    sequence_addWord("petit",ht);
    sequence_progress();
    sequence_addWord("chat",ht);
    sequence_progress();
    sequence_addWord("marron",ht);
    sequence_progress();
    
    cherche_ngramme(a);
    cherche_mot(n,"marron");

    //Création d'un quatriième N_gramme
    sequence_addWord("Un",ht);
    sequence_progress();
    sequence_addWord("petit",ht);
    sequence_progress();
    sequence_addWord("chat",ht);
    sequence_progress();
    sequence_addWord("noir",ht);
    sequence_progress();

    cherche_mot(n,"noir");
    cherche_mot(n,"marron");
    printf("%s\n",cherche_mot_max(n));

    







    }