#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

struct minimap
{
	SDL_Surface *minimap,*miniheroright,*miniheroleft;
	SDL_Rect positionminihero,positionminimap;
	int ground;
	 
};

typedef struct minimap minim;

void initminimap (minim *mini);
void blitminimap (minim *mini,SDL_Surface* screen,int choix);
void deplacementminihero (minim *mini,int direction);

void miniJump (minim *mini,int choix);
