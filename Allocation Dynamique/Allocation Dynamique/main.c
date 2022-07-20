//
//  main.m
//  Allocation Dynamique
//
//  Created by Pierre Lamotte on 9/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Coordonnees{
    int x;
    int y;
};

int main(int argc, const char * argv[]) {
    int* memoireAllouee=malloc(sizeof(struct Coordonnees));//Réserve de la place en mémoire
    if(memoireAllouee==NULL){
        exit(0);
    }
    printf("La variable 'int' prend %d octets de mémoire\n",sizeof(int));//Indique la mémoire occupée par un "int"
    printf("La variable 'char' prend %d octets de mémoire\n",sizeof(char));
    printf("La variable 'long' prend %d octets de mémoire\n",sizeof(long));
    printf("La variable 'double' prend %d octets de mémoire\n",sizeof(double));
    printf("La structure 'Coordonnees' prend %d octets de mémoire\n",sizeof(struct Coordonnees));
    printf("La mémoire allouée prend %d octets\n",memoireAllouee);
    free(memoireAllouee);//Libère la mémoire réservée
    //Allocation dynamique d'un tableau
    int *ageAmis;
    int nombreAmis;
    printf("\nCombien d'amis avez-vous ?\n");
    scanf("%d",&nombreAmis);
    if(nombreAmis>0){
        ageAmis=malloc(nombreAmis*sizeof(int));
        if(ageAmis==NULL){
            exit(0);
        }
        for(int i=0;i<nombreAmis;i++){
            printf("Quel est l'âge de l'ami n°%d ? ",i+1);
            scanf("%d",&ageAmis[i]);
        }
        printf("\nVos amis ont les âges suivants:\n");
        for(int i=0;i<nombreAmis;i++){
            printf("%d ans\n",ageAmis[i]);
        }
        printf("\n");
        free(ageAmis);
    }
    return 0;
}
