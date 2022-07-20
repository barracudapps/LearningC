//
//  main.c
//  String
//
//  Created by Pierre Lamotte on 4/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>//Inclut la bibliothèque de String

#define TAILLE_MAX 30//Définit une valeur pour tous les "TAILLE_MAX", remplacés par cette valeur à la compilation
                     //Ce n'est pas une variable !!
#define HEURE_DE_COMPILATION() printf("%s",__TIME__);//Définit une fonction qui remplacera toutes les itérations de "HEURE_DE_COMPILATION"
#define PETIT_NOM(taille) if(taille<10)\
                          printf("Ton prénom contient mois de 10 lettres.");//Définit une fonction qui prend des paramètres

int main(int argc, const char * argv[]) {
    HEURE_DE_COMPILATION()
    printf("\n\n");
    char prenom[TAILLE_MAX];
    char copie[TAILLE_MAX];
    char nom[TAILLE_MAX];
    char *suite;
    int longueurPrenom;
    printf("Quel est ton prénom jeune Padawan ?\n");
    scanf("%s",prenom);
    printf("Tu t'appelles donc %s.\n",prenom);
    longueurPrenom=strlen(prenom);//Compte le nombre de caractères contenus dans le tableau de char
    printf("Sais-tu que ton prénom contient %d lettres ?\n",longueurPrenom);
    PETIT_NOM(strlen(prenom))
    printf("\n");
    strcpy(copie,prenom);//Permet de réaliser une copie de la chaine de caractère sélectionnée
    printf("Je vais copier ton nom...\n%s.\n",copie);
    printf("Quel est ton nom de famille à présent ?\n");
    scanf("%s",nom);
    strcpy(copie,nom);
    if(strcmp(prenom,nom)==0){//Compare les chaines de caractères
        printf("Tu as le même nom que ton prénom.\n");
    }
    strcat(prenom,nom);//La chaine de caractères "prenom" devient "prenom+nom"
    printf("Tu t'appelles donc %s.\n\n",prenom);
    suite=strchr(prenom,'L');//Cherche la suite du String désigné à partir du caractère "L"
    if(suite!=NULL){
        printf("Voici la fin de ton nom à partir de la première lettre \"L\": %s\n",suite);
    }
    suite=strstr(prenom,copie);//Cherche le String copie dans le string prenom
    if(suite!=NULL){
        printf("Ton nom est %s.\n\n",suite);
    }
    printf("Vous êtes à la ligne %d du fichier %s.\n",__LINE__,__FILE__);//Indique la ligne à laquelle ceci est écrit et le nom du ficher dans lequel c'est enregistré
    printf("Le fichier a été compilé le %s à %s.\n\n",__DATE__,__TIME__);//Indique la date et l'heure de la compilation
    return 0;
}
