/** 
* @file enigme.c 
* @brief generer enigme
* @author Ben Mbarek Amira
* @version 1.0
* @date Apr 22, 2021 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include "menu.h"



void init_enigme(enig *e)
{
int i;
	e->pos.x=0;
	e->pos.y=0;
	e->pos_text.x=250;
	e->pos_text.y=70;
	e->background1=NULL;
	e->background2=NULL;
	for (i=0;i<4;i++)
	{
		e->question[i]=NULL;
	}
	/*for (i=0;i<4;i++)
	{
		e->rep[i]=0;
	}*/
	e->num=0;
}

void afficher_enigme(SDL_Surface *screen, enig *e)
{
	SDL_Surface *text=NULL;
	SDL_Rect pos_text[4];
	TTF_Font *police=NULL;
	SDL_Color white={255,255,255},black={0,0,0},purple={160,0,170},red={255,0,0};
	TTF_Init();

	e->background1=IMG_Load("enigme/shore.png");
	SDL_BlitSurface(e->background1,NULL,screen,&e->pos);

	pos_text[0].x=210; pos_text[0].y=360;
	pos_text[1].x=160; pos_text[1].y=390;
	pos_text[2].x=190; pos_text[2].y=100;
	pos_text[3].x=660; pos_text[3].y=420;
	
	text_ttf("Let's test your knowledge",police,text,screen,pos_text[0],black,30);
	text_ttf("Solve the riddle to advance to the next level",police,text,screen,pos_text[1],black,30);
	text_ttf("Riddle Time !",police,text,screen,pos_text[2],purple,55);
	text_ttf("Press 'enter' to continue",police,text,screen,pos_text[3],red,20);
}

void generer_enigme(SDL_Surface *screen, enig *e,char quest[],char answ[])
{
	char questions[10][50];
	SDL_Surface *quest2[8];
	int *alea,i,j=0,k=0;
	FILE *qfile,*afile;

	TTF_Font *police = NULL;
	SDL_Color black={0,0,0};
	TTF_Init();
	police = TTF_OpenFont("Blanchope Free.ttf", 40);

	e->question[0] = IMG_Load("enigme/question1.png");
	e->question[1] = IMG_Load("enigme/question2.png");
	e->question[2] = IMG_Load("enigme/question3.png");
	e->question[3] = IMG_Load("enigme/question4.png");


	qfile=fopen(quest,"r");
	if (qfile == NULL)
		printf("Questions file Error\n");

	afile=fopen(answ, "r");
	if (afile == NULL)
		printf("Answers file Error\n");

	while (getc(qfile)!=EOF)
	{
		fgets(questions[j], 50, qfile);
		j++;
	}

	while (getc(afile)!=EOF)
	{
		fscanf(afile,"%s",&e->rep[k][20]);
		k++;
	}


	for (i=0;i<4;i++)
	{
		quest2[i]=TTF_RenderText_Blended(police, questions[i], black);
	}

	srand(time(NULL));
	*alea=rand()%4;

	SDL_BlitSurface(e->question[*alea], NULL, screen, &(e->pos));
	SDL_BlitSurface(quest2[*alea],NULL,screen,&e->pos_text);
        SDL_Flip(screen);

	e->num=*alea;

	fclose(qfile);
	fclose(afile);
}



