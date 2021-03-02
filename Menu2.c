#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>





int rain_move (SDL_Rect *frame_position)
{
    if ((*frame_position).x<2400)
        (*frame_position).x=(*frame_position).x+800;
    else (*frame_position).x=0;
}



int main(int argc, char *argv[])
{  

    SDL_Surface *Rain,*texte=NULL,*ecran = NULL, *imageDeFond = NULL, *bouton = NULL,*bouton2 = NULL,*mute_button,*voulme_up,*volume_down,*fullscreen_button,*unmute_button,*volume_level;
    TTF_Font *police=NULL;
    SDL_Rect pos_volume_down,pos_volume_up,pos_mute,pos_fullscreen,pos_back;
    SDL_Color couleurBlanche={255,255,255};
    SDL_Rect positionFond,postexte;
    SDL_Event event,event2; 
    int continuer=1 ,i,mousex,mousey,couleurNoire; 
    int Menu_state=1;
    int volume;
    char volume_text[50];
    int k=0;
    int muted=0;
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

    ecran = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Game", NULL);

    //text
    sprintf(volume_text, "volume : %d", volume);
    TTF_Init();
    police=TTF_OpenFont("angelina.ttf",40);
    texte=TTF_RenderText_Blended(police,"CodeBusters©",couleurBlanche);
    volume_level=TTF_RenderText_Blended(police,volume_text,couleurBlanche);
    mute_button=IMG_Load("mute.jpg");
    voulme_up=IMG_Load("sound+.png");
    volume_down=IMG_Load("sound-.png");
    fullscreen_button=IMG_Load("Square Simple.jpg");
    unmute_button=IMG_Load("Unmuted.jpg");
  
    pos_volume_down.x=215;
    pos_volume_down.y=250;
    pos_volume_up.x=500;
    pos_volume_up.y=250;
    pos_volume.x=200;
    pos_volume.y=400;
    pos_mute.x=362;
    pos_mute.y=250;
    pos_fullscreen.x=352;
    pos_fullscreen.y=100;
    pos_back.x=250;
    pos_back.y=460;

    couleurNoire= SDL_MapRGB(ecran -> format, 0, 0, 0);
    Rain= IMG_Load("rain.png");
    SDL_SetColorKey(Rain, SDL_SRCCOLORKEY | SDL_RLEACCEL,couleurNoire);
    SDL_Rect frame_position;
    frame_position.x=0;
    frame_position.y=0;
    frame_position.w=800;
    frame_position.h=600;


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
       
        
        while (Menu_state==1)
        {
            rain_move (&frame_position);
             SDL_Delay(60);
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
                                SDL_BlitSurface(imageDeFond, NULL, ecran, NULL);
                                SDL_BlitSurface(texte, NULL, ecran, &postexte);
                                SDL_BlitSurface(Rain, &frame_position, ecran, NULL);
                                bouton = SDL_LoadBMP("exit.bmp");
                                positionFond.x = 600;
                                positionFond.y = 280;

                                SDL_BlitSurface(bouton, NULL, ecran, &positionFond);
                                
                                
                                bouton = SDL_LoadBMP("newgame2.bmp");
                                positionFond.x = 600;
                                positionFond.y = 100;
                                SDL_BlitSurface(bouton, NULL, ecran, &positionFond);
                
                               ;
                                bouton = SDL_LoadBMP("option.bmp");
                                positionFond.x = 600;
                                positionFond.y = 220;
                                SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                                
                                bouton = SDL_LoadBMP("loadgame.bmp");
                                positionFond.x = 600;
                                positionFond.y = 160;
                                SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                                SDL_Flip(ecran);

                    } else if (i % 4==1 ) {
                           SDL_BlitSurface(imageDeFond, NULL, ecran, NULL);
                            SDL_BlitSurface(texte, NULL, ecran, &postexte);
                                SDL_BlitSurface(Rain, &frame_position, ecran, NULL);

                            bouton = SDL_LoadBMP("exit.bmp");
                            positionFond.x = 600;
                            positionFond.y = 280;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            bouton = SDL_LoadBMP("loadgame2.bmp");
                            positionFond.x = 600;
                            positionFond.y = 160;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                      
                            bouton = SDL_LoadBMP("option.bmp");
                            positionFond.x = 600;
                            positionFond.y = 220;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                        
                            bouton = SDL_LoadBMP("newgame.bmp");
                            positionFond.x = 600;
                            positionFond.y = 100;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                         SDL_Flip(ecran);
                    } else if (i % 4==2 ) {
                            SDL_BlitSurface(imageDeFond, NULL, ecran, NULL);
                           SDL_BlitSurface(texte, NULL, ecran, &postexte);
                             SDL_BlitSurface(Rain, &frame_position, ecran, NULL);
                            bouton = SDL_LoadBMP("exit.bmp");
                            positionFond.x = 600;
                            positionFond.y = 280;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                          
                            bouton = SDL_LoadBMP("option2.bmp");
                            positionFond.x = 600;
                            positionFond.y = 220;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                     
                            bouton = SDL_LoadBMP("newgame.bmp");
                            positionFond.x = 600;
                            positionFond.y = 100;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                      
                            bouton = SDL_LoadBMP("loadgame.bmp");
                            positionFond.x = 600;
                            positionFond.y = 160;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_Flip(ecran);
                    } else if (i % 4==3 ) {
                            SDL_BlitSurface(imageDeFond, NULL, ecran, NULL);
                            SDL_BlitSurface(texte, NULL, ecran, &postexte);
                             SDL_BlitSurface(Rain, &frame_position, ecran, NULL);
                            bouton = SDL_LoadBMP("exit2.bmp");
                            positionFond.x = 600;
                            positionFond.y = 280;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                         
                            bouton = SDL_LoadBMP("option.bmp");
                            positionFond.x = 600;
                            positionFond.y = 220;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);
                            
                          
                            bouton = SDL_LoadBMP("newgame.bmp");
                            positionFond.x = 600;
                            positionFond.y = 100;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                        
                            bouton = SDL_LoadBMP("loadgame.bmp");
                            positionFond.x = 600;
                            positionFond.y = 160;
                            SDL_BlitSurface(bouton, NULL, ecran, &positionFond);

                            SDL_Flip(ecran);
                    }
                            SDL_Flip(ecran);
                                                 if (event.key.keysym.sym==SDLK_RETURN) 
                                     {       
                                        if(i % 4==3 )
                                            {
                                             continuer=0;
                                             Menu_state=0;
                                            }
                                        if(i % 4==2 )
                                            {
                                             Menu_state=2;
                                            }    
                                      }
        }
            while (Menu_state==2)
            {   
                SDL_BlitSurface(fullscreen_button, NULL, ecran, &pos_fullscreen);
                 SDL_BlitSurface(voulme_up, NULL, ecran, &pos_volume_up);
                 SDL_BlitSurface(volume_down, NULL, ecran, &pos_volume_down);
                 if (muted==0)
                 SDL_BlitSurface(unmute_button, NULL, ecran, &pos_mute);
                else 
                    SDL_BlitSurface(mute_button, NULL, ecran, &pos_mute);
                SDL_Flip(ecran);
                Mix_VolumeMusic(volume);
                Mix_Volume(1,volume);
                 sprintf(volume_text, "Volume : %d", volume);
                 volume_level=TTF_RenderText_Blended(police,volume_text,couleurBlanche);
                 SDL_Delay(60);

        SDL_PollEvent(&event);
                 switch(event.type)
                 {
                     case SDL_QUIT:

                    continuer = 0;

                     break;

                    case SDL_KEYDOWN: {

                    switch(event.key.keysym.sym){

                    case SDLK_DOWN:
                                        Mix_PlayChannel(1,music,0);

                    if (k==1)
                        k=0;
                    else k++;
                    break;
                    case SDLK_UP:
                                        Mix_PlayChannel(1,music,0);

                    if (k==0)
                        k=1;
                    else k--;
                    case SDLK_RETURN:
                                        Mix_PlayChannel(1,music,0);

                    if (k==0)
                        SDL_WM_ToggleFullScreen(ecran);
                    if (k==1)
                        if (muted==1)
                           { volume=0;
                             muted=1;
                           }
                        else
                            {
                                volume=100;
                                muted=0;
                            
                            }
                    break;
                    case SDLK_RIGHT:

                                        Mix_PlayChannel(1,music,0);

                    if (k==1)
                    {
                    if (volume<100)
                        volume=volume+10;
                }   
                    break;
                    case SDLK_LEFT:
                                        Mix_PlayChannel(1,music,0);
                    if (k==1)
                    {                    
                    if (volume>0)
                        volume=volume-10;
                    }
                    break;
                    case SDLK_BACKSPACE:
                    Menu_state=1;
                    break;
                    }   
                 }
             }
                 SDL_BlitSurface(fullscreen_button, NULL, ecran, &pos_fullscreen);
                 SDL_BlitSurface(voulme_up, NULL, ecran, &pos_volume_up);
                 SDL_BlitSurface(volume_down, NULL, ecran, &pos_volume_down);
                 if (muted==0)
                 SDL_BlitSurface(unmute_button, NULL, ecran, &pos_mute);
                else 
                    SDL_BlitSurface(mute_button, NULL, ecran, &pos_mute);
                SDL_Flip(ecran);




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
