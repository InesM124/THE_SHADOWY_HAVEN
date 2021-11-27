#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "monster1.h"

void clipping (second_entity * enemy)
{
    int i;

    for(i=0; i<3; i++)
    {
        enemy->m[ i ].x = 33 * i;
        enemy->m[ i ].y = 0;
        enemy->m[ i ].w = 33;
        enemy->m[ i ].h = 35;
    }
}

void clipping2 (second_entity * enemy)
{
    int i;

    for(i=0; i<3; i++)
    {
        enemy->m[ i ].x = 33 * i;
        enemy->m[ i ].y = 35;
        enemy->m[ i ].w = 33;
        enemy->m[ i ].h = 35;
    }
}

void clipping3 (second_entity * enemy)

{

    int i;



    for(i=0; i<3; i++)

    {

        enemy->m[ i ].x = 131 * i;

        enemy->m[ i ].y = 0;

        enemy->m[ i ].w = 131;

        enemy->m[ i ].h = 97;

    }

}



void clipping4 (second_entity * enemy)

{

    int i;



    for(i=0; i<3; i++)

    {

        enemy->m[ i ].x = 131 * i;

        enemy->m[ i ].y = 97;

        enemy->m[ i ].w = 131;

        enemy->m[ i ].h = 97;

    }

}

void clipping5 (second_entity * enemy)

{

    int i;



    for(i=0; i<3; i++)

    {

        enemy->m[ i ].x = 116 * i;

        enemy->m[ i ].y = 0;

        enemy->m[ i ].w = 116;

        enemy->m[ i ].h = 77;

    }

}

void clipping6 (second_entity * enemy)

{

    int i;



    for(i=0; i<3; i++)

    {

        enemy->m[ i ].x = 116 * i;

        enemy->m[ i ].y = 77;

        enemy->m[ i ].w = 116;

        enemy->m[ i ].h = 77;

    }

}





void initializemonster(second_entity * enemy)
{

    enemy->sprite_monster = IMG_Load("lapras.png");


    enemy->monster.x = 360;
    enemy->monster.y = 280;
    enemy->frame=0;

    enemy->direction=0;

}
void initializemonster1(second_entity * enemy)
{
   enemy->sprite_monster = IMG_Load("lapras.png");


    enemy->monster.x = 2270;
    enemy->monster.y = 280;
    enemy->frame=0;

    enemy->direction=0;

}

void initializemonster2(second_entity * enemy)
{

    enemy->sprite_monster = IMG_Load("monster_sprite.png");


    enemy->monster.x = 4500;
    enemy->monster.y = 330;
    enemy->frame=0;

    enemy->direction=0;

}

void initializemonster3(second_entity * enemy)
{

    enemy->sprite_monster = IMG_Load("monster_sprite.png");


    enemy->monster.x = 6000;
    enemy->monster.y = 330;
    enemy->frame=0;

    enemy->direction=0;

}

void initializemonster4(second_entity * enemy)
{

    enemy->sprite_monster = IMG_Load("lava_monster.png");


    enemy->monster.x = 8000;
    enemy->monster.y = 300;
    enemy->frame=0;

    enemy->direction=0;

}
void afficher ( second_entity * enemy, SDL_Surface* screen, SDL_Rect relcoord )
{
    clipping (enemy);
    SDL_BlitSurface(enemy->sprite_monster, &(enemy->m[enemy->frame]), screen, &relcoord);
    SDL_Flip(screen);

}

void afficher2 ( second_entity * enemy, SDL_Surface* screen ,SDL_Rect relcoord)
{
    clipping2 (enemy);
    SDL_BlitSurface(enemy->sprite_monster, &(enemy->m[enemy->frame]), screen, &relcoord);
    SDL_Flip(screen);

}

void afficher3 ( second_entity * enemy, SDL_Surface* screen ,SDL_Rect relcoord)
{
    clipping3 (enemy);
    SDL_BlitSurface(enemy->sprite_monster, &(enemy->m[enemy->frame]), screen, &relcoord);
    SDL_Flip(screen);

}

void afficher4 ( second_entity * enemy, SDL_Surface* screen ,SDL_Rect relcoord)
{
    clipping4 (enemy);
    SDL_BlitSurface(enemy->sprite_monster, &(enemy->m[enemy->frame]), screen, &relcoord);
    SDL_Flip(screen);

}

void afficher5 ( second_entity * enemy, SDL_Surface* screen ,SDL_Rect relcoord)
{
    clipping5 (enemy);
    SDL_BlitSurface(enemy->sprite_monster, &(enemy->m[enemy->frame]), screen, &relcoord);
    SDL_Flip(screen);

}

void afficher6 ( second_entity * enemy, SDL_Surface* screen ,SDL_Rect relcoord)
{
    clipping6 (enemy);
    SDL_BlitSurface(enemy->sprite_monster, &(enemy->m[enemy->frame]), screen, &relcoord);
    SDL_Flip(screen);

}





void animate_monster(second_entity * enemy)
{

    if (enemy->frame <= 2)
    {
        enemy->frame += 1;
    }

    if (enemy->frame >=2)
    {
        enemy->frame = 0;
    }

}

void move_monster(second_entity * enemy)
{
    /* if (enemy->monster.x>700)
                    enemy->direction=1;
       if (enemy->direction==1) */
    enemy->monster.x-=1;
}

void move_monster2(second_entity * enemy)
{
    /* if(enemy->monster.x<100)
                   enemy->direction=0;
      if (enemy->direction==0)*/
    enemy->monster.x+=1;
}

int collision_bb(SDL_Rect camera, second_entity *enemy)
{

    if (((camera.x+300)+ camera.w< enemy->monster.x) || ((camera.x+300)> enemy->monster.x + enemy->monster.w) ||(camera.y + camera.h< enemy->monster.y) ||

            (camera.y> enemy->monster.y + enemy->monster.h ))

        return 0;

    else

        return 1;

}








