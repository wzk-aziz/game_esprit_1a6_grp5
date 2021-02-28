#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


int frame_postion (SDL_Rect *frame_position)
{
    if (frame_position<3200)
        frame_position=frame_position+800;
    else frame_position=0
}



int main(int argc, char *argv[])
{  

    SDL_Surface *Rain,*texte=NULL,*ecran = NULL, *imageDeFond = NULL, *bouton = NULL,*bouton2 = NULL,*imageDeFond2 = NULL,*imageDeFond3 = NULL,*imageDeFond4 = NULL;
    TTF_Font *police=NULL;
    SDL_Color couleurBlanche={255,255,255};
    SDL_Rect positionFond,postexte;
    SDL_Event event,event2; 
    int continuer=1 ,i,mousex,mousey; 
    
    positionFond.x = 0;
    positionFond.y = 0;
//son 
    Mix_Music *music1;
    Mix_Chunk *music;
    Mix_AllocateChannels(2);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1;
    music=Mix_LoadWAV("button.wav");
    music1=Mix_LoadMUS("Music.mp3");
    Mix_PlayMusic(music1, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Game", NULL);

    //text
    TTF_Init();
    police=TTF_OpenFont("angelina.ttf",40);
    texte=TTF_RenderText_Blended(police,"CodeBusters©",couleurBlanche);


    bouton = SDL_LoadIMG("rain.png");
    SDL_Rect frame_position;
    frame_postion.x=0;
    frame_postion.y=0;
    frame_postion.w=800;
    frame_postion.h=600;


    imageDeFond= SDL_LoadBMP("Menusans.bmp");
    
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    bouton = SDL_LoadBMP("newgame.bmp");
    positionFond.x = 600;
    positionFond.y = 100;
    SDL_BlitSurface(bouton, NULL, ecran, &positionFond);


    bouton = SDL_LoadBMP("loadgame.bmp");
    positionFond.x = 600;
    positionFond.y = 160;
    SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

    bouton = SDL_LoadBMP("option.bmp");
    positionFond.x = 600;
    positionFond.y = 220;
    SDL_BlitSurface(bouton, NULL, ecran, &positionFond);
    
    bouton = SDL_LoadBMP("exit.bmp");
    positionFond.x = 600;
    positionFond.y = 280;
    SDL_BlitSurface(bouton, NULL, ecran, &positionFond);


    TTF_Init();
    police=TTF_OpenFont("angelina.ttf",40);
    texte=TTF_RenderText_Blended(police,"CodeBusters ©",couleurBlanche);
    postexte.x=569;
    postexte.y=558;
    SDL_BlitSurface(texte, NULL, ecran, &postexte);


    SDL_WM_SetCaption("SDL_Mixer", NULL);
    SDL_Flip(ecran);

    SDL_WM_SetCaption("Menu", NULL);
    while (continuer)

    {
        frame_postion (&frame_position);
        SDL_PollEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

                break;

            case SDL_KEYDOWN: {

                switch(event.key.keysym.sym)

                {

                    case SDLK_DOWN: 
                    Mix_PlayChannel(1,music,0);
                    i++ ;// Flèche haut

                        break;  

                    case SDLK_UP:
                    Mix_PlayChannel(1,music,0);
                    i-- ;// Flèche bas
                          
                       break;
                  
                                   }
                               }

                    case SDL_MOUSEMOTION : 
                    {
                       mousex = event.motion.x;

                       mousey = event.motion.y;

                    } 
                    break;
        }


        if (mousex>=600 && mousey>=100 && mousey<=180) {
            i=0;
        }
        if (mousex>=600 && mousey>=160 && mousey<=240) {
            i=1;
        }

        if (mousex>=600 && mousey>=220 && mousey<=300) {
            i=2;
        }
        if (mousex>=600 && mousey>=280 && mousey<=300) {
            i=3;
        }
       

        
        if (i % 4 ==0  ){
                                SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                                SDL_BlitSurface(Rain, &frame_position, ecran, NULL);
                                bouton = SDL_LoadBMP("exit.bmp");
                                positionFond.x = 600;
                                positionFond.y = 280;

                                SDL_BlitSurface(bouton, NULL, ecran, &positionFond);
                                
                                SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                                bouton = SDL_LoadBMP("newgame2.bmp");
                                positionFond.x = 600;
                                positionFond.y = 100;
                                SDL_BlitSurface(bouton, NULL, ecran, &positionFond);
                
                                SDL_BlitSurface(imageDeFond4, NULL, ecran, &positionFond);
                                bouton = SDL_LoadBMP("option.bmp");
                                positionFond.x = 600;
                                positionFond.y = 220;
                                SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                                SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                                bouton = SDL_LoadBMP("loadgame.bmp");
                                positionFond.x = 600;
                                positionFond.y = 160;
                                SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                                SDL_Flip(ecran);

                    } else if (i % 4==1 ) {
                            SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                                SDL_BlitSurface(Rain, &frame_position, ecran, NULL);

                            bouton = SDL_LoadBMP("exit.bmp");
                            positionFond.x = 600;
                            positionFond.y = 280;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                            bouton = SDL_LoadBMP("loadgame2.bmp");
                            positionFond.x = 600;
                            positionFond.y = 160;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond);
                            bouton = SDL_LoadBMP("option.bmp");
                            positionFond.x = 600;
                            positionFond.y = 220;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                            bouton = SDL_LoadBMP("newgame.bmp");
                            positionFond.x = 600;
                            positionFond.y = 100;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                         SDL_Flip(ecran);
                    } else if (i % 4==2 ) {

                            SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                             SDL_BlitSurface(Rain, &frame_position, ecran, NULL);
                            bouton = SDL_LoadBMP("exit.bmp");
                            positionFond.x = 600;
                            positionFond.y = 280;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond);
                            bouton = SDL_LoadBMP("option2.bmp");
                            positionFond.x = 600;
                            positionFond.y = 220;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                            bouton = SDL_LoadBMP("newgame.bmp");
                            positionFond.x = 600;
                            positionFond.y = 100;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                            bouton = SDL_LoadBMP("loadgame.bmp");
                            positionFond.x = 600;
                            positionFond.y = 160;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_Flip(ecran);
                    } else if (i % 4==3 ) {

                            SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                             SDL_BlitSurface(Rain, &frame_position, ecran, NULL);
                            bouton = SDL_LoadBMP("exit2.bmp");
                            positionFond.x = 600;
                            positionFond.y = 280;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond);
                            bouton = SDL_LoadBMP("option.bmp");
                            positionFond.x = 600;
                            positionFond.y = 220;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);
                            
                            SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                            bouton = SDL_LoadBMP("newgame.bmp");
                            positionFond.x = 600;
                            positionFond.y = 100;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
                            bouton = SDL_LoadBMP("loadgame.bmp");
                            positionFond.x = 600;
                            positionFond.y = 160;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_Flip(ecran);
                    }
                            SDL_Flip(ecran);
                                                 if (event.key.keysym.sym==SDLK_RETURN) 
                                     {       
                                        if(i==3)
                  
                                             continuer=0;
                                      }

       
}

        
        
        

    
      
       


        

    

   

            TTF_CloseFont(police);
            TTF_Quit();
            SDL_FreeSurface(texte);
            Mix_FreeMusic(music1);
            Mix_FreeChunk(music);
            Mix_CloseAudio();       
            SDL_FreeSurface(imageDeFond);     
            SDL_Quit();

    return EXIT_SUCCESS;
}
