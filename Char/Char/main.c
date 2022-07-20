//
//  main.c
//  Char
//
//  Created by Pierre Lamotte on 3/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char tab[7]={'a','b','c','d','e','f','\0'};
    for(int i=0;i<6;i++){
        printf("%c",tab[i]);
    }
    printf("\n");
    printf("%s",tab);//Equivalent à la boucle ci-dessus mais indique directement qu'il s'agit d'un String
    printf("\n\n");
    char tab2[20];
    printf("Quel est ton nom jeune Padawan ?\n");
    scanf("%s",tab2);//Inscrit le String reçu, caractère par caractère, dans le tablezu de char
    printf("Bonjour Padawan %s.\n\n",tab2);
    return 0;
}
