#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"

typedef struct second_entity
{
    SDL_Surface *sprite_monster;
    SDL_Rect  monster;
    SDL_Rect m[ 3 ];

    int frame;
    int direction;

} second_entity;

typedef struct collisionbb
{
    int x;
    int y;
    int w;
    int h;
} collisionbb;

void clipping (second_entity * enemy);
void clipping2 (second_entity * enemy);
void clipping6 (second_entity * enemy);
void clipping5 (second_entity * enemy);
void clipping4 (second_entity * enemy);
void clipping3 (second_entity * enemy);
void initializemonster(second_entity * enemy);
void initializemonster1(second_entity * enemy);
void initializemonster3(second_entity * enemy);
void initializemonster2(second_entity * enemy);
void initializemonster4(second_entity * enemy);
void afficher ( second_entity * enemy, SDL_Surface* back, SDL_Rect relcoord );
void afficher2 ( second_entity * enemy, SDL_Surface* back, SDL_Rect relcoord );
void afficher3 ( second_entity * enemy, SDL_Surface* back, SDL_Rect relcoord );
void afficher4 ( second_entity * enemy, SDL_Surface* back, SDL_Rect relcoord );
void afficher6 ( second_entity * enemy, SDL_Surface* screen ,SDL_Rect relcoord);
void afficher5 ( second_entity * enemy, SDL_Surface* screen ,SDL_Rect relcoord);
void animate_monster(second_entity * enemy);
void move_monster(second_entity * enemy);
void move_monster2(second_entity * enemy);
int collision_bb(SDL_Rect camera, second_entity *enemy);
