#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sequence.h"

static const char* N_gramme[Lg_N_gramme+1];
static int it;
static int pos;

//initialise N_gramme avec des mots vides
void sequence_initialize(struct strhash_table * ht){
    char* m=strhash_wordAdd(ht,"");
    for (int i=0;i<Lg_N_gramme+1;i++){
        N_gramme[i]=m;
    }
    it=0;
    pos=0;
}

//gestion de it qui peut parcourir N_gramme et son initialisation sur le 1er mot courant
void sequence_itStart(void){
    
    if(pos==Lg_N_gramme){it=0;}
    else{it=pos+1;}
}

//retourne le mot a la position de it et avance it 
const char* sequence_itNext(void){
    const char * mot=N_gramme[it];
    if(it==Lg_N_gramme){it=0;}
    else{it++;}
    return mot;
}

//test si it est a la fin de N_gramme
//true = 1        false = 0
int sequence_itHasNext(void){
    if (it==pos){
        return 0;
    }
    else{
        return 1;
    }
   
    
    

}

//definit le nouveau mot qui ira dans N_gramme
void sequence_addWord(const char * wordi, struct strhash_table *ht){
    char* m=strhash_wordAdd(ht,wordi);
    N_gramme[pos]=m;
}

//retourne le nouveau mot qui entrera dans le N_gramme
const char * sequence_nextWord(void){
    return N_gramme[pos];
}

//avance le N_gramme pour integrer le nouveau mot
void sequence_progress(void){
    if(pos==Lg_N_gramme){pos=0;}
    else{pos++;}
}

//affichage de N_gramme
void sequence_print(void){
    sequence_itStart();
    while(sequence_itHasNext()==1){
        printf("-%s\n",sequence_itNext());
    }
    
}

//sequence sous forme de chaine
char * sequence_printInTab(void){
    sequence_itStart();
    static char phrase[250]="";
    strcpy(phrase,"");
    strcat(phrase,sequence_itNext());
    while(sequence_itHasNext()==1){
        strcat(phrase," ");
        strcat(phrase,sequence_itNext());
    }
    return phrase;
}

