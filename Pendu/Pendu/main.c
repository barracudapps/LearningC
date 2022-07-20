//
//  main.m
//  Pendu
//
//  Created by Pierre Lamotte on 9/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define TAILLE_MAX 1000
#define MIN 1

char LireCaract();
int Dictionnaire();
int nombreMots=0;
int rechercheLettre(char lettre,char motSecret[],int lettreTrouvee[]);
int Reussi(int lettreTrouvee[],long tailleMot);

int main(int argc, const char * argv[]){
    int* recherchee;
    char motX[30];
    char car;
    int vies;
    int réponse=1;
    int taille;
    int diff;
    while(réponse==1){
        printf("Veuillez choisir votre niveau de  difficulté.\n\n");
        printf("1. Facile (15 tentatives)\n");
        printf("2. Difficile (10 tentatives)\n");
        printf("3. Extrême (6 tentatives)\n");
        do{
            printf("Quel est votre choix ?\n");
            scanf("%d",&diff);
        }while(diff<1||diff>3);
        if(diff==1){
            vies=15;
        }
        else if(diff==2){
            vies=10;
        }
        else{
            vies=6;
        }
        nombreMots=0;
        Dictionnaire();
        int MAX=nombreMots;
        srand(time(NULL));
        int myst=(rand()%(MAX-MIN+1))+MIN;
        FILE* file=fopen("Dico.strings","r");
        if(file!=NULL){
            for(int i=0;i<myst;i++){
                fgets(motX,30,file);
            }
            //printf("%d %s",myst,motX);
            fclose(file);
        }
        else{
            printf("ERREUR: Accès au fichier impossible !");
        }
        printf("\nLe mot mystère est:\n");
        taille=strlen(motX)-1;
        for(int i=0;i<taille;i++){
            printf("*");
        }
        int lettreTrouvee[taille];
        printf("\n");
        while(vies>0&&!Reussi(lettreTrouvee,taille)){
            printf("\nIl vous reste %d vies.\nQuelle lettre proposez-vous ?\n",vies);
            car=LireCaract();
            if(!rechercheLettre(car,motX,lettreTrouvee)){
                vies--;
            }
            for (int i=0;i<taille;i++){
                if(lettreTrouvee[i]){
                    printf("%c",motX[i]);
                }
                else{
                    printf("*");
                }
            }
        }
        if(Reussi(lettreTrouvee,taille)){
            printf("\n\nFélicitations, vous avez trouvé !\nLe mot secret etait bien \"%s\"",motX);
        }
        else{
            printf("\n\nDommage, vous n'avez pas réussi...\nLe mot secret etait \"%s\"", motX);
        }
        printf("\n\n");
        do{
            printf("Voulez-vous rejouer une partie ?\n1.Oui\n2.Non\n");
            scanf("%d",&réponse);
        }while(réponse<1||réponse>2);
        printf("\nAu revoir et à bientôt...\n\n");
    }
    return 0;
}
//Récupérer un et un seul caractère entré (contrairement au "scanf" qui récupère \n en plus
char LireCaract(){
    char caract=getchar();
    caract=toupper(caract);//Met la lettre lue en majuscule
    while(getchar()!='\n');
    return caract;
}
//Créer un dictionnaire de mots
int Dictionnaire(){
    FILE* fichier=NULL;
    fichier=fopen("Dico.strings","w");
    if(fichier!=NULL){
        fprintf(fichier,"BOUTEILLE\nCAGE\nOUVERTURE\nBAPTEME\nTOUPILLE\nCOUVERTURE\nGLADIATEUR\nPOUBELLE\nPOULE\nTORTUE\nCABLE\nELECTRONIQUE\nMARECHAL\nANALPHABETISATION\nPORTAIL\nMONSTRE\nLAXATIF\nPOPULATION\nCRAMPE\nVOITURE\nMARQUE\nCHASSEUR\nSTATUE\nSITUATION\nLOCALISATION\nGENDARMERIE\nSMARTPHONE\nORDINATEUR\nAMOUR\nBOUQUET\nCERCLE\nPUISSANCE\nEXPOSITION\nPEINTRE\nPAPILLON\nTIGRE\nSCOUTISME\nCARTABLE\nDIVAN\nARCHEOLOGIE\nMISSISSIPI\nXYLOPHONE\nBLEU\nROUGE\nORCHESTRE\nCORAIL\nSOURIS\nCOURT\nVILLE\nCARGAISON\nREPOS\nPRENDRE\nDISPENSER\nEXAMINER\nVERIFIER\nMALADIE\nTAXIDERMIE\nLONGUEUR\nIMAGINATION\nREBELLION\nILLUSION\nPROPRETE\nMUSEE\nTARDIF\nGENDRE\nATTACHE\nCOURONNE\nMAGNIFIQUE\nSCOLARITE\nCARDINAL\nNORVEGE\nRWANDA\nAUSTRALIE\nPRESIDENTIELLE\nLUXURE\nESPIONNAGE\nCOURSIER\nBALADE\nCAVALIER\nECURIE\nAUTOMOBILE\nMOBILITE\nTRANSPORT\nVOIRIE\nPERSE\nPRUSSE\nGUERRE\nUNIVERS\nSATURNE\nJUPITER\nRELATIVITE\nTHEORIE\nRELATIVITE\nETREINTE\nEINSTEIN\nTESLA\nGAUSS\nMETRE\nLITRE\nMORTALITE\nPUERIL\nEDUCATION\nCALIN\nPOINCARRE\nCURIE\nGEOPOLITIQUE\nEXTREMITE\nVERSEAU\nPANTHERE\nBALANCE\nSAGESSE\nEMPATHIE\nPHASE\nFUSION\nNUCLEAIRE\nCENTRE\nARBITRAIRE\nCROYANCE\nFOOTBALL\nGYMNASTE\nATHLETE\nCOUPURE\nVOLT\nSURF\nTROU\nINGENIERIE\nCONSTITUTION\nCANADA\nCABANE\nTERRITOIRE\nAMPHITHEATRE\nCURSUS\nBLOC\nUNIVERSITE\nGRECE\nANTIQUITE\nPHILOSOPHIE\nPENSEE\nIMAGE\nDROIT\nCOUPABLE\nJUGEMENT\nGRAVITE\nORBITE\nASTRONOMIE\nQUANTIQUE\nPHYSIQUE\nMATHEMATIQUES\nFRANCAIS\nANGLAIS\nACADEMIQUE\nBEURRE\nPUITS\nMETAL\nFERROVIAIRE\nAERONAUTIQUE\nROMANCE\nROMANTIQUE\nSANGLOTS\nMUSIQUE\nSAMILIARITE\nCARRELAGE\nVITRE\nTOITURE\nOSSATURE\nJEUX\nCAMESCOPE\nPOELE\nMURAILLE\nCHINE\nRUSSIE\nAFGHANISTAN\nMEDAILLE\nEPAULER\nSOUTENIR\nVESTIBULE\nLACUNE\nDAUPHIN\nCLOISON\nPHOBIE\nRELIGION\nTARTARE\nCIEUX\nCANICHE\nDOGUE\nPERSAN\nRACE\nBUILDING\nBOISSON\nVIGNOBLE\nCHATEAU\nARCHER\nGRUE\nMANUEL\nSERPE\nFAUCHEUSE\nSOMBRE\nALLEMAGNE\nPERTE\nCOURAGE\nFORCE\nBULLE\nZONE\nFILMOGRAPHIE\n");
        fclose(fichier);
    }
    else{
        printf("ERREUR: Accès au fichier impossible !");
    }
    fichier=fopen("Dico.strings","r");
    char chaine[TAILLE_MAX];
    if(fichier!=NULL){
        while(fgets(chaine,TAILLE_MAX,fichier)!=NULL){
            nombreMots++;
            //printf("%s",chaine);
        }
        //printf("\n%d mots\n",nombreMots);
        fclose(fichier);
    }
    else{
        printf("ERREUR: Accès au fichier impossible !");
    }
    fseek(fichier,0,SEEK_SET);
    return 0;
}
//Réussite
int Reussi(int lettreTrouvee[],long tailleMot){
    int réussi=1;
    for(int i=0;i<tailleMot;i++){
        if(lettreTrouvee[i]==0){
            réussi=0;
        }
    }
    return réussi;
}
//Recherche de lettre
int rechercheLettre(char lettre,char motSecret[],int lettreTrouvee[]){
    int bonneLettre=0;
    // On parcourt motSecret pour vérifier si la lettre proposée y est
    for(int i=0;motSecret[i]!='\0';i++){
        if(lettre==motSecret[i]){// Si la lettre y est
            bonneLettre = 1; // On mémorise que c'était une bonne lettre
            lettreTrouvee[i] = 1; // On met à 1 la case du tableau de booléens correspondant à la lettre actuelle
        }
    }
    return bonneLettre;
}
