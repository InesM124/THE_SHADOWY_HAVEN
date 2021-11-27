#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "amelioration_menu.h"
#include "perso.h"

void amelioration(SDL_Surface *screen,Mix_Chunk *effect,Mix_Chunk *effect2)
{
	SDL_Surface *menu=NULL,*choice=NULL,*player=NULL,*multiplayer=NULL,*keyboard=NULL;
	SDL_Rect pos;
	SDL_Event event,event2;
	int done=1,run=1,perso;
	hero c,d;

	menu=IMG_Load("images/choice menu.png");
	choice=IMG_Load("images/choice.png");
	player=IMG_Load("images/1 player.png");
	multiplayer=IMG_Load("images/multiplayer.png");
	keyboard=IMG_Load("images/keyboard.png");

	pos.x=0; pos.y=0;

	SDL_BlitSurface(menu,NULL,screen,&pos);
	SDL_BlitSurface(choice,NULL,screen,&pos);
	SDL_Flip(screen);
init(&c);
init2(&d);

while (done)
    {
    SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_MOUSEBUTTONDOWN :
		{
			if(event.button.button==SDL_BUTTON_LEFT)
			{
				if (event.motion.x>705 && event.motion.x<754 && event.motion.y>65 && event.motion.y<108)
				{
					Mix_PlayChannel(-1,effect2,0);
					done=0;
				}
				else if (event.motion.x>322 && event.motion.x<502 && event.motion.y>227 && event.motion.y<278)
				{
					Mix_PlayChannel(-1,effect2,0);
					SDL_BlitSurface(keyboard,NULL,screen,&pos);
					SDL_Flip(screen);
					while (run)
				    	{
					SDL_PollEvent(&event2);
						switch(event2.type)
						{
							case SDL_MOUSEBUTTONDOWN :
							{
							if (event2.motion.x>343 && event2.motion.x<480 && event2.motion.y>198 && event2.motion.y<306)
							{
								Mix_PlayChannel(-1,effect2,0);
								Mix_PauseMusic();
								perso=main_perso1(screen,c);
							}
							else if (event2.motion.x>552 && event2.motion.x<699 && event2.motion.y>198 && event2.motion.y<306)
							{
								Mix_PlayChannel(-1,effect2,0);
								Mix_PauseMusic();
								perso=main_perso2(screen,c);
							}
							
							break;
							}run=0;
						}
					}
						
				}
					else if (event.motion.x>548 && event.motion.x<729 && event.motion.y>227 && event.motion.y<278)
					{
						Mix_PlayChannel(-1,effect2,0);
						Mix_PauseMusic();
						perso=main_perso(screen,c,d);
					}
				}
			break;
			}
			case SDL_MOUSEMOTION :
			{
			    if (event.motion.x>322 && event.motion.x<502 && event.motion.y>227 && event.motion.y<278)
			    {
				SDL_BlitSurface(player,NULL,screen,&pos);
				Mix_PlayChannel(-1,effect,0);
				SDL_Flip(screen);

			    }
			    else if (event.motion.x>548 && event.motion.x<729 && event.motion.y>227 && event.motion.y<278)
			    {
				SDL_BlitSurface(multiplayer,NULL,screen,&pos);
				Mix_PlayChannel(-1,effect,0);
				SDL_Flip(screen);
			    }
			    else
			    {
				SDL_BlitSurface(choice,NULL,screen,&pos);
				SDL_Flip(screen);
			    }
			break;
			}
		}
	}
SDL_FreeSurface(menu);
SDL_FreeSurface(choice);
SDL_FreeSurface(player);
SDL_FreeSurface(multiplayer);
SDL_FreeSurface(keyboard);
}
