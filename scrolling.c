#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "scrolling.h"


void scrolling(SDL_Rect *camera, SDL_Rect *test)
{
    camera->x += 13;
    test->x += 13;
    if (camera->x >= 11500 - 446) 
    {
        camera->x = 11500;
    }
}

void scrollingb(SDL_Rect *camera, SDL_Rect *test)
{
    camera->x -= 13;
    test->x -= 13;
    if (camera->x <= 0) 
    {
        camera->x = 10;
    }
}

