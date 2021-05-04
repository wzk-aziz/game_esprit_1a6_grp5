#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "header.h"


/**
*@file main.c 
*@brief game loops
*@author aziz
*
*
*
*
*/

int main()

/**
*@brief init vars
*
*
*
*
*
*/

{

    ennemi E;
    E.direction=1;
    E.pas=0;
    int continuer=1,couleurNoire;
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(700, 500, 0, 0);
    E.postion_ecran.x=200;
    E.postion_ecran.y=417;
    E.postion_sprite.x=0;
    //to not eat mem val temp 
    temp= IMG_Load("Skeleton_Sprite_sheet.png");
    ennemy = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    temp  = IMG_Load("background12.png");
    grass = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    couleurNoire= SDL_MapRGB(screen-> format, 0, 0, 0);
    SDL_SetColorKey(ennemy, SDL_SRCCOLORKEY | SDL_RLEACCEL,couleurNoire);
    SDL_Flip(screen);
    
    while (continuer){

while (continuer)
    {
        SDL_Event event;
        

        /* look for an event */
        if (SDL_PollEvent(&event)) 
        {
            /* an event was found */
            switch (event.type) 
            {
                /* close button clicked */
                case SDL_QUIT:
                  continuer = 0;
                    break;
            }
        }




            animerEnnemiwalking(&E, screen);
            Ennemiwalking(&E);
    }
    
    
                        }


}





















































