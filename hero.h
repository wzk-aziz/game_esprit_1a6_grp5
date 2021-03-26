#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Hero Hero;
struct Hero {
SDL_Surface *images[8],*lifeArray[7],*fire,*score[13];
int life,r,l,spt,niv, splength;
SDL_Rect pos,poslife,posscr,posfire;
};

void initHero(Hero *H);
void showHero(Hero H, SDL_Surface * screen);
void moveHero(Hero *H, int direction);
void loadScoreHero(Hero *H);
void loadLifeHero(Hero *H);
void animateHero(Hero* H);
void jump(Hero* H);
void fire(Hero* H);
void loadMoveHeroRight(Hero *H);
void loadMoveHeroLeft(Hero *H);

// TODO NEXT TIME
void init(Hero * H, int caracterNumber);