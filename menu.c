#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"

void text_ttf(char ch[20],TTF_Font *police,SDL_Surface *text,SDL_Surface *screen,SDL_Rect pos,SDL_Color white,int x)
{
    police=TTF_OpenFont("Blanchope Free.ttf",x);
    if(!police)
    {
        printf("TTF_OpenFont: %s\n",TTF_GetError());
    }
    else
    {
        text=TTF_RenderText_Blended(police,ch,white);
        SDL_BlitSurface(text,NULL,screen,&pos);
        SDL_Flip(screen);
    }
}

void liberation (TTF_Font *police ,SDL_Surface *screen, SDL_Surface *newgame, SDL_Surface *newgame1, SDL_Surface *load, SDL_Surface *load1, SDL_Surface *options, SDL_Surface *options1, SDL_Surface *credits, SDL_Surface *credits1, SDL_Surface *quit, SDL_Surface *quit1,SDL_Surface *text, SDL_Surface *background,Mix_Music *musique)
{
SDL_FreeSurface(screen);
SDL_FreeSurface(newgame);
SDL_FreeSurface(newgame1);
SDL_FreeSurface(load);
SDL_FreeSurface(load1);
SDL_FreeSurface(options);
SDL_FreeSurface(options1);
SDL_FreeSurface(credits);
SDL_FreeSurface(credits1);
SDL_FreeSurface(quit);
SDL_FreeSurface(quit1);
SDL_FreeSurface(text);
SDL_FreeSurface(background);

Mix_FreeMusic(musique);
Mix_CloseAudio();

TTF_CloseFont(police);
TTF_Quit();
SDL_Quit();
}

void animation_stars(SDL_Surface *star,SDL_Surface *star2,SDL_Surface *star3,SDL_Surface *star_back,SDL_Surface *star_back2,SDL_Surface *star_back3,SDL_Surface *screen,SDL_Rect pos_star)
{
	SDL_BlitSurface(star, NULL, screen,&pos_star);
	SDL_BlitSurface(star2, NULL, screen,&pos_star);
	SDL_BlitSurface(star3, NULL, screen,&pos_star);
	SDL_Flip(screen);
	SDL_Delay(100);
	SDL_BlitSurface(star_back, NULL, screen, &pos_star);
	SDL_BlitSurface(star_back2, NULL, screen, &pos_star);
	SDL_BlitSurface(star_back3, NULL, screen, &pos_star);
	SDL_Flip(screen);
	SDL_Delay(100);
}

