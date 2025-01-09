#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sequence.h"

//initialisation
int main(void){

    /*//MAIN NON AUTOMATISE
    struct strhash_table * ht = strhash_create(10);
    sequence_initialize(ht);

    printf("----Test avec des mots vides-----\n");
    sequence_itStart();
    printf("Affichage mot par mot: \n");
    sequence_print();
    printf("Affichage d'une phrase: \n");
    printf("%s\n",sequence_printInTab());
    printf("\n");

    printf("----Avec 1 mot non vide-----\n");
    sequence_addWord("Le",ht);
    printf("Mot ajouté:%s\n",sequence_nextWord());
    sequence_progress();
    printf("Affichage mot par mot: \n");
    sequence_print();
    printf("Affichage d'une phrase: \n");
    printf("%s\n",sequence_printInTab());
    printf("\n");


    printf("----Avec 2 mots non vide-----\n");
    sequence_addWord("petit",ht);
    printf("Mot ajouté:%s\n",sequence_nextWord());
    sequence_progress();
    printf("Affichage mot par mot: \n");
    sequence_print();
    printf("Affichage d'une phrase: \n");
    printf("%s\n",sequence_printInTab());
    printf("\n");

    printf("----Avec 3 mots non vide-----\n");
    sequence_addWord("chat",ht);
    printf("Mot ajouté:%s\n",sequence_nextWord());
    sequence_progress();
    printf("Affichage mot par mot: \n");
    sequence_print();
    printf("Affichage d'une phrase: \n");
    printf("%s\n",sequence_printInTab());
    printf("\n");

    printf("----Ajout d'un 4ème mots-----\n");
    sequence_addWord("noir",ht);
    printf("Mot ajouté:%s\n",sequence_nextWord());
    sequence_progress();
    printf("Affichage mot par mot: \n");
    sequence_print();
    printf("Affichage d'une phrase: \n");
    printf("%s\n",sequence_printInTab());
    printf("\n");*/

    //MAIN AUTOMATISE
    struct strhash_table * ht = strhash_create(10);
    sequence_initialize(ht);
    sequence_itStart();
    
    printf("----Test avec des mots vides-----\n");
    char* c=sequence_printInTab();
    char* r="  ";
    if (strcmp(c,r)==0){
        printf("Affichage attendu \n");
        printf("%s /%s\n",c,r );
    }else{
        printf("Affichage non attendu \n");
        printf("%s /%s\n",c,r );
    }    
    
    printf("\n");

    printf("----Avec 1 mot non vide-----\n");
    sequence_addWord("Le",ht);
    sequence_progress();
    c=sequence_printInTab();
    r="  Le";
    if (strcmp(c,r)==0){
        printf("Affichage attendu \n");
        printf("%s /%s\n",c,r );
    }else{
        printf("Affichage non attendu \n");
        printf("%s /%s\n",c,r );
    } 
    printf("\n");


    printf("----Avec 2 mots non vide-----\n");
    sequence_addWord("petit",ht);
    sequence_progress();
    c=sequence_printInTab();
    r=" Le petit";
    if (strcmp(c,r)==0){
        printf("Affichage attendu \n");
        printf("%s /%s\n",c,r );
    }else{
        printf("Affichage non attendu \n");
        printf("%s /%s\n",c,r );
    } 
    printf("\n");

    printf("----Avec 3 mots non vide-----\n");
    sequence_addWord("chat",ht);
    sequence_progress();
    c=sequence_printInTab();
    r="Le petit chat";
    if (strcmp(c,r)==0){
        printf("Affichage attendu: \n");
        printf("%s /%s\n",c,r );
    }else{
        printf("Affichage non attendu \n");
        printf("%s /%s\n",c,r );
    }
    printf("\n");

    printf("----Ajout d'un 4ème mots-----\n");
    sequence_addWord("noir",ht);
    sequence_progress();
    c=sequence_printInTab();
    r="petit chat noir";
    if (strcmp(c,r)==0){
        printf("Affichage attendu \n");
        printf("%s /%s\n",c,r );
    }else{
        printf("Affichage non attendu \n");
        printf("%s /%s\n",c,r );
    }
    printf("\n");

    printf("----Ajout d'un 5ème mots-----\n");
    sequence_addWord("marche",ht);
    sequence_progress();
    c=sequence_printInTab();
    r="chat noir m";
    if (strcmp(c,r)==0){
        printf("Affichage attendu \n");
        printf("%s /%s\n",c,r );
    }else{
        printf("Affichage non attendu \n");
        printf("%s /%s\n",c,r );
    }
    printf("\n");



    }