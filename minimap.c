#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "minimap.h"

void initminimap(minim *mini)
{

	mini->minimap = NULL;

	mini->miniheroright = NULL;
	mini->miniheroleft = NULL;

	mini->positionminihero.x = 0;
	mini->positionminihero.y = 400;

	mini->positionminimap.x = 0;
	mini->positionminimap.y = 370;


	mini->miniheroright = IMG_Load("images/right.png");
	mini->miniheroleft = IMG_Load("images/left.png");

	mini->minimap = IMG_Load("images/minimap.png");

	mini->ground = 400;
}

void blitminimap(minim *mini, SDL_Surface *screen, int choix)
{

	switch (choix)
	{

	case 1:
		SDL_BlitSurface(mini->minimap, NULL, screen, &(mini->positionminimap));
		SDL_BlitSurface(mini->miniheroright, NULL, screen, &(mini->positionminihero));
		break;

	case 2:
		SDL_BlitSurface(mini->minimap, NULL, screen, &(mini->positionminimap));
		SDL_BlitSurface(mini->miniheroleft, NULL, screen, &(mini->positionminihero));
		break;
	}
}

void miniJump(minim *mini, int choix)
{
    if(choix==1)
    {
        mini->positionminihero.x+=9;
        mini->positionminihero.y-=7;
    }

    if (choix==2)
    {
        mini->positionminihero.x-=9;
        mini->positionminihero.y-=7;
    }
mini->positionminihero.y=mini->ground;

}

void deplacementminihero(minim *mini, int direction)
{

	switch (direction)
	{
	case 1:
		mini->positionminihero.x += 1;
	break;

	case 2:
		mini->positionminihero.x -= 1;
	break;
	}
}

