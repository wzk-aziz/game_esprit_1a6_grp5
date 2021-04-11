#ifndef ENNEMY_H
#define ENNEMY_H
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "header.h"

typedef struct 
{
	int status;
	SDL_Rect postion_ecran;
	SDL_Rect postion_sprite;
	int ennemy_type;
	int direction;
	int pas;
}ennemi;
void animerEnnemiwalking(ennemi *e, SDL_Surface * screen);
void Ennemiwalking(ennemi *e);
int randomer(int min, int max) ;

#endif // ENNEMY_H