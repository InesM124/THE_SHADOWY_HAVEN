#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "save.h"
#include "menu.h"
#include "perso.h"

void init_menu(saving *s)
{
int i;
	s->pos_save.x=0;
	s->pos_save.y=0;
	s->pos_quit.x=0;
	s->pos_quit.y=0;
	s->pos_pause.x=0;
	s->pos_pause.y=0;

	s->pause=NULL;
	s->sure=NULL;
	s->quit=NULL;
	s->quit1=NULL;
	s->save=NULL;
	s->save1=NULL;
	s->quit_and_save=NULL;
	s->quit_no_save=NULL;
	s->quit_sous_menu=NULL;

	for (i=0; i<3; i++)
	{
		s->position[i].x=0;
		s->position[i].y=0;
	}

	s->pause=IMG_Load("save/pause.png");
	s->sure=IMG_Load("save/sure.png");
	s->quit1=IMG_Load("save/quit1.png");
	s->quit=IMG_Load("save/quit.png");

	s->save=IMG_Load("save/save.png");
	s->save1=IMG_Load("save/save1.png");
	s->quit_and_save=IMG_Load("save/quit_and_save.png");
	s->quit_no_save=IMG_Load("save/quit_no_save.png");
	s->quit_sous_menu=IMG_Load("save/quit_sous_menu.png");
}

void sauvegarder (hero c,int b,char fich[],SDL_Surface *screen)
{
saving s;

init_menu(&s);
SDL_Event event,event2;
FILE *f=NULL;
int done=1,run=1;

	SDL_BlitSurface(s.pause, NULL, screen, &s.pos_pause);
	SDL_BlitSurface(s.quit, NULL, screen, &s.pos_quit);
	SDL_BlitSurface(s.save, NULL, screen, &s.pos_save);
	SDL_Flip(screen);
while(done)
{


        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_KEYDOWN :
            if(event.key.keysym.sym==SDLK_ESCAPE)
		done=0;
	break;
        case SDL_MOUSEMOTION:
        {
            if (event.motion.x>288 && event.motion.x<472 && event.motion.y>275 && event.motion.y<330)
            {
                SDL_BlitSurface(s.quit1, NULL, screen, &s.pos_quit);
                SDL_Flip(screen);
            }
            else if (event.motion.x>513 && event.motion.x<696 && event.motion.y>275 && event.motion.y<330)
            {
                SDL_BlitSurface(s.save1, NULL, screen, &s.pos_save);
                SDL_Flip(screen);
            }
           else
            {
		SDL_BlitSurface(s.quit, NULL, screen, &s.pos_quit);
		SDL_BlitSurface(s.save, NULL, screen, &s.pos_save);
		SDL_Flip(screen);
            }
        }
	break;
        case SDL_MOUSEBUTTONDOWN :
        {
            if (event.motion.x>513 && event.motion.x<696 && event.motion.y>275 && event.motion.y<330)
            {
                f = fopen(fich, "w");
                if (f != NULL)
                {
                    fprintf(f,"%d %d %d %d",c.vie.valVie,c.score.scoreActuel,c.pos_hero.x, b);
                }
                fclose(f);
                done=0;
            }
            else if (event.motion.x>288 && event.motion.x<472 && event.motion.y>275 && event.motion.y<330)
            {
                SDL_BlitSurface(s.sure, NULL, screen, &s.pos_pause);
                SDL_BlitSurface(s.quit_sous_menu, NULL, screen, &s.position[0]);
                SDL_Flip(screen);
                while(run)
                {
                    SDL_WaitEvent(&event2);
                    switch(event2.type)
                    {
                    case SDL_MOUSEMOTION:
                    {
                        if (event2.motion.x>288 && event2.motion.x<472 && event2.motion.y>275 && event2.motion.y<330)
                        {
                            SDL_BlitSurface(s.quit_no_save, NULL, screen, &s.position[2]);
                            SDL_Flip(screen);
                        }
                        else if (event2.motion.x>513 && event2.motion.x<696 && event2.motion.y>275 && event2.motion.y<330)
                        {
                            SDL_BlitSurface(s.quit_and_save, NULL, screen, &s.position[1]);
                            SDL_Flip(screen);
                        }
                        else
                        {
                            SDL_BlitSurface(s.quit_sous_menu, NULL, screen, &s.position[0]);
                            SDL_Flip(screen);
                        }
                    }
                    break;
                    case SDL_MOUSEBUTTONDOWN :
                    {
                        if (event2.motion.x>288 && event2.motion.x<472 && event2.motion.y>275 && event2.motion.y<330)
                        {
                            run=0;
                            done=0;
                        }
                        else if (event2.motion.x>513 && event2.motion.x<696 && event2.motion.y>275 && event2.motion.y<330)
                        {
                            f = fopen(fich, "w");
                            if (f != NULL)
                            {
                                fprintf(f,"%i %i %i %i",c.vie.valVie,c.score.scoreActuel,c.pos_hero.x, b);
                            }
                            fclose(f);
                            run=0;
                            done=0;
                        }
                    }
                    break;
        	    case SDL_KEYDOWN :
            		if(event.key.keysym.sym==SDLK_ESCAPE)
				run=0;
				done=0;
		   break;
                    }
	        
                }
            }
        }
        break;
        }
}
}

int charger (hero *c,int *b,char fich[],SDL_Surface *screen)
{
FILE* f;
int pos;
f=fopen(fich,"r");
	if (f==NULL) 
	{
		printf("erreur d'ouverture du ficher\n");
	}
	else
	{
		fscanf(f,"%i %i %i %i",&(*c).vie.valVie,&(*c).score.scoreActuel ,&pos ,&(*b));
	}
fclose(f);
(*c).pos_hero.x=pos;
return 1;
}
