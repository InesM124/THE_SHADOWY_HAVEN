#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
/** 
* @struct enigme 
* @brief struct for enigme 
*/
typedef struct
{
	SDL_Surface *background1,*background2,*question[4];
	SDL_Rect pos,pos_text;
	int num;
	char rep[4][20];
}enig;

int main_enigme(int *vie);
//void text_ttf(char ch[20],TTF_Font *police,SDL_Surface *text,SDL_Surface *screen,SDL_Rect pos,SDL_Color white,int x);
void init_enigme(enig *e);
void afficher_enigme(SDL_Surface *screen, enig *e);
void generer_enigme(SDL_Surface *screen, enig *e,char quest[],char answ[]);
