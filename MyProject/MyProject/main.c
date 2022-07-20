//
//  main.c
//  MyProject
//
//  Created by Pierre Lamotte on 1/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h> //bibliothèque mathématiques (carrés,...)
#include <time.h>

int main(int argc, const char * argv[]) {
    int réponse;
    printf("Hello world !\n-Comment allez-vous aujourd'hui ?\n-Je vais très bien et vous ?\n-Bien, merci !\n\n");
    double heure;
    signed char vie;
    vie=3;
    heure=15.45;
    printf("Il est actuellement %fh.\nIl vous reste %d vies.\n\n",heure,vie);
    printf("Quel âge avez-vous ?\n");
    int age;
    scanf("%d",&age);
    printf("Bien, vous avez %d ans.\n\n",age);
    int somme=age+vie;
    printf("Votre âge additionné à votre nombre de vie vaut %d.\n",somme);
    printf("Êtes-vous capable de me donner le nombre de vies que vous possédez ?\n");
    scanf("%d)",&réponse);
    if(réponse==vie){
        printf("En effet, vous avez %d vies.😀\n\n",vie);
    }
    else{
        printf("Non, vous avez %d vies car %d-%d=%d.\nIl s'agit pourtant d'un calcul élémentaire...🤔\n\n",vie,somme,age,vie);
    }
    double tertio=-3.4/4.5;
    printf("-3.4/4.5=%f\n",tertio);
    double valeurAbsolue=fabs(tertio);//Valeur absolue
    printf("En valeur absolue, cela donne : %f.\n",valeurAbsolue);
    double puissance=pow(valeurAbsolue,4);//Puissance et exposants
    printf("Élevons %f à la puissance 4. Le résultat vaut : %f.\n",valeurAbsolue,puissance);
    double racCub=cbrt(puissance);
    printf("Prenons-en la racine cubique : cbrt(%f)=%f.\n\n",puissance,racCub);
    int choix;
    printf("===Menu===\n1. Royal Cheese\n2. Mc Deluxe\n3. Mc Bacon\n4. Big Mac\nQuel est votre choix ?\n");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            printf("Vous avez sélectionné le Royal Cheese.\n");
            break;
        case 2:
            printf("Vous avez choisi le Mc Deluxe.\n");
            break;
        case 3:
            printf("Vous voulez un McBacon.\n");
            break;
        case 4:
            printf("Vous choisissez de prendre un Big Mac.\n");
            break;
        default:
            printf("Désolé, je n'ai pas compris votre demande.\n");
    }
    printf("Bon appétit.\n\n");
    for (int i=3;i<16;i++){
        if(i%3==0){
            printf("%d\n",i);
        }
    }
    printf("Ces nombres sont multiples de 3.\n\n");
    for (int i=190;i>0;i-=7) {
        if(i%2==0){
            printf("%d est un nombre pair.\n",i);
        }
        switch (i) {
            case 176:
                printf("Coucou !\n");
                break;
            case 92:
                printf("Tu veux voir ma...\n");
            default:
                break;
        }
    }
    printf("\n");
    for (int i=150;i>0;i--) {
        switch (i) {
            case 96:
                printf("S");
                break;
            default:
                printf("$");
                break;
        }
    }
    printf("\nA quelle position se trouve le \"S\" ?\n");
    scanf("%d",&réponse);
    if (réponse==96) {
        printf("Vous avez une bonne vue !");
    }
    else{
        printf("Désolé mais ce n'est pas la bonne position...\nAllez chez l'ophtalmologue 🤓.");
    }
    if(réponse!=96){
        printf("\n\n");
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
    }
    printf("\n\nL'emplacement de la variable réponse est %p\n\n",&réponse);//Indication de l'emplacement de lavariable "réponse" dans la mémoire
    return 0;
}
