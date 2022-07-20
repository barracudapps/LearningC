//
//  FicheIdentite.c
//  Coordonnées
//
//  Created by Pierre Lamotte on 5/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include "FicheIdentite.h"
#include "Joueur.h"
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Joueur();

void FicheIdentite(int num){
    printf("\nVoici ta fiche d'identité:\nPrénom: %s\nNom: %s\nÂge: %d\nSexe: %s\nAdresse: %s\nTél.: %s\n\n",joueur[num].prenom,joueur[num].nom,joueur[num].age,sexe2,joueur[num].adresse,joueur[num].numero);
}
