#ifndef _STRSEQUENCE_H_
#define _STRSEQUENCE_H_

#include "hash.h"
//nombre de mots dans les N_grammes
enum{Lg_N_gramme=3};

//initiamise le N_gramme avec des mots vides
void sequence_initialize(struct strhash_table * ht);

//Gestion de l'itérateur permettant de parcourir le N_gramme
//initialise l'itérateur sur le premier mot du N_gramme courant
void sequence_itStart(void);

//retourne le mot correspondant a la position de l'iterateur
//avance la position de l'iterateur
const char* sequence_itNext(void);

//tset si l'itérateur est a la fin du N_gramme
int sequence_itHasNext(void);

//Nouveau mot à la fin du prochain N_gramme
//definit le nouveau mot qui entrera dans le N_gramme
void sequence_addWord(const char* wordi,struct strhash_table * ht);

//retourne le noub=veau mot qui entrera dans le N_gramme
const char * sequence_nextWord(void);

//avance le N_gramme pour integrer le nouveau mot écrit
void sequence_progress(void);

//Debug
//affiche le N_gramme courant, les mots sont separes par des /
void sequence_print(void);

//sequence sous forme d'une chaine de caracteres
char * sequence_printInTab(void);



#endif

