#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

void text_ttf(char ch[20],TTF_Font *police,SDL_Surface *text,SDL_Surface *screen,SDL_Rect pos,SDL_Color white,int x);
void liberation (TTF_Font *police ,SDL_Surface *screen, SDL_Surface *newgame, SDL_Surface *newgame1, SDL_Surface *load, SDL_Surface *load1, SDL_Surface *options, SDL_Surface *options1, SDL_Surface *credits, SDL_Surface *credits1, SDL_Surface *quit, SDL_Surface *quit1,SDL_Surface *text, SDL_Surface *background,Mix_Music *musique);
void animation_stars(SDL_Surface *star,SDL_Surface *star2,SDL_Surface *star3,SDL_Surface *star_back,SDL_Surface *star_back2,SDL_Surface *star_back3,SDL_Surface *screen,SDL_Rect pos_star);
void menu(SDL_Surface *screen, SDL_Surface *newgame, SDL_Surface *load, SDL_Surface *options, SDL_Surface * credits, SDL_Surface *quit,SDL_Rect pos_new,SDL_Rect pos_load,SDL_Rect pos_options,SDL_Rect pos_credits,SDL_Rect pos_quit, SDL_Rect pos_back);
void credit(SDL_Surface *screen,Mix_Chunk *effect,Mix_Chunk *effect2,TTF_Font *police,SDL_Surface *text,SDL_Color white);
void sous_menu(SDL_Surface *screen, Mix_Chunk *effect, Mix_Chunk *effect2,SDL_Surface *text,TTF_Font *police,SDL_Color white, Mix_Music *musique,int *volume);

