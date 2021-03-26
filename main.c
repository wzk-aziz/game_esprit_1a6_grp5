#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "hero.h"
int main ()
{

    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(500, 500, 0, 0);
    postionScreen.x=50;
    postionScreen.y=50;

    scoreSpriteSheet = IMG_Load("scoreSpritesheet.png");
    Hero = SDL_DisplayFormat(scoreSpriteSheet);
    SDL_FreeSurface(scoreSpriteSheet);

    lifeSpriteSheet = SDL_LoadBMP("lifeSpritesheet.png");
    background = SDL_DisplayFormat(lifeSpriteSheet);
    SDL_FreeSurface(lifeSpriteSheet);

    jumpSpriteSheet  = SDL_LoadBMP("jumpSpritesheet.png");
    background = SDL_DisplayFormat(jumpSpriteSheet);
    SDL_FreeSurface(jumpSpriteSheet);

    fireSpriteSheet  = SDL_LoadBMP("fireSpritesheet.png");
    background = SDL_DisplayFormat(fireSpriteSheet);
    SDL_FreeSurface(fireSpriteSheet);

    moveRightSpriteSheet  = SDL_LoadBMP("moveRightSpritesheet.png");
    background = SDL_DisplayFormat(moveRightSpriteSheet);
    SDL_FreeSurface(moveRightSpriteSheet);

    moveLeftSpriteSheet  = SDL_LoadBMP("moveLeftSpritesheet.png");
    background = SDL_DisplayFormat(moveLeftSpriteSheet);
    SDL_FreeSurface(moveLeftSpriteSheet);

    while (continuer)
    void animateHero(& H);


}
