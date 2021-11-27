#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include "perso.h"
#include "scrolling.h"
#include <string.h>

void init(hero *hero)
{
    char string[20];
    SDL_Color white = {220,20,60};

    hero->spriteright = NULL;
    hero->spriteleft = NULL;
    hero->pos_hero.x = 0;
    hero->pos_hero.y = 330;
    hero->pos_hero.w = 60;
    hero->pos_hero.h = 200;
    hero->testt.x = 0; //scrolling de perso
    hero->testt.y = 330;
    hero->frame = 0;
    hero->spriteright = IMG_Load("spriteright.png");
    hero->spriteleft = IMG_Load("spriteleft.png");
    hero->ground=330;
    hero->vie.vie1=IMG_Load("vie1.png");
    hero->vie.vie2=IMG_Load("vie2.png");
    hero->vie.vie3=IMG_Load("vie3.png");
    hero->vie.vie0=IMG_Load("vie0.png");
    hero->vie.posVie.x=700;
    hero->vie.posVie.y=-25;
    hero->vie.valVie=3;
    hero->score.posScore.x=670 ;
    hero->score.posScore.y=40;
    hero->score.posFond.x=530;
    hero->score.posFond.y=10;

    hero->score.fondScore = IMG_Load("score0.png");
    (hero->score.police) = TTF_OpenFont("Blanchope Free.ttf", 20);
    hero->score.scoreActuel=0;
    sprintf(string, "score = %d ", hero->score.scoreActuel);

    (hero->score.texteScore)=TTF_RenderText_Blended(hero->score.police,string, white);
}
void init2(hero *hero)
{

    char string[20];
    SDL_Color white = {220,20,60};
    hero->spriteright = NULL;
    hero->spriteleft = NULL;
    hero->pos_hero.x = 20;
    hero->pos_hero.y = 330;
    hero->pos_hero.w = 60;
    hero->pos_hero.h = 200;
    hero->frame = 0;
    hero->spriteright = IMG_Load("right2.png");
    hero->spriteleft = IMG_Load("left2.png");
    hero->ground=330;
    hero->vie.vie1=IMG_Load("vie1.png");
    hero->vie.vie2=IMG_Load("vie2.png");
    hero->vie.vie3=IMG_Load("vie3.png");
    hero->vie.vie0=IMG_Load("vie0.png");
    hero->vie.posVie.x=-90;
    hero->vie.posVie.y=-25;
    hero->vie.valVie=3;
    hero->score.posScore.x=232 ;
    hero->score.posScore.y=40;
    hero->score.posFond.x=70;
    hero->score.posFond.y=5;

    hero->score.fondScore = IMG_Load("score0.png");
    (hero->score.police) = TTF_OpenFont("Blanchope Free.ttf", 20);

    hero->score.scoreActuel=0;
    sprintf(string, "score = %d ", hero->score.scoreActuel);

    (hero->score.texteScore)=TTF_RenderText_Blended(hero->score.police,string, white);
}
void setright(hero* hero)
{
    hero->rectright[0].x = 35;
    hero->rectright[0].y = 0;
    hero->rectright[0].w = 28;
    hero->rectright[0].h = 42.64;

    hero->rectright[1].x = 3;
    hero->rectright[1].y = 0;
    hero->rectright[1].w = 28;
    hero->rectright[1].h = 42.64;

    hero->rectright[2].x = 68;
    hero->rectright[2].y = 0;
    hero->rectright[2].w = 28;
    hero->rectright[2].h = 42.66;
}

