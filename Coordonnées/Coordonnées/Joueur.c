//
//  Joueur.c
//  Coordonnées
//
//  Created by Pierre Lamotte on 5/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include "Joueur.h"
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Joueur(){
    for(int j=0;j<2;j++){
        char sexe2[10];
        Personne joueur[2];
        printf("Joueur n°%d\n\n",j+1);
        printf("Quel est ton prénom ?\n");
        scanf("%s",joueur[j].prenom);
        printf("Quel est ton nom ?\n");
        scanf("%s",joueur[j].nom);
        printf("Où habites-tu ?\n");
        scanf("%s",joueur[j].adresse);
        printf("Quel est ton numéro de téléphone ?\n");
        scanf("%s",joueur[j].numero);
        printf("Quel âge as-tu ?\n");
        scanf("%d",&joueur[j].age);
        do{
            printf("Es-tu un garçon (1) ou une fille (2) ?\n");
            scanf("%d",&joueur[j].sexe);
        }while(joueur[j].sexe!=1&&joueur[j].sexe!=2);
        if(joueur[j].sexe==1){
            strcpy(sexe2,"Garçon");
        }
        else{
            strcpy(sexe2,"Fille");
        }
        printf("\nVoici ta fiche d'identité:\nPrénom: %s\nNom: %s\nÂge: %d\nSexe: %s\nAdresse: %s\nTél.: %s\n\n",joueur[j].prenom,joueur[j].nom,joueur[j].age,sexe2,joueur[j].adresse,joueur[j].numero);
    }
}
