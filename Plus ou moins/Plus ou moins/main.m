//
//  Jeu du plus/moins.c
//  MyProject
//
//  Created by Pierre Lamotte on 2/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h> //bibliothèque mathématiques (carrés,...)
#include <time.h>

int main(int argc, const char * argv[]){
    printf("_________________________\n");
    printf("***** 𝒫𝓇ℯ𝓂𝒾ℯ𝓇 𝒥ℯ𝓊 *****\n\n");
    int recommencer;
    do{
        printf("         ⦓ℳℯ𝓃𝓊⦔\n\n");
        printf("Choisissez votre niveau de difficulté parmi les propositions suivantes:\n");
        printf("1. Entre 1 et 100\n2. Entre 1 et 1 000\n3. Entre 1 et 10 000\n");
        int answer;
        scanf("%d",&answer);
        printf("\nC'est parti !\n");
        srand(time(NULL));
        const int MIN=1;
        int coups;
        int nombreMystere;
        int rep;
        if(answer==1){
            const int MAX=100;
            nombreMystere=(rand()%(MAX-MIN+1))+MIN;
        }
        else if(answer==2){
            const int MAX=1000;
            nombreMystere=(rand()%(MAX-MIN+1))+MIN;
        }
        else{
            const int MAX=10000;
            nombreMystere=(rand()%(MAX-MIN+1))+MIN;
        }
        do{
            printf("Quel est le Nombre Mystère ?\n");
            scanf("%d",&rep);
            if(rep>nombreMystere){
                printf("C'est moins.\n");
            }
            else if(rep<nombreMystere){
                printf("C'est plus.\n");
            }
            else if(rep==nombreMystere){
                printf("Bravo ! Le nombre mystère était bel et bien %d.\n\n",nombreMystere);
            }
            coups++;//Augmente le nombre de tentatives
        }
        while(rep!=nombreMystere);
        printf("Il vous aura fallu %d tentatives pour réussir.\n\n",coups);
        if(coups>=10){
            Dessin(1);//Fait appel à la fonction "dessin"
        }
        printf("Souhaitez-vous recommencer ?\nSi oui, insérez 1, sinon 0.\n");
        scanf("%d",&recommencer);
        coups=0;
    }
    while(recommencer!=0);
    return 0;
}
int Dessin(int i){//Dessine une croix
    if(i==1){
        for (int i=0;i<3;i++) {
            for (int j=0;j<10;j++) {
                printf(" ");
            }
            printf("😈\n");
        }
        for (int i=0;i<10;i++) {
            printf("😈");
        }
        printf("\n");
        for (int i=0;i<10;i++) {
            for (int j=0;j<10;j++) {
                printf(" ");
            }
            printf("😈\n");
        }
        printf("\n\n");
    }
    return 0;
}
