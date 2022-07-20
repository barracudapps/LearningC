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
#include "AireRectangle.h"

int main(int argc, const char * argv[]){
    int age;
    printf("Quel est votre âge ?\n");
    scanf("%d",&age);
    int *pointeurAge=&age;//Création d'un pointeur sur l'adresse de la variable "age"
    printf("Vous avez %d ans.\n\n",*pointeurAge);//Affiche la valeur de la variable indiquée par le pointeur
    printf("Rectangle de longueur 10 et de largeur 5.\nAire=%f\n\n",AireRectangle(10,5));
    printf("Rectangle de longueur 3.5 et de largeur 2.5.\nAire=%f\n\n",AireRectangle(3.5,2.5));
    printf("Rectangle de longueur 4.2 et de largeur 9.7.\nAire=%f\n\n",AireRectangle(4.2,9.7));
    return 0;
}

