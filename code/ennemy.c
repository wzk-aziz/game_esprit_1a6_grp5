
#include "ennemy.h"
#include "header.h"

void animerEnnemiwalking(ennemi *e, SDL_Surface *screen)
{
	if (*e->direction == 1)
	{
		*e->postion_sprite.y=128;
		switch (*e->postion_sprite.x)
		{
			case 0:
			*e->postion_sprite.x=512;
			break;
			default:
			*e->postion_sprite.x-=64;
			break;
		}
	}
	if (*e->direction == 2)
	{
		*e->postion_sprite.y=192;
		switch (*e->postion_sprite.x)
		{
			case 512:
			*e->postion_sprite.x=0;
			break;
			default:
			*e->postion_sprite.x+=64;
			break;
		}
	}
	 for (int x = 0; x < 500 / 64; x++) {
            for (int y = 0; y < 500 / 64; y++) {
                SDL_Rect position;
                position.x = x * 64;
                position.y = y * 64;
                SDL_BlitSurface(grass, NULL, screen, &position);
            }
        }
	SDL_BlitSurface(ennemy, &(*e->postion_sprite), screen, &(*e->postion_ecran));
	SDL_Flip((screen));
}

