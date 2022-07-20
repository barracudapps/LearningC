//
//  main.c
//  Coordonnées
//
//  Created by Pierre Lamotte on 4/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include "main.h"
#include "Joueur.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Joueur();
void InitialiserCoordonnees();

int main(int argc, const char * argv[]) {
    Coordonnees point;//Structure "Coordonnes"
    InitialiserCoordonnees(&point);
    point.x=3;//Définit l'abscisse du point
    point.y=5;//Définit l'ordonnée du point
    
    Joueur();
    
    return 0;
}
void InitialiserCoordonnees(Coordonnees* point){
    (*point).x=0;
    point->y=0;//Identique à "(*point).y=0;"
}

