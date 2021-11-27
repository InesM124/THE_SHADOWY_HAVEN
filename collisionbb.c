#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "f.h"

int coll_bb(collisionbb1* obstacle ,SDL_Rect camera )
{
obstacle->x=797;
    obstacle->y=300;
    obstacle->w=98;
    obstacle->h=64;

    if ((obstacle->x + obstacle->w< (camera.x+150)) || (obstacle->x> (camera.x+150) + camera.w) ||(obstacle->y + obstacle->h< camera.y) ||
            (obstacle->y> camera.y + camera.h ))
        return 0;
    else
        return 1;
}

int coll_bb1(collisionbb1* obstacle ,SDL_Rect camera )
{
obstacle->x=1336;
    obstacle->y=311;
    obstacle->w=61;
    obstacle->h=50;

    if ((obstacle->x + obstacle->w< (camera.x+150)) || (obstacle->x> (camera.x+150) + camera.w) ||(obstacle->y + obstacle->h< camera.y) ||
            (obstacle->y> camera.y + camera.h ))
        return 0;
    else
        return 1;
}

int coll_bb2(collisionbb1* obstacle ,SDL_Rect camera )
{
obstacle->x=2675;
    obstacle->y=313;
    obstacle->w=82;
    obstacle->h=49;

    if ((obstacle->x + obstacle->w< (camera.x+150)) || (obstacle->x> (camera.x+150) + camera.w) ||(obstacle->y + obstacle->h< camera.y) ||
            (obstacle->y> camera.y + camera.h ))
        return 0;
    else
        return 1;
}

int coll_bb3(collisionbb1* obstacle ,SDL_Rect camera )
{
obstacle->x=4406;
    obstacle->y=296;
    obstacle->w=31;
    obstacle->h=77;

    if ((obstacle->x + obstacle->w< (camera.x+150)) || (obstacle->x> (camera.x+150) + camera.w) ||(obstacle->y + obstacle->h< camera.y) ||
            (obstacle->y> camera.y + camera.h ))
        return 0;
    else
        return 1;
}

int coll_bb4(collisionbb1* obstacle ,SDL_Rect camera )
{
obstacle->x=8105;
    obstacle->y=294;
    obstacle->w=519;
    obstacle->h=79;

    if ((obstacle->x + obstacle->w< (camera.x+150)) || (obstacle->x> (camera.x+150) + camera.w) ||(obstacle->y + obstacle->h< camera.y) ||
            (obstacle->y> camera.y + camera.h ))
        return 0;
    else
        return 1;
}



