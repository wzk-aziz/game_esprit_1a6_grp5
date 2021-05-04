#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "ennemy.h"
#include "header.h"

/**
*
*@file ennemy.c 
*@brief fonctions file
*@author aziz
*
*
*
*
*
*/



/**
*@brief mouvement character + animation du personnage
*@param Event
*@return rien
*
*
*
*
*
*/

void animerEnnemiwalking(ennemi *e, SDL_Surface *screen)
{
	// add pos sprite ffs 
	e->postion_sprite.w=64;
	e->postion_sprite.h=64;
	
	
	//printf("///////////////////1\n");// just for errors 
	if (e->direction == 1)
	{
		e->postion_sprite.y=128;
		e->postion_sprite.x=e->postion_sprite.x-64;
		if (e->postion_sprite.x<0)
		{
			
			e->postion_sprite.x=512;	
		
		}

	}

	if (e->direction == 2)
	{   
		e->postion_sprite.y=190;
		e->postion_sprite.x=e->postion_sprite.x+64;
		if (e->postion_sprite.x>512)
		{
			
			e->postion_sprite.x=0;	
		
		}

	}
	

      SDL_BlitSurface(grass,NULL,screen,NULL);
	 for (int x = 0; x < 700 / 64; x++) {
         

            for (int y = 0; y <500 / 64; y++) 
            {
                
                SDL_Rect position;
                position.x = x * 64;
                position.y = y * 64;
                
                SDL_BlitSurface(grass, NULL, screen, &position);
                      }
        }

	SDL_BlitSurface(ennemy, &(e->postion_sprite), screen, &(e->postion_ecran));
	SDL_Flip((screen));
}

    //skelet walking frame by frame
    //random moves 
    //2 l 1 r                
void Ennemiwalking(ennemi *e)
{
	if (e->postion_ecran.x>=550)
	{
		e->direction=1;
<<<<<<< HEAD
		e->pas=randomer(50, 80);
=======
		e->pas_afranchir=randomer(10, 20);
		e->pas=e->pas_afranchir*2;
>>>>>>> 5ebc75c219063a67afc9897e6eb60fe6a39eb22d
	}
	if (e->postion_ecran.x<=220)
	{
		e->direction=2;
<<<<<<< HEAD
		e->pas=randomer(50, 80);
=======
		e->pas_afranchir=randomer(10, 20);
		e->pas=e->pas_afranchir*2;
>>>>>>> 5ebc75c219063a67afc9897e6eb60fe6a39eb22d
	}
	if (e->pas_afranchir==e->pas  && direction==1 )
	{
<<<<<<< HEAD
		e->direction=randomer(1,2);
		e->pas=randomer(50, 80);
=======
		direction=2;
>>>>>>> 5ebc75c219063a67afc9897e6eb60fe6a39eb22d
	}
	if (e->pas_afranchir==e->pas  && direction==2 )
	{
		direction=1;
	}
	if (e->pas==0  && direction==1 )
	{
		direction=2;
		e->pas_afranchir=randomer(10, 20);
		e->pas=e->pas_afranchir*2;
	}
<<<<<<< HEAD
SDL_Delay(50);
=======
	if (e->pas==0  && direction==2 )
	{
		direction=1;
		e->pas_afranchir=randomer(10, 20);
		e->pas=e->pas_afranchir*2;
	}
	else 
		e->pas--;
SDL_Delay(16);
>>>>>>> 5ebc75c219063a67afc9897e6eb60fe6a39eb22d
}

//
int randomer(int min, int max) 
{
  return rand() % (max - min + 1) + min;;
};