void menu(SDL_Surface *screen, SDL_Surface *newgame, SDL_Surface *load, SDL_Surface *options, SDL_Surface * credits, SDL_Surface *quit,SDL_Rect pos_new,SDL_Rect pos_load,SDL_Rect pos_options,SDL_Rect pos_credits,SDL_Rect pos_quit, SDL_Rect pos_back)
{
    SDL_BlitSurface(newgame,NULL,screen,&pos_new);
    SDL_BlitSurface(load,NULL,screen,&pos_load);
    SDL_BlitSurface(options,NULL,screen,&pos_options);
    SDL_BlitSurface(credits,NULL,screen,&pos_credits);
    SDL_BlitSurface(quit,NULL,screen,&pos_quit);
    SDL_Flip(screen);
}
void credit(SDL_Surface *screen,Mix_Chunk *effect,Mix_Chunk *effect2,TTF_Font *police,SDL_Surface *text,SDL_Color white)
{
	SDL_Surface *bg=NULL,*back=NULL,*back1=NULL;
	SDL_Rect pos_bg,pos_bk,pos_text,pos_text2,pos_text3,pos_text4,pos_text5,pos_text6,pos_text7,pos_text8;
	int done=1;
	SDL_Event event;

	bg=IMG_Load("images/credits.png");
	back=IMG_Load("images/buttons/back.png");
	back1=IMG_Load("images/buttons/back1.png");

	pos_bg.x=0;pos_bg.y=0;
	pos_bk.x=100; pos_bk.y=80;
	
	pos_text.x=280; pos_text.y=0;
	pos_text2.x=320; pos_text2.y=30;
	pos_text3.x=420; pos_text3.y=150;
	pos_text4.x=420; pos_text4.y=180;
	pos_text5.x=420; pos_text5.y=210;
	pos_text6.x=420; pos_text6.y=240;
	pos_text7.x=420; pos_text7.y=270;
	pos_text8.x=420; pos_text8.y=300;

	SDL_BlitSurface(bg,NULL,screen,&pos_bg);
	SDL_BlitSurface(back,NULL,screen,&pos_bk);
	SDL_Flip(screen);

	text_ttf("This game was designed and developped",police,text,screen,pos_text,white,30);
	text_ttf(" by our team at Chaos Games",police,text,screen,pos_text2,white,30);
	text_ttf("Ben Mbarek Amira",police,text,screen,pos_text3,white,30);
	text_ttf("Meddeb Ines",police,text,screen,pos_text4,white,30);
	text_ttf("Ben fredj Zeineb",police,text,screen,pos_text5,white,30);
	text_ttf("Saidi Tayssir",police,text,screen,pos_text6,white,30);
	text_ttf("Zgaya Ayoub",police,text,screen,pos_text7,white,30);
	text_ttf("Ferchichi Yassine",police,text,screen,pos_text8,white,30);


	while (done)
    	{
        SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN :
        		{
				if(event.key.keysym.sym==SDLK_b)
				{
                			done=0;
					Mix_PlayChannel(-1,effect2,0);
				}
			break;
			}
			case SDL_MOUSEBUTTONDOWN :
			{
				if(event.button.button==SDL_BUTTON_LEFT)
				{
					if (event.motion.x>404 && event.motion.x<586 && event.motion.y>398 && event.motion.y<484)
					{
						done=0;
						Mix_PlayChannel(-1,effect2,0);
					}
				}
			break;
			}
			case SDL_MOUSEMOTION :
			{
			    if (event.motion.x>404 && event.motion.x<586 && event.motion.y>398 && event.motion.y<484)
			    {
				SDL_BlitSurface(back1,NULL,screen,&pos_bk);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,effect,0);
			    }
			    else
			    {
				SDL_BlitSurface(back,NULL,screen,&pos_bk);
				SDL_Flip(screen);
			    }
			break;
			}
		}
	}

