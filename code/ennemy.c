
#include "ennemy.h"
#include "header.h"

void animerEnnemiwalking(ennemi *e, SDL_Surface *screen)
{
	
	e->postion_sprite.w=64;
	e->postion_sprite.h=64;
	e->direction = 1;
	e->postion_sprite.y=128;
	//printf("///////////////////1\n");
	if (e->direction == 1)
	{
	
		e->postion_sprite.x=e->postion_sprite.x-64;
		if (e->postion_sprite.x<0)
		{
			
			e->postion_sprite.x=512;	
		
		}

	}
	//printf("///////////////////2\n");
	if (e->direction == 2)
	{   
		
		e->postion_sprite.y=192;
		switch (e->postion_sprite.x)
		{   
			case 512:
			e->postion_sprite.x=0;
			break;
			default:
			e->postion_sprite.x+=64;
			break;
	     

		}
	}
	//printf("///////////////////3\n");
	
	SDL_Delay(16);

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

                    
void Ennemiwalking(ennemi *e)
{
	if (e->pas==0)
	{
		e->direction=randomer(1, 2);
		e->pas=randomer(10, 20);
	}
	if (e->direction==1)
	{
		e->postion_ecran.x-=2;
		e->pas-=1;
	}
	if (e->direction==2)
	{
		e->postion_ecran.x+=2;
		e->pas-=1;
	}

}

int randomer(int min, int max) 
{
  return rand() % (max - min + 1) + min;;
};























