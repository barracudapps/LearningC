//
//  main.h
//  Coordonnées
//
//  Created by Pierre Lamotte on 4/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#ifndef main_h
#define main_h

#include <stdio.h>
#define TAILLE_MAX 200

typedef struct Coordonnees Coordonnees;//Permet de remplacer "struct Coordonnees" par "Coordonnes" dans "main.c"
struct Coordonnees{
    int x;
    int y;
};
typedef struct Personne Personne;
struct Personne{
    char prenom[TAILLE_MAX];
    char nom[TAILLE_MAX];
    char adresse[TAILLE_MAX];
    char numero[TAILLE_MAX];
    int age;
    int sexe;
};
#endif /* main_h */
