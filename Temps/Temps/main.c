//
//  main.c
//  Temps
//
//  Created by Pierre Lamotte on 3/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void DecoupeHeures(int *pHeures,int *pMin);

int main(int argc, const char * argv[]) {
    int heures=0;
    int minutes=0;
    printf("Quel temps voulez-vous transformer dans le SI ?\n");
    printf("Heures: ");
    scanf("%d",&heures);
    printf("Minutes: ");
    scanf("%d",&minutes);
    DecoupeHeures(&heures,&minutes);
    printf("Le résultat est: %dheures et %dminutes.\n\n",heures,minutes);
    return 0;
}
void DecoupeHeures(int *pHeures,int *pMin){
    *pHeures=*pHeures+*pMin/60;
    *pMin=*pMin%60;
}
