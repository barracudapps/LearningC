//
//  main.c
//  Tableaux
//
//  Created by Pierre Lamotte on 3/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    double tab[5];
    double somme;
    for(int i=0;i<5;i++){
        tab[i]=pow(5,i);
        printf("%f\n",tab[i]);
    }
    for(int i=0;i<5;i++){
        somme+=tab[i];
    }
    printf("La somme des valeurs inscrites dans ce tableau vaut: %f.\n",somme);
    somme=0;
    printf("\n");
    for(int i=0;i<5;i++){
        tab[i]=pow(8,i);
        printf("%f\n",tab[i]);
    }
    for(int i=0;i<5;i++){
        somme+=tab[i];
    }
    printf("La somme des valeurs inscrites dans ce tableau vaut: %f.\n",somme);
    somme=0;
    printf("\n");
    for(int i=0;i<5;i++){
        tab[i]=cbrt(pow(35,sqrt(i)));
        printf("%f\n",tab[i]);
    }
    for(int i=0;i<5;i++){
        somme+=tab[i];
    }
    printf("La somme des valeurs inscrites dans ce tableau vaut: %f.\n",somme);
    printf("\n");
    return 0;
}
