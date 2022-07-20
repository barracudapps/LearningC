//
//  main.m
//  Securisation
//
//  Created by Pierre Lamotte on 10/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int Lecture(char* chaine,int longueur);
int ReplaceDot(char* chaine,int longueur);
void viderBuffer();
double LireDouble();

int main(int argc, const char * argv[]) {
    char nom[10];
    double poids;
    long i;
    printf("Quel est votre nom ?\n");
    fgets(nom,10,stdin);//Même fonction que "scanf" mais interdit les buffer overflow
    printf("Vous êtes donc le fameux %s dont j'ai tant entendu parler...\n",nom);
    printf("\nRéessayons... Quel est votre nom ?\n");
    Lecture(nom,10);
    printf("Vous vous appelez %s...\n\n",nom);
    //Conversion de String en long
    i=strtol("148",NULL,10);//Récupère le long dans le String ssi il débute la chaîne
    printf("%ld\n",i);
    i=strtol("148 Fleurs",NULL,10);//i=148
    printf("%ld\n\n",i);
    printf("Quel est ton poids %s ?\n",nom);
    poids=LireDouble();
    printf("Tu pèses %f kg.\n\n",poids);
    return 0;
}
//Supprimer le "\n" enregistré par "fgets"
int Lecture(char* chaine,int longueur){
    char* position1=NULL;
    if(fgets(chaine,longueur,stdin)!=NULL){
        position1=strchr(chaine,'\n');//Recherche du caractère "\n"
        if(position1!=NULL){
            *position1='\0';//Remplace le "\n" par "\0" (fin de String)
        }
        else{
            viderBuffer();
        }
        return 1;
    }
    else{
        viderBuffer();
        return 0;
    }
}
//Supprimer les caractères en overflow
void viderBuffer(){
    int c=0;
    while(c!='\n'&&c!=EOF){
        c=getchar();
    }
}
//Conversion en double
double LireDouble(){
    char nombre[100];
    if(ReplaceDot(nombre,100)){
        return strtod(nombre,NULL);
    }
    else{
        return 0;
    }
}
//Remplace une virgule par un point
int ReplaceDot(char* chaine,int longueur){
    char* position1=NULL;
    if(fgets(chaine,longueur,stdin)!=NULL){
        position1=strchr(chaine,',');//Recherche du caractère ","
        if(position1!=NULL){
            *position1='.';//Remplace le "," par "."
        }
        else{
            viderBuffer();
        }
        return 1;
    }
    else{
        viderBuffer();
        return 0;
    }
}