void setleft(hero* hero)
{
    hero->rectleft[0].x = 35;
    hero->rectleft[0].y = 0;
    hero->rectleft[0].w = 28;
    hero->rectleft[0].h = 42.66;

    hero->rectleft[1].x = 3;
    hero->rectleft[1].y = 0;
    hero->rectleft[1].w = 28;
    hero->rectleft[1].h = 42.66;

    hero->rectleft[2].x = 68;
    hero->rectleft[2].y = 0;
    hero->rectleft[2].w = 28;
    hero->rectleft[2].h = 42.66;

}
void animation(hero *hero)
{

    if (hero->frame <= 2)
    {
        hero->frame += 1;
    }

    if (hero->frame > 2)
    {
        hero->frame = 0;
    }



}
void deplacerhero(hero *hero)
{
    animation(hero);

    switch (hero->directionhero)
    {
    case 1:
    {
        hero->pos_hero.x +=4 ;
	hero->testt.x += 4;
    }
    break;

    case 2:
    {
        hero->pos_hero.x -= 4;
	hero->testt.x -= 4;
    }
    break;
    }
}
void deplacerhero_avec_acceleration(hero *hero)
{
    animation(hero);

    switch (hero->directionhero)
    {
    case 1:
    {
        hero->pos_hero.x += 24;
        SDL_Delay(50);
        animation(hero);
	hero->testt.x += 24;
    }
    break;

    case 2:
    {
        hero->pos_hero.x -= 24;
        SDL_Delay(50);
        animation(hero);
	hero->testt.x += 24;
    }
    break;
    }
}

void blithero(hero *hero, SDL_Surface *screen, int choix)
{
    switch (choix)
    {
    case 1:
    {
        SDL_BlitSurface(hero->spriteright, &(hero->rectright[hero->frame]), screen, &(hero->pos_hero));

    }
    break;
    case 2:
    {
        SDL_BlitSurface(hero->spriteleft, &(hero->rectleft[hero->frame]), screen, &(hero->pos_hero));

    }
    break;
    }

}



int nbVie(int gameOver,Vie vie, SDL_Surface *screen)
{

    if (vie.valVie==0)
    {
        gameOver=0;
        SDL_BlitSurface(vie.vie0, NULL, screen,&vie.posVie);
    }
    else if (vie.valVie==1)
    {
        SDL_BlitSurface(vie.vie1, NULL, screen, &vie.posVie);
    }
    else if (vie.valVie==2)
    {
        SDL_BlitSurface(vie.vie2, NULL, screen, &vie.posVie);
    }
    else if (vie.valVie==3)
    {
        SDL_BlitSurface(vie.vie3, NULL, screen, &vie.posVie);
    }
    SDL_Flip(screen);

    return gameOver;
}


void afficherScore(SDL_Surface *ecran, Score *score,int s )
{


    SDL_Color white = {85,107,47};

    char string[20];

    score->scoreActuel=s;
    sprintf(string, "score = %d ", score->scoreActuel);

    score->texteScore =TTF_RenderText_Blended(score->police,string, white);


    SDL_BlitSurface(score->fondScore, NULL, ecran, &score->posFond);
    SDL_BlitSurface(score->texteScore, NULL, ecran, &score->posScore);
}

void jump(hero *hero,SDL_Surface *screen,SDL_Rect pos_back,SDL_Surface *back,int choix,int *s,SDL_Rect camera)
{
    int i;



    if(choix==1)

    {

       // camera.x+=10;

	hero->pos_hero.x+=200;

        hero->pos_hero.y-=60;

	//scrolling(&camera, &hero->testt);

        (*s)+=6;


            SDL_BlitSurface(back,&camera,screen,&pos_back);

           // SDL_Delay(50);

            animation(hero);

            blithero(hero,screen,choix);

            hero->frame++;
 }



    if (choix==2)

    {

        //camera.x-=10;

	hero->pos_hero.x-=200;

        hero->pos_hero.y-=100;

        SDL_BlitSurface(back,&camera,screen,&pos_back);

        animation(hero);

        blithero(hero,screen,choix);

    }

}


void restartjump(hero *hero,SDL_Surface *screen,SDL_Rect pos_back,SDL_Surface *back,int choix,SDL_Rect camera)

{

    int i;

    if (choix==1)

    {

       // camera.x+=30;
	hero->pos_hero.x+=200;

        hero->pos_hero.y=hero->ground;

        

            SDL_BlitSurface(back,&camera,screen,&pos_back);

           // SDL_Delay(50);

            animation(hero);

            blithero(hero,screen,choix);

            hero->frame++;
        }

    if (choix==2)

    {

        //camera.x-=30;
	hero->pos_hero.x-=200;

        hero->pos_hero.y=hero->ground;

        SDL_BlitSurface(back,&camera,screen,&pos_back);

        animation(hero);

        blithero(hero,screen,choix);

    }

}

