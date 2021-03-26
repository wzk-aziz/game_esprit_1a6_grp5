#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "hero.h"

//this fct is to crop the spritesheet so i can use it piece by piece
// DO NOT TOUCH , USE ONLY
// eg. crop_surface(spritesheet,0,0,100,50)
// spritesheet is an SDL_Surface
SDL_Surface* crop_surface(SDL_Surface* sprite_sheet, int x, int y, int width, int height) {
	SDL_Surface* surface = SDL_CreateRGBSurface(sprite_sheet->flags, width, height, sprite_sheet->format->BitsPerPixel, sprite_sheet->format->Rmask, sprite_sheet->format->Gmask, sprite_sheet->format->Bmask, sprite_sheet->format->Amask);
	SDL_Rect rect = {x, y, width, height};
	SDL_BlitSurface(sprite_sheet, &rect, surface, 0);
	return surface;
}

//splngth=spritesheet length
//r=right ; l=left ; scr=score ; niv=niveau
void initHero(Hero *H) {

    H->life=6;
    H->splength=8;

    H->r=0;
    H->l=0;

    H->pos.x=0;
    H->pos.y=130;

    H->poslife.x=H->pos.x;
    H->poslife.y=H->pos.y-30;

    H->posscr.x=H->pos.x;
    H->posscr.y=H->pos.y-50;
   
    H->fire=IMG_Load("fire.png");

    H->posfire.x=H->pos.x+95;
    H->posfire.y=H->pos.y+56;

    H->spt=0;

    H->niv=1;

}

//affichage 
void showHero(Hero H,SDL_Surface *screen) {
	
	SDL_BlitSurface(H.images[H.spt], NULL,screen,&H.pos);
	SDL_BlitSurface(H.lifeArray[6-H.life], NULL,screen,&H.poslife);
	SDL_BlitSurface(H.score[13-H.niv], NULL,screen,&H.posscr);
}

//deplacement avec direction
void moveHero(Hero *H, int direction) {
	// direction = 0 is RIGHT
    if(direction == 0) {
		H->pos.x+=4;
	    if (H->r==7) {
	        H->r=0;
	    } else {
	        H->r++;
	    }
	   	H->l=0;
    }
	// direction != 0 is LEFT
   	else {
   		H->pos.x-=8;
    	if (H->l==7) {
        	H->l=0;
    	} else {
        	H->l++;
    	}
   		H->r=0;
   	}
}

//spritesheet width and height khdemt kol spritesheet indiv de l'autre
//affichage score
void loadScoreHero(Hero *H) {
	
	SDL_Surface* scoreSpriteSheet = IMG_Load("scoreSpritesheet.png");
	int scoreFrameLength = scoreSpriteSheet->w / 13;
	for(int i = 0; i<13; i++) {
		H->score[i] = crop_surface(scoreSpriteSheet, i * scoreFrameLength, 0, scoreFrameLength, scoreSpriteSheet->w);
	}
}

//affichage vie
void loadLifeHero(Hero *H) {
	
	SDL_Surface* lifeSpriteSheet = IMG_Load("lifeSpritesheet.png");
	int lifeFrameLength = lifeSpriteSheet->w / 7;
	for(int i = 0; i<7; i++) {
		H->lifeArray[i] = crop_surface(lifeSpriteSheet, i * lifeFrameLength, 0, lifeFrameLength, lifeSpriteSheet->w);
	}
}


//animation
void animateHero(Hero *H) {
    H->poslife.x=H->pos.x;
    H->poslife.y=H->pos.y-30;
    H->posfire.x=H->pos.x+95;
    H->posfire.y=H->pos.y+56;
    H->posscr.x=H->pos.x;
    H->posscr.y=H->pos.y-50;
}

//saut
void jump(Hero* H) {
	
	SDL_Surface* jumpSpriteSheet = IMG_Load("jumpSpritesheet.png");
	int jumpFrameLength = jumpSpriteSheet->w / 6;
	for(int i = 0; i<6; i++) {
		H->images[i] = crop_surface(jumpSpriteSheet, i * jumpFrameLength, 0, jumpFrameLength, jumpSpriteSheet->w);
	}
}


void fire(Hero* H) {
	
	SDL_Surface* fireSpriteSheet = IMG_Load("fireSpritesheet.png");
	int fireFrameLength = fireSpriteSheet->w / 6;
	for(int i = 0; i<6; i++) {
		H->images[i] = crop_surface(fireSpriteSheet, i * fireFrameLength, 0, fireFrameLength, fireSpriteSheet->w);
	}
}

//affichage dep droite
void loadMoveHeroRight(Hero* H) {
	
	SDL_Surface* moveRightSpriteSheet = IMG_Load("moveRightSpritesheet.png");
	int moveRightFrameLength = moveRightSpriteSheet->w / 8;
	for(int i = 0; i<8; i++) {
		H->images[i] = crop_surface(moveRightSpriteSheet, i * moveRightFrameLength, 0, moveRightFrameLength, moveRightSpriteSheet->w);
	}
}

//affichage dep gauche
void loadMoveHeroLeft(Hero* H) {
	// TODO : create moveLeftSpritesheet.png (8 images)
	SDL_Surface* moveLeftSpriteSheet = IMG_Load("moveLeftSpritesheet.png");
	int moveLeftFrameLength = moveLeftSpriteSheet->w / 8;
	for(int i = 0; i<8; i++) {
		H->images[i] = crop_surface(moveLeftSpriteSheet, i * moveLeftFrameLength, 0, moveLeftFrameLength, moveLeftSpriteSheet->w);
	}
}


