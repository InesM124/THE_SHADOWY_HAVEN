/** 
* @file main_enigme.c 
* @brief resolution enigme
* @author Ben Mbarek Amira
* @version 1.0
* @date Apr 22, 2021 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "enigme.h"

int main_enigme(int *vie)
{
	SDL_Surface *screen=NULL,*success=NULL,*failure=NULL;
	enig e;

	SDL_Event event,event2;
	int done=1,run=1;
	
	SDL_Init(SDL_INIT_VIDEO);
	
	screen=SDL_SetVideoMode(1000, 446, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	init_enigme(&e);
	afficher_enigme(screen,&e);

	e.background2=IMG_Load("enigme/underwater.png");
	success=IMG_Load("enigme/success.png");
	failure=IMG_Load("enigme/failure.png");

	while (done)
    	{
        SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN :
        		{

				switch (event.key.keysym.sym)
				{
					case SDLK_SPACE:
						done=0;
					break;

					case SDLK_RETURN:
					{
						SDL_BlitSurface(e.background2,NULL,screen,&e.pos);

						generer_enigme(screen,&e,"questions.txt","answers.txt");
						while (run)
						{
						    SDL_WaitEvent(&event2);
						    switch(event2.type)
						    {
						        case SDL_MOUSEBUTTONDOWN :
						        {
								if(event2.motion.x>650 && event2.motion.x<922 && event2.motion.y>272 && 										event2.motion.y<383 && e.num==0)
								{
									SDL_BlitSurface(success,NULL,screen,&e.pos);
									SDL_Flip(screen);
									run=0;
								}

								else if(event2.motion.x>50 && event2.motion.x<322 && event2.motion.y>272 && 											event2.motion.y<383 && (e.num==1 || e.num==3))
								{
									SDL_BlitSurface(success,NULL,screen,&e.pos);
									SDL_Flip(screen);
									run=0;
								}

								else if(event2.motion.x>350 && event2.motion.x<622 && event2.motion.y>272 && 											event2.motion.y<383 && e.num==2)
								{
									SDL_BlitSurface(success,NULL,screen,&e.pos);
									SDL_Flip(screen);
									run=0;
								}

								else
								{ 
									SDL_BlitSurface(failure,NULL,screen,&e.pos);
									SDL_Flip(screen);
									(*vie)--;
									run=0;
								}
						        }
							break;
							case SDL_KEYDOWN :
						        {
								if (event2.key.keysym.sym==SDLK_KP3 && (strcmp(e.rep[e.num],"MarkTwain")==0))
								{
									SDL_BlitSurface(success,NULL,screen,&e.pos);
									SDL_Flip(screen);
									run=0;
								}

								else if (event2.key.keysym.sym==SDLK_KP1 && ((strcmp(e.rep[e.num],"1000years")==0) || (strcmp(e.rep[e.num],"Rum")==0)))
								{
									SDL_BlitSurface(success,NULL,screen,&e.pos);
									SDL_Flip(screen);
									run=0;
								}

								else if (event2.key.keysym.sym==SDLK_KP1 && (strcmp(e.rep[e.num],"JollyRoger")==0))
								{
									SDL_BlitSurface(success,NULL,screen,&e.pos);
									SDL_Flip(screen);
									run=0;
								}

								else
								{ 
									SDL_BlitSurface(failure,NULL,screen,&e.pos);
									SDL_Flip(screen);
									vie--;
									run=0;
								}
						        }
							break;
						    }
						}
					}
					break;
				}
			}
				break;
		}
	}
return 0;
}
