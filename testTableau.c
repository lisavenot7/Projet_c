#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tableaud.h"

//comparaison de valeur de pointeur
int compare(void* elt1,void* elt2){
    if(*(int*)elt1==*(int*)elt2){
        return 1;
    }
    return -1;
}

int main(void){

    //Initialisation
    struct tabd * t = tableau_init(2,2);
    printf("------------Initialisation------------\n");
    if (t!=NULL){
        printf("Affichage attendu \n");
    }else{
        printf("Affichage non attendu \n");
    }

    printf("------------Test de addFin------------\n");
    int n1=5;
    tab_addFin(t,&n1);printf("test");
    if (tab_get(t,0)==&n1){
        printf("Affichage attendu \n");
        printf("%d /%d\n",*(int*)tab_get(t,0),*(int*)&n1 );
    }else{
        printf("Affichage non attendu \n");
        printf("%d /%d\n",*(int*)tab_get(t,0),*(int*)&n1 );
    }
    
    int n2=7;
    tab_addFin(t,&n2);
    if (tab_get(t,1)==&n2){
        printf("Affichage attendu \n");
        printf("%d /%d\n",*(int*)tab_get(t,1),*(int*)&n2 );
    }else{
        printf("Affichage non attendu \n");
        printf("%d /%d\n",*(int*)tab_get(t,1),*(int*)&n2 );
    }
    int n3=9;
    tab_addFin(t,&n3);
    if (tab_get(t,2)==&n3){
        printf("Affichage attendu \n");
        printf("%d /%d\n",*(int*)tab_get(t,2),*(int*)&n3 );
    }else{
        printf("Affichage non attendu \n");
        printf("%d /%d\n",*(int*)tab_get(t,2),*(int*)&n3 );
    }
    int n4=8;
    tab_addFin(t,&n4);
    if (tab_get(t,3)==&n4){
        printf("Affichage attendu \n");
        printf("%d /%d\n",*(int*)tab_get(t,3),*(int*)&n4 );
    }else{
        printf("Affichage non attendu \n");
        printf("%d /%d\n",*(int*)tab_get(t,3),*(int*)&n4 );
    }
    printf("------------Test de addLoin------------\n");
    int n5=11;
    tab_addLoin(t,&n5,6);
    if (tab_get(t,0)==&n1 && tab_get(t,1)==&n2 && tab_get(t,2)==&n3 && tab_get(t,3)==&n4 && tab_get(t,6)==&n5){
        printf("Affichage attendu \n");
        printf("%d /%d /%d /%d /%p /%p /%d\n",*(int*)tab_get(t,0),*(int*)tab_get(t,1),*(int*)tab_get(t,2),*(int*)tab_get(t,3),tab_get(t,4),tab_get(t,5),*(int*)tab_get(t,6));
    }else{
        printf("Affichage non attendu \n");
        printf("%d /%d /%d /%d /%p /%p /%d\n",*(int*)tab_get(t,0),*(int*)tab_get(t,1),*(int*)tab_get(t,2),*(int*)tab_get(t,3),tab_get(t,4),tab_get(t,5),*(int*)tab_get(t,6));
    }
    printf("------------Test de addDecal------------\n");
    int n6=13;
    tab_addDecal(t,&n6,3);
    if (tab_get(t,0)==&n1 && tab_get(t,1)==&n2 && tab_get(t,2)==&n3 && tab_get(t,3)==&n6 && tab_get(t,4)==&n4 && tab_get(t,7)==&n5){
        printf("Affichage attendu \n");
        printf("%d /%d /%d /%d /%d /%p /%p /%d\n",*(int*)tab_get(t,0),*(int*)tab_get(t,1),*(int*)tab_get(t,2),*(int*)tab_get(t,3),*(int*)tab_get(t,4),tab_get(t,5),tab_get(t,6),*(int*)tab_get(t,7));
    }else{
        printf("Affichage non attendu \n");
        printf("%d /%d /%d /%d /%d /%p /%p /%d\n",*(int*)tab_get(t,0),*(int*)tab_get(t,1),*(int*)tab_get(t,2),*(int*)tab_get(t,3),*(int*)tab_get(t,4),tab_get(t,5),tab_get(t,6),*(int*)tab_get(t,7));
    }
    printf("------------Test de addEcras------------\n");
    int n7=15;
    tab_addEcras(t,&n7,3);
    if (tab_get(t,0)==&n1 && tab_get(t,1)==&n2 && tab_get(t,2)==&n3 && tab_get(t,3)==&n7 && tab_get(t,4)==&n4 && tab_get(t,7)==&n5){
        printf("Affichage attendu \n");
        printf("%d /%d /%d /%d /%d /%p /%p /%d\n",*(int*)tab_get(t,0),*(int*)tab_get(t,1),*(int*)tab_get(t,2),*(int*)tab_get(t,3),*(int*)tab_get(t,4),tab_get(t,5),tab_get(t,6),*(int*)tab_get(t,7));
    }else{
        printf("Affichage non attendu \n");
        printf("%d /%d /%d /%d /%d /%p /%p /%d\n",*(int*)tab_get(t,0),*(int*)tab_get(t,1),*(int*)tab_get(t,2),*(int*)tab_get(t,3),*(int*)tab_get(t,4),tab_get(t,5),tab_get(t,6),*(int*)tab_get(t,7));
    }
    printf("------------Test de searchPos------------\n");
    if (tab_searchpos(t,&n7,&compare)==3){
        printf("Affichage attendu \n");
    }else{
        printf("Affichage non attendu \n");
    }
   
    printf("------------Suppression------------\n");
    tab_supp(t);
    if (tab_get(t,0)!=&n1){
        printf("Affichage attendu \n");
    }else{
        printf("Affichage non attendu \n");
    }
    }