SDL_FreeSurface(bg);
SDL_FreeSurface(back);
SDL_FreeSurface(back1);
}
void sous_menu(SDL_Surface *screen, Mix_Chunk *effect, Mix_Chunk *effect2,SDL_Surface *text,TTF_Font *police,SDL_Color white, Mix_Music *musique,int *volume)
{
	SDL_Surface *menu=NULL,*back=NULL,*save=NULL,*back1=NULL,*save1=NULL;
	SDL_Surface *plus=NULL,*plus1=NULL,*minus=NULL,*minus1=NULL;
	SDL_Rect pos_menu,pos_save,pos_bk,pos_plus,pos_minus,pos_text,pos_text2,pos_text3;
	int done=1;
	SDL_Event event;

	menu=IMG_Load("images/sous_menu.png");

	save=IMG_Load("images/buttons/save.png");
	save1=IMG_Load("images/buttons/save1.png");

	back=IMG_Load("images/buttons/back.png");
	back1=IMG_Load("images/buttons/back1.png");

	minus=IMG_Load("images/buttons/minus.png");
	minus1=IMG_Load("images/buttons/minus1.png");

	plus=IMG_Load("images/buttons/plus.png");
	plus1=IMG_Load("images/buttons/plus1.png");


	pos_menu.x=200; pos_menu.y=0;

	pos_save.x=30; pos_save.y=25;
	pos_bk.x=0; pos_bk.y=25;

	pos_minus.x=0; pos_minus.y=0;
	pos_plus.x=0; pos_plus.y=0;

	pos_text.x=300; pos_text.y=65;
	pos_text2.x=300; pos_text2.y=150;
	pos_text3.x=300; pos_text3.y=200;

	SDL_BlitSurface(menu,NULL,screen,&pos_menu);
	SDL_BlitSurface(save,NULL,screen,&pos_save);
	SDL_BlitSurface(back,NULL,screen,&pos_bk);
	SDL_BlitSurface(plus,NULL,screen,&pos_plus);
	SDL_BlitSurface(minus,NULL,screen,&pos_minus);
	SDL_Flip(screen);

	text_ttf("Music",police,text,screen,pos_text,white,60);

	while (done)
    	{
        SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN :
        		{
				if(event.key.keysym.sym==SDLK_b)
				{
                			done=0;
					Mix_PlayChannel(-1,effect2,0);
				}
				else if(event.key.keysym.sym==SDLK_s)
				{
                			done=0;
					Mix_PlayChannel(-1,effect2,0);
				}
			break;
			}
			case SDL_MOUSEBUTTONDOWN :
			{
				if(event.button.button==SDL_BUTTON_LEFT)
				{
					if (event.motion.x>305 && event.motion.x<484 && event.motion.y>343 && event.motion.y<390)
					{
						done=0;
						Mix_PlayChannel(-1,effect2,0);
					}
					else if(event.motion.x >542 && event.motion.x <724 && event.motion.y >343 && event.motion.y <390)
					{
						Mix_PlayChannel(-1,effect2,0);
						done=0;
					}
					else if(event.motion.x>465 && event.motion.x<515 && event.motion.y>100 && event.motion.y<110)
					{
						if((*volume)>0)
						{
						(*volume)-=32;
						Mix_VolumeMusic((*volume));
						}
					}
					else if(event.motion.x>595 && event.motion.x<645 && event.motion.y>100 && event.motion.y<110)
					{

						if((*volume)<128)
						{
						(*volume)+=32;
						Mix_VolumeMusic((*volume));
						}
					}
				}
			break;
			}
			case SDL_MOUSEMOTION :
			{
			    if (event.motion.x>305 && event.motion.x<484 && event.motion.y>343 && event.motion.y<390)
			    {
				SDL_BlitSurface(back1,NULL,screen,&pos_bk);
				SDL_BlitSurface(save,NULL,screen,&pos_save);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,effect,0);
			    }
			    else if (event.motion.x >542 && event.motion.x <724 && event.motion.y >343 && event.motion.y <390)
			    {
				SDL_BlitSurface(back,NULL,screen,&pos_bk);
				SDL_BlitSurface(save1,NULL,screen,&pos_save);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,effect,0);
			    }
			    else if (event.motion.x >465 && event.motion.x <515 && event.motion.y >100 && event.motion.y <110)
			    {
				SDL_BlitSurface(minus1,NULL,screen,&pos_minus);
				SDL_BlitSurface(plus,NULL,screen,&pos_plus);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,effect,0);
			    }
			    else if (event.motion.x >595 && event.motion.x <645 && event.motion.y >100 && event.motion.y <110)
			    {
				SDL_BlitSurface(minus,NULL,screen,&pos_minus);
				SDL_BlitSurface(plus1,NULL,screen,&pos_plus);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,effect,0);
			    }
			    else
			    {
				SDL_BlitSurface(back,NULL,screen,&pos_bk);
				SDL_BlitSurface(save,NULL,screen,&pos_save);
				SDL_BlitSurface(minus,NULL,screen,&pos_minus);
				SDL_BlitSurface(plus,NULL,screen,&pos_plus);
				SDL_Flip(screen);
			    }
			    break;
			}	
		}
	SDL_Flip(screen);
	}

SDL_FreeSurface(menu);
SDL_FreeSurface(back);
SDL_FreeSurface(back1);
SDL_FreeSurface(save);
SDL_FreeSurface(save1);
SDL_FreeSurface(minus);
SDL_FreeSurface(minus1);
SDL_FreeSurface(plus);
SDL_FreeSurface(plus1);
}
