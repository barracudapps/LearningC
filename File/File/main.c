//
//  main.m
//  File
//
//  Created by Pierre Lamotte on 6/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE_MAX 1000

int main(int argc, const char * argv[]) {
    long curseur1;
    int age;
    int temp=0;
    int scores[3]={67,54,12};
    char chaine[TAILLE_MAX];
    FILE* fichier=NULL;//Déclaration d'un pointeur de fichier initialisé à NULL
    fichier=fopen("/Users/Baracuda/Documents/Cours/Créations C/File/File/test","w");//Ouvre le fichier "test.txt" en mode lecture/écriture
    if(fichier!=NULL){
        //Ecriture
        fputc('A',fichier);//Insère un seul caractère dans le fichier
        fputs("\nHello toi !\n",fichier);//Ecrit des chaînes dans le fichier sans l'afficher
        fprintf(fichier,"Bonjour toi !\n");//Idem
        printf("Quel âge as-tu ?\n");
        scanf("%d",&age);
        fprintf(fichier,"Il a %d ans.\n",age);
        fclose(fichier);
    }
    else{
        printf("ERREUR: Accès au fichier impossible.\n");
    }
    printf("\n");
    fichier=fopen("/Users/Baracuda/Documents/Cours/Créations C/File/File/test","r");
    if(fichier!=NULL){
        //Lecture
        fscanf(fichier,"%d %d %d",&scores[0],&scores[1],&scores[2]);//Récupère les données de "scores"
        printf("Les meilleurs scores sont: %d, %d et %d\n",scores[0],scores[1],scores[2]);
        do{
            temp=fgetc(fichier);//Lecture d'un caractère
            printf("%c",temp);//Affichage du caractère
        }while(temp!=EOF);//Continue le boucle jusqu'à la fin du fichier
        fclose(fichier);
    }
    else{
        printf("ERREUR: Accès au fichier impossible.\n");
    }
    printf("\n");
    fichier=fopen("/Users/Baracuda/Documents/Cours/Créations C/File/File/test","r");
    if(fichier!=NULL){
        while(fgets(chaine,TAILLE_MAX,fichier)!=NULL){
            printf("%s",chaine);
        }
        curseur1=ftell(fichier);
        printf("\nPosition du curseur: %d\n",curseur1);
        fseek(fichier,5,SEEK_SET);//Déplace le curseur à la 5e position après le début du fichier (SEEK_CUR=position actuelle, SEEK_SET=début de fichier, SEEK_END=fin de fichier)
        curseur1=ftell(fichier);
        printf("Position du curseur: %d\n",curseur1);
        fseek(fichier,-2,SEEK_CUR);
        curseur1=ftell(fichier);
        printf("Position du curseur: %d\n",curseur1);
        fseek(fichier,-19,SEEK_END);
        curseur1=ftell(fichier);
        printf("Position du curseur: %d\n",curseur1);
        fclose(fichier);
    }
    else{
        printf("ERREUR: Accès au fichier impossible.\n");
    }
    //rename("/Users/Baracuda/Documents/Cours/Créations C/File/File/test","/Users/Baracuda/Documents/Cours/Créations C/File/File/test2");//Renomme le fichier
    //remove("/Users/Baracuda/Documents/Cours/Créations C/File/File/test");//Supprime le fichier
    printf("\n");
    return 0;
}
