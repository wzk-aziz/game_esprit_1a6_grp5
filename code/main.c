#include "header.h"


int main ()
{
    ennemi E;

    int continuer=1;
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(500, 500, 0, 0);
    E.postion_ecran.x=50;
    E.postion_ecran.y=50;
	temp   = IMG_Load("Skeleton_Sprite_sheet.png");
    ennemy = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    temp  = IMG_Load("grass_15.png");
    grass = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    while (continuer)
    SDL_Delay(50);
    animerEnnemiwalking(&E, screen);

}