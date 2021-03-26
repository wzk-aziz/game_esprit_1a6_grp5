#include "header.h"


int main ()
{

	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(500, 500, 0, 0);
	E.postion_ecran.x=50;
	E.postion_ecran.y=50;
	temp   = IMG_Load("../Assets/Ennmy_models/Skeleton_Sprite.png");
    ennemy = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    temp  = SDL_LoadBMP("/Assets/Background_Levels/grass.bmp");
    background = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    while (continuer)
    void animerEnnemiwalking(&E, &screen);


}