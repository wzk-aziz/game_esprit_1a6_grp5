#include "header.h"


int main()
{
    ennemi E;

    int continuer=1,couleurNoire;
    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(700, 500, 0, 0);
    E.postion_ecran.x=500;
    E.postion_ecran.y=417;
	
    temp   = IMG_Load("Skeleton_Sprite_sheet.png");
    ennemy = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    temp  = IMG_Load("background12.png");
    grass = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    couleurNoire= SDL_MapRGB(screen-> format, 0, 0, 0);
    SDL_SetColorKey(ennemy, SDL_SRCCOLORKEY | SDL_RLEACCEL,couleurNoire);
    SDL_Flip(screen);
    
    while (continuer)
    
    animerEnnemiwalking(&E, screen);

}
























































