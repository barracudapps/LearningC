//
//  main.m
//  SDL Events
//
//  Created by Pierre Lamotte on 20/09/16.
//  Copyright © 2016 Pierre Lamotte. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

void Pause();

int main(int argc,const char* argv[]){
    SDL_Window* ecran=NULL;
    SDL_Renderer* rend1=NULL;
    SDL_Surface* image=NULL;
    SDL_Surface* image2=NULL;
    SDL_Surface* screen=NULL;
    SDL_Texture* sdlTex=NULL;
    if(SDL_Init(SDL_INIT_VIDEO)==-1){
        printf("Problème 1\n");
        exit(EXIT_FAILURE);
    }
    ecran=SDL_CreateWindow("Gestion d'événements SDL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,850,500,SDL_SWSURFACE);
    if(ecran==NULL){
        printf("Problème 2\n");
        exit(EXIT_FAILURE);
    }
    rend1=SDL_CreateRenderer(ecran,-1,0);
    image=SDL_LoadBMP("/Users/Baracuda/Documents/Cours/Créations C/SDL Events/SDL Events/zozor.bmp");
    SDL_SetColorKey(image,SDL_TRUE,SDL_MapRGB(image->format,0,0,255));//Détoure l'image
    if(image==NULL){
        printf("Problème 3\n");
        exit(EXIT_FAILURE);
    }
    image2=SDL_LoadBMP("/Users/Baracuda/Documents/Cours/Créations C/pack_images_sdz/sdl_icone.bmp");
    SDL_SetColorKey(image2,SDL_TRUE,SDL_MapRGB(image2->format,0,0,0));//Détoure l'image
    if(image2==NULL){
        printf("Problème 4\n");
        exit(EXIT_FAILURE);
    }
    SDL_SetWindowIcon(ecran,image2);
    sdlTex=SDL_CreateTexture(rend1,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,850,500);
    screen=SDL_CreateRGBSurface(SDL_SWSURFACE,850,500,32,0,0,0,0);
    SDL_Rect pos;
    pos.x=screen->w/2-image->w/2;
    pos.y=screen->h/2-image->h/2;
    SDL_Rect pos2;
    pos2.x=10;
    pos2.y=10;
    int continuer=1;
    SDL_Event event;//Variable dédiée à la gestion des événements
    while(continuer){
        SDL_WaitEvent(&event);//Tant qu'aucun événement ne se présente, le programme attend
        switch(event.type){
            case SDL_QUIT://Evénement lié à la cessation d'activité
                continuer=0;//Sortie de la boucle et, par conséquent, de la boucle d'attente
                break;
            case SDL_KEYDOWN://Touche pressée parallèle à "KEYUP" où la touche est relâchée
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        continuer=0;
                        break;
                    case SDLK_UP:
                        if(pos.y>0){
                            pos.y-=5;
                            break;
                        }
                    case SDLK_DOWN:
                        if(pos.y<500-image->h){
                            pos.y+=5;
                            break;
                        }
                    case SDLK_RIGHT:
                        if(pos.x<850-image->w){
                            pos.x+=5;
                            break;
                        }
                    case SDLK_LEFT:
                        if(pos.x>0){
                            pos.x-=5;
                            break;
                        }
                    case SDL_MOUSEBUTTONDOWN:
                        if(event.button.button==SDL_BUTTON_LEFT){
                            pos.x=event.button.x;
                            pos.y=event.button.y;
                            break;
                        }
                }
        }
        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
        SDL_BlitSurface(image2,NULL,screen,&pos2);
        SDL_BlitSurface(image,NULL,screen,&pos);
        SDL_UpdateTexture(sdlTex,NULL,screen->pixels,screen->pitch);
        SDL_SetRenderDrawColor(rend1,0,0,0,255);
        SDL_RenderClear(rend1);
        SDL_RenderCopy(rend1,sdlTex,NULL,NULL);
        SDL_RenderPresent(rend1);
    }
    //Pause();
    SDL_FreeSurface(screen);
    SDL_FreeSurface(image);
    SDL_Quit();
    return EXIT_SUCCESS;
}
/*//Suspension des activités
void Pause(){
    int continuer=1;
    SDL_Event event;//Variable dédiée à la gestion des événements
    while(continuer){
        SDL_WaitEvent(&event);//Tant qu'aucun événement ne se présente, le programme attend
        switch(event.type){
            case SDL_QUIT://Evénement lié à la cessation d'activité
                continuer=0;//Sortie de la boucle et, par conséquent, de la boucle d'attente
                break;
            case SDL_KEYDOWN://Touche pressée parallèle à "KEYUP" où la touche est relâchée
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        continuer=0;
                        break;
                    case SDLK_UP:
                        if(pos.y>0){
                            pos.y--;
                            break;
                        }
                    case SDLK_DOWN:
                        if(pos.y<500){
                            pos.y++;
                            break;
                        }
                    case SDLK_RIGHT:
                        if(pos.x<850){
                            pos.x++;
                            break;
                        }
                    case SDLK_LEFT:
                        if(pos.x>0){
                            pos.x--;
                            break;
                        }
                }
            case SDL_KEYUP:
                switch(event.key.keysym.sym){
                        case SDLK_COLON:
                            continuer=0;
                            break;
                }
        }
    }
}
*/
