#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "save.h"

int main(int argc, char *argv[])
{
SDL_Surface *screen=NULL,*back=NULL,*quit=NULL,*pause=NULL,*save=NULL;
SDL_Rect pos_back;
SDL_Event event;
SDL_Rect pos_pause,pos_quit,pos_save;
    screen=SDL_SetVideoMode(960, 400, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
back=IMG_Load("btp.jpg");
    pos_back.x=0;
    pos_back.y=0;
int done=1,b=1;
	SDL_BlitSurface(back,NULL,screen,&pos_back);
	pos_save.x=0;
	pos_save.y=0;
	pos_quit.x=250;
	pos_quit.y=70;
	pos_pause.x=250;
	pos_pause.y=70;
pause=IMG_Load("save/pause.png");

	quit=IMG_Load("save/quit.png");

	save=IMG_Load("save/save.png");

    SDL_Flip(screen);
	 while(done)
    {
	SDL_WaitEvent(&event);
        switch(event.type)
        {printf("error2");
		case SDL_QUIT:
			done=0;
			printf("error3");
		break;

		case SDL_KEYDOWN :
		    if(event.key.keysym.sym==SDLK_ESCAPE)
		        {
	SDL_BlitSurface(pause, NULL, screen, &pos_pause);
	SDL_BlitSurface(quit, NULL, screen, &pos_quit);
	SDL_BlitSurface(save, NULL, screen, &pos_save);
	SDL_Flip(screen);
printf("error4");}
		break;
	}
    }



}
