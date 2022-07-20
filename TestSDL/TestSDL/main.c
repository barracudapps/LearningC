//
//  main.m
//  TestSDL
//
//  Created by Pierre Lamotte on 13/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void Pause();

int main(int argc, const char * argv[]){
    SDL_Window* screen=NULL;//Retient la surface de l'écran affiché
    SDL_Renderer* renderer=NULL;
    SDL_Texture* sdlTexture=NULL;
    SDL_Surface* ecran=NULL;
    SDL_Surface* rectangle[2]={NULL};
    SDL_Surface* degrade[256]={NULL};
    SDL_Surface* image=NULL;
    SDL_Rect pos3;
    pos3.x=5;
    pos3.y=5;
    SDL_Rect pos2;
    pos2.x=100;
    pos2.y=300;
    SDL_Rect pos;
    pos.x=700;
    pos.y=30;
    SDL_Rect position;
    position.x=955;
    position.y=285;
    if(SDL_Init(SDL_INIT_VIDEO)==-1){//Charge la SDL sur le mode vidéo
        fprintf(stderr,"Erreur d'initialisation de la SDL : %s\n",SDL_GetError());//Ecriture de l'erreur dans un fichier
        exit(EXIT_FAILURE);//Quitte le programme
    }
    screen=SDL_CreateWindow("Test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1350,800,SDL_SWSURFACE);//Parmètres de la fenêtre à ouvrir (Titre,position x,position y,largeur,hauteur, flags)
                                               //SDL_SWSURFACE est lent mais stocke la fenètre là où il y a beaucoup de mémoire
    if(screen==NULL){
        fprintf(stderr,"Impossible de charger le mode vidéo : %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    renderer=SDL_CreateRenderer(screen,-1,0);
    ecran=SDL_CreateRGBSurface(SDL_SWSURFACE,1350,800,32,0,0,0,0);//Création d'une surface de mêmes dimensions que la fenêtre
    for(int i=0;i<256;i++){
        degrade[i]=SDL_CreateRGBSurface(SDL_SWSURFACE,250,1,32,0,0,0,0);
        SDL_FillRect(degrade[i],NULL,SDL_MapRGB(ecran->format,255-i,i,i));
    }
    image=SDL_LoadBMP("/Users/Baracuda/Documents/Cours/Créations C/TestSDL/TestSDL/screen2.bmp");//Charge une image ".bmp"
    SDL_SetWindowIcon(screen,image);//Création de l'icône
    rectangle[0]=SDL_CreateRGBSurface(SDL_SWSURFACE,300,250,32,0,0,0,0);
    rectangle[1]=SDL_CreateRGBSurface(SDL_SWSURFACE,100,50,32,0,0,0,0);
    sdlTexture=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,1350,800);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,0,0));
    SDL_FillRect(rectangle[0],NULL,SDL_MapRGB(ecran->format,5,255,255));
    SDL_FillRect(rectangle[1],NULL,SDL_MapRGB(ecran->format,15,55,255));
    SDL_BlitSurface(rectangle[0],NULL,ecran,&position);
    SDL_BlitSurface(rectangle[1],NULL,ecran,&pos2);
    SDL_BlitSurface(image,NULL,ecran,&pos3);
    for(int i=0;i<256;i++){
        pos.y++;
        pos.x++;
        SDL_BlitSurface(degrade[i],NULL,ecran,&pos);
    }
    //SDL_SetColorKey(rectangle[0],SDL_SRCCOLORKEY,SDL_MapRGB(image->format,5,255,255));//Rend transparente une couleur de l'image
    //SDL_SetSurfaceAlphaMod(rectangle[1],120);//Rend l'image translucide
    SDL_UpdateTexture(sdlTexture,NULL,ecran->pixels,ecran->pitch);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,sdlTexture,NULL,NULL);
    SDL_RenderPresent(renderer);//Relance la fenêtre avec la nouvelle couleur
    Pause();
    SDL_FreeSurface(image);
    for(int i=0;i<256;i++){
        SDL_FreeSurface(degrade[i]);
    }
    SDL_FreeSurface(ecran);//Libération de la surface
    SDL_Quit();//Arrête la SDL
    return EXIT_SUCCESS;
}
//Suspension
void Pause(){
    int continuer=1;
    SDL_Event event;
    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                continuer=0;
        }
    }
}
