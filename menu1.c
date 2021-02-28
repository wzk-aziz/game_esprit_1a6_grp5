#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{  

    SDL_Surface *ecran = NULL, *background = NULL, *Newgame = NULL,*Loadgame = NULL,*option=NULL,*exxit=NULL;

    SDL_Surface *Newgame2 = NULL,*Loadgame2 = NULL,*option2=NULL,*exxit2=NULL;
    
    SDL_Rect posbackground, posNewgame,posLoadgame,posoption,posexxit;
    SDL_Event event,event2; 
    int continuer=1,j ,i=0,mousex,mousey; 
    
    posbackground.x=0;
    posbackground.y=0;

    posNewgame.x = 600;
    posNewgame.y = 100;

    posLoadgame.x = 600;
    posLoadgame.y = 140;

    posoption.x = 600;
    posoption.y = 180;

    posexxit.x = 600;
    posexxit.y = 220;
    
    
    

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("game", NULL);

   
    background= SDL_LoadBMP("Menusans.bmp");
    Newgame = SDL_LoadBMP("newgame.bmp");
    option = SDL_LoadBMP("option.bmp");
    Loadgame = SDL_LoadBMP("loadgame.bmp");
    exxit = SDL_LoadBMP("exit.bmp");
    Newgame2 = SDL_LoadBMP("newgame2.bmp");
    option2 = SDL_LoadBMP("option2.bmp");
    Loadgame2 = SDL_LoadBMP("loadgame2.bmp");
    exxit2 = SDL_LoadBMP("exit2.bmp");

    SDL_BlitSurface(background, NULL, ecran, &posbackground);
    SDL_BlitSurface(Newgame, NULL, ecran, &posNewgame);    
    SDL_BlitSurface(option, NULL, ecran, &posoption);
    SDL_BlitSurface(Loadgame, NULL, ecran, &posLoadgame);
    SDL_BlitSurface(exxit, NULL, ecran, &posexxit);

    SDL_Flip(ecran);

    SDL_WM_SetCaption("Menu", NULL);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN: {
                switch(event.key.keysym.sym)
                {           
                    case SDLK_DOWN: i++ ;// Flèche haut
                        break;  

                    case SDLK_UP:i-- ;// Flèche bas                      
                       break;                  
                }
                               }

            case SDL_MOUSEMOTION : 
                {
                    mousex = event.motion.x;
                    mousey = event.motion.y;

                } 
                    break;
        }
      

        if (mousex>=600 && mousey>=100 && mousey<=160) {
            i=0;
        }
        if (mousex>=600 && mousey>=140 && mousey<=200) {
            i=1;
        }

        if (mousex>=600 && mousey>=180 && mousey<=240) {
            i=2;
        }
        if (mousex>=600 && mousey>=220 && mousey<=280) {
            i=3;
        }

        j=i;

        if (i<0) {

        if (-i % 4==1) {
            j=3;
        }else if (-i % 4==2 ) {
            j=2;
        }else if (-i % 4==3 ) {
            j=1;
        }else if (-i % 4==0 ) {
            j=0;
        }
        
                 }

        if (j % 4 ==0  ){
                        
    SDL_BlitSurface(Newgame2, NULL, ecran, &posNewgame);    
    SDL_BlitSurface(option, NULL, ecran, &posoption);
    SDL_BlitSurface(Loadgame, NULL, ecran, &posLoadgame);
    SDL_BlitSurface(exxit, NULL, ecran, &posexxit);                        
    SDL_Flip(ecran);

                        } 
        else if (j % 4==1 ) {
                        
    SDL_BlitSurface(Newgame, NULL, ecran, &posNewgame);    
    SDL_BlitSurface(option, NULL, ecran, &posoption);
    SDL_BlitSurface(Loadgame2, NULL, ecran, &posLoadgame);
    SDL_BlitSurface(exxit, NULL, ecran, &posexxit);
    SDL_Flip(ecran);
                            } 

        else if (j % 4==2 ) {

    SDL_BlitSurface(Newgame, NULL, ecran, &posNewgame);    
    SDL_BlitSurface(option2, NULL, ecran, &posoption);
    SDL_BlitSurface(Loadgame, NULL, ecran, &posLoadgame);
    SDL_BlitSurface(exxit, NULL, ecran, &posexxit);                      
    SDL_Flip(ecran);
                             } 

        else if (j % 4==3 ) {
                       
    SDL_BlitSurface(Newgame, NULL, ecran, &posNewgame);    
    SDL_BlitSurface(option, NULL, ecran, &posoption);
    SDL_BlitSurface(Loadgame, NULL, ecran, &posLoadgame);
    SDL_BlitSurface(exxit2, NULL, ecran, &posexxit);
    SDL_Flip(ecran);
                if (event.key.keysym.sym==SDLK_RETURN) 
                {
                    continuer=0;
                }
                            }       
   
}



    SDL_FreeSurface(ecran);     
    SDL_Quit();

    return EXIT_SUCCESS;
}
