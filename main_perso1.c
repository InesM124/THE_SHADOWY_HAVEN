#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
#include "enigme.h"
#include "save.h"
#include "monster1.h"
#include "scrolling.h"
#include "f.h"
#include "background.h"
#include "minimap.h"

int main_perso1(SDL_Surface *screen,hero c)
{

    //hero c;
	second_entity enemy,enemy1,enemy2,enemy3,enemy4;
	E_S boss;
    SDL_Surface *back=NULL;
    SDL_Rect pos_back,camera;
    Mix_Chunk *effect=NULL;
    SDL_Event event,event1;
    int done=1,choix=1,gameOver=3,s=0,k=0,s1=0,gameOver1=3,choix1=1,k1=0,enigme,colob,colob2,colen,colen1,colen2,colen3,colen4,i,colob_enemy1;
	int colob_enemy2,colob_enemy3,colob_enemy4,colob_enemy5,colob2_enemy1,colob2_enemy2,colob2_enemy3,colob2_enemy4,p=0;   
    
    collisionbb1 obstacle,cam,obstacle1,obstacle2,obstacle3,obstacle4,obstacle5;
    SDL_BlitSurface(back,&camera,screen,&pos_back);

    SDL_Flip(screen);
    const Uint8 * keystate = SDL_GetKeyState(NULL);
minim mini;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    effect=Mix_LoadWAV("selection.wav");
pos_back.x=0;
pos_back.y=0;
back=IMG_Load("map3.png");    
TTF_Init();
    init(&c);

    setright(&c);
    setleft(&c);
initminimap(&mini);
    initializemonster(&enemy);
initializemonster1(&enemy1);
initializemonster2(&enemy2);
initializemonster3(&enemy3);
initializemonster4(&enemy4);
initializem(&boss);
    camera.x = 0;
    camera.y = 0;
    camera.h = 446;
    camera.w = 1000;
    SDL_EnableKeyRepeat(150,150);
    blithero(&c,screen,choix);
blitminimap (&mini,screen,1);
    while(done)
    {

SDL_Rect location = {camera.x,camera.y,1000,446};    

        /*colob_enemy5=coll_bb5(&obstacle5,camera);
        if(colob_enemy5==1)
        {
            //printf("collision between hero and obstacle\n");
            enigme=main_enigme(&c.vie.valVie);
        }*/

SDL_Rect relcoord5 = {boss.monster.x-camera.x,boss.monster.y-camera.y};

if (collision(&location,&boss.monster)) 
{

if (boss.monster.x>9950)
                  boss.direction=1;
              else  if(boss.monster.x<9800)
                  boss.direction=0;
   updateEnemy (&boss,& camera ) ;
       
            switch (boss.etat)
   { 
      case waiting:
       
       // l'ennemi s'anime mais reste à la même position 
        if (boss.direction==1)
       { aff2 ( &boss,  screen,relcoord5 );
       animate_monsterB(&boss);
        SDL_BlitSurface(back,&camera,screen,&pos_back);
	blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);

                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

}
       else if (boss.direction==0)
         { aff1 ( &boss,  screen,relcoord5 );
   animate_monsterB(&boss);
SDL_BlitSurface(back,&camera,screen,&pos_back);
	blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);
  }
  
      break;
      case following:
        
         if (boss.direction==1)
       {aff2 ( &boss,  screen,relcoord5 );
         animate_monsterB(&boss);
 SDL_BlitSurface(back,&camera,screen,&pos_back);
	blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

         //SDL_BlitSurface(back,NULL,screen,&pos_back);
         move_monsterB(&boss);
}
      else if (boss.direction==0)
          { aff1 ( &boss,  screen,relcoord5 );
   animate_monsterB(&boss);
   SDL_BlitSurface(back,&camera,screen,&pos_back);
	blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

 move_monster2B(&boss);


  }



      break;
     case attacking:

      if (boss.direction==1)
{   for(i=0;i<3;i++) 
      {
        boss.m[ i ].x = 100 * i;
        boss.m[ i ].y = 300;
        boss.m[ i ].w = 100;
        boss.m[ i ].h = 100;
      }
    
   
   SDL_BlitSurface(boss.sprite_monster, &(boss.m[boss.frame]), screen, &relcoord5);
   SDL_Flip(screen);
  



         animate_monsterB(&boss);
 SDL_BlitSurface(back,&camera,screen,&pos_back);
	blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

         //SDL_BlitSurface(background,NULL,screen,&pos_back);
         move_monsterB(&boss);

}
 else if (boss.direction==0)
  {for(i=0;i<3;i++) 
      {
        boss.m[ i ].x = 100 * i;
        boss.m[ i ].y = 200;
        boss.m[ i ].w = 100;
        boss.m[ i ].h = 100;
      }
    
   
   SDL_BlitSurface(boss.sprite_monster, &(boss.m[boss.frame]), screen, &relcoord5);
   SDL_Flip(screen);
  



         animate_monsterB(&boss);
 SDL_BlitSurface(back,&camera,screen,&pos_back);
	blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

         //SDL_BlitSurface(background,NULL,screen,&pos_back);
 move_monster2B(&boss); 

}

      break;
}

        gameOver=nbVie(gameOver,c.vie,screen);

        c.score.posFond.y=-25;


        if (s<=0)
            s=0;


}

SDL_Rect relcoord4 = {enemy4.monster.x-camera.x,enemy4.monster.y-camera.y};

if (collision(&location,&enemy4.monster))    
    {
 if (enemy4.monster.x>7950)
            enemy4.direction=1;
        else  if(enemy4.monster.x<7800)
            enemy4.direction=0;


        if (enemy4.direction==1)
        {
            afficher5 ( &enemy4,  screen ,relcoord4);

            animate_monster(&enemy4);
            SDL_BlitSurface(back,&camera,screen,&pos_back);
		blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

            move_monster(&enemy4);

            colen4=collision_bb(camera,&enemy4);
            if(colen4==1)
            {
               // printf("collision between monster and hero\n");
                c.vie.valVie--;
                gameOver=nbVie(gameOver,c.vie,screen);
            }

        }

        else if (enemy4.direction==0)
        {
            afficher6 ( &enemy4,  screen ,relcoord4);

            animate_monster(&enemy4);
            SDL_BlitSurface(back,&camera,screen,&pos_back);
		blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

            move_monster2(&enemy4);

            colen4=collision_bb(camera,&enemy4);
            if(colen4==1)
            {
                //printf("collision between monster and hero\n");
                c.vie.valVie--;
                gameOver=nbVie(gameOver,c.vie,screen);
            }

        }

        colob_enemy4=coll_bb4(&obstacle4,camera);
        if(colob_enemy4==1)
        {
            //printf("collision between hero and obstacle\n");
            while (s>0)
                s-=10;
        }
        colob2_enemy4=coll_bb4(&obstacle4,camera);
          if(colob2_enemy4==1)
          {//printf("collision between hero2 and obstacle\n");
           while (s1>0)
            s1-=10;
          }

        gameOver=nbVie(gameOver,c.vie,screen);

        c.score.posFond.y=-25;

        if (s<=0)
            s=0;
	}


SDL_Rect relcoord3 = {enemy3.monster.x-camera.x,enemy3.monster.y-camera.y};

if (collision(&location,&enemy3.monster))    
    {
 if (enemy3.monster.x>5900)
            enemy3.direction=1;
        else  if(enemy3.monster.x<5750)
            enemy3.direction=0;


        if (enemy3.direction==1)
        {
            afficher ( &enemy3,  screen ,relcoord3);

            animate_monster(&enemy3);
            SDL_BlitSurface(back,&camera,screen,&pos_back);
		blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

            move_monster(&enemy3);

            colen3=collision_bb(camera,&enemy3);
            if(colen3==1)
            {
               // printf("collision between monster and hero\n");
                c.vie.valVie--;
                gameOver=nbVie(gameOver,c.vie,screen);
            }

        }

        else if (enemy3.direction==0)
        {
            afficher2 ( &enemy3,  screen ,relcoord3);

            animate_monster(&enemy3);
            SDL_BlitSurface(back,&camera,screen,&pos_back);
		blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

            move_monster2(&enemy3);

           colen3=collision_bb(camera,&enemy3);
            if(colen3==1)
            {
                //printf("collision between monster and hero\n");
                c.vie.valVie--;
                gameOver=nbVie(gameOver,c.vie,screen);
            }
        }

        colob_enemy3=coll_bb3(&obstacle3,camera);
        if(colob_enemy3==1)
        {
            //printf("collision between hero and obstacle\n");
            while (s>0)
                s-=10;
        }

        gameOver=nbVie(gameOver,c.vie,screen);

        c.score.posFond.y=-25;



        if (s<=0)
            s=0;
	}



SDL_Rect relcoord2 = {enemy2.monster.x-camera.x,enemy2.monster.y-camera.y};
if (collision(&location,&enemy2.monster))    
    {
 if (enemy2.monster.x>4400)
            enemy2.direction=1;
        else  if(enemy2.monster.x<4250)
            enemy2.direction=0;


        if (enemy2.direction==1)
        {
            afficher ( &enemy2,  screen ,relcoord2);

            animate_monster(&enemy2);
            SDL_BlitSurface(back,&camera,screen,&pos_back);
		blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

            move_monster(&enemy2);

            colen2=collision_bb(camera,&enemy2);
            if(colen2==1)
            {
               // printf("collision between monster and hero\n");
                c.vie.valVie--;
                gameOver=nbVie(gameOver,c.vie,screen);
            }

        }

        else if (enemy1.direction==0)
        {
            afficher2 ( &enemy2,  screen ,relcoord2);

            animate_monster(&enemy1);
            SDL_BlitSurface(back,&camera,screen,&pos_back);
		blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

            move_monster2(&enemy2);

            colen2=collision_bb(camera,&enemy2);
            if(colen2==1)
            {
                //printf("collision between monster and hero\n");
                c.vie.valVie--;
                gameOver=nbVie(gameOver,c.vie,screen);
            }

        }

        colob_enemy2=coll_bb2(&obstacle2,camera);
        if(colob_enemy2==1)
        {
            //printf("collision between hero and obstacle\n");
            while (s>0)
                s-=10;
        }

        gameOver=nbVie(gameOver,c.vie,screen);

        c.score.posFond.y=-25;



        if (s<=0)
            s=0;
	}




SDL_Rect relcoord1 = {enemy1.monster.x-camera.x,enemy1.monster.y-camera.y};

if (collision(&location,&enemy1.monster))    
    {
 if (enemy1.monster.x>2250)
            enemy1.direction=1;
        else  if(enemy1.monster.x<2100)
            enemy1.direction=0;


        if (enemy1.direction==1)
        {
            afficher3 ( &enemy1,  screen ,relcoord1);

            animate_monster(&enemy1);
            SDL_BlitSurface(back,&camera,screen,&pos_back);
		blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

            move_monster(&enemy1);

            colen1=collision_bb(camera,&enemy1);
            if(colen1==1)
            {
               // printf("collision between monster and hero\n");
                c.vie.valVie--;
                gameOver=nbVie(gameOver,c.vie,screen);
            }

        }

        else if (enemy1.direction==0)
        {
            afficher4 ( &enemy1,  screen ,relcoord1);

            animate_monster(&enemy1);
            SDL_BlitSurface(back,&camera,screen,&pos_back);
		blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

            move_monster2(&enemy1);

            colen1=collision_bb(camera,&enemy1);
            if(colen1==1)
            {
                //printf("collision between monster and hero\n");
                c.vie.valVie--;
                gameOver=nbVie(gameOver,c.vie,screen);
            }
        }

        colob_enemy1=coll_bb1(&obstacle1,camera);
        if(colob_enemy1==1)
        {
            //printf("collision between hero and obstacle\n");
            while (s>0)
                s-=10;
        }

        gameOver=nbVie(gameOver,c.vie,screen);

        c.score.posFond.y=-25;



        if (s<=0)
            s=0;
	}

 
SDL_Rect relcoord = {enemy.monster.x-camera.x,enemy.monster.y-camera.y};
if (collision(&location,&enemy.monster))    
    {
 if (enemy.monster.x>350)
            enemy.direction=1;
        else  if(enemy.monster.x<200)
            enemy.direction=0;

        if (enemy.direction==1)
        {
            afficher3 ( &enemy,  screen ,relcoord);

            animate_monster(&enemy);
            SDL_BlitSurface(back,&camera,screen,&pos_back);
		blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

            move_monster(&enemy);

            colen=collision_bb(camera,&enemy);
            if(colen==1)
            {
                //printf("collision between monster and hero\n");
                c.vie.valVie--;
                gameOver=nbVie(gameOver,c.vie,screen);
            }

        }

        else if (enemy.direction==0)
        {
            afficher4 ( &enemy,  screen ,relcoord);

            animate_monster(&enemy);
           SDL_BlitSurface(back,&camera,screen,&pos_back);
		blithero(&c,screen,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

            move_monster2(&enemy);

            colen=collision_bb(camera,&enemy);
            if(colen==1)
            {
                //printf("collision between monster and hero\n");
                c.vie.valVie--;
                gameOver=nbVie(gameOver,c.vie,screen);
            }
        }

        colob=coll_bb(&obstacle,camera);
        if(colob==1)
        {
            //printf("collision between hero and obstacle\n");
            while (s>0)
                s-=10;
        }

        gameOver=nbVie(gameOver,c.vie,screen);

        c.score.posFond.y=-25;


        if (s<=0)
            s=0;
	}
	
        while (SDL_PollEvent(&event))
        {
        afficherScore(screen,&c.score,s);

        switch(event.type)
        {
        case SDL_KEYDOWN :
            if(event.key.keysym.sym==SDLK_ESCAPE)
	    {
                sauvegarder(c,pos_back.x,"save.txt",screen);
		done=0;
	    }
	
            else if(event.key.keysym.sym==SDLK_RIGHT)//deplacement a droite du perso1
            {
                c.directionhero=1;
                choix=1;
                
		if (c.pos_hero.x>=100)			
		{scrolling(&camera, &c.testt);
		//c.pos_hero.x++;
		animation(&c);	}
                gameOver=nbVie(gameOver,c.vie,screen);
                SDL_BlitSurface(back,&camera,screen,&pos_back);
      		 if (c.pos_hero.x<100)
                {deplacerhero(&c);
			}
                blithero(&c,screen,choix);

                if(k<camera.x)
                {
                    s+=50;
                    k=camera.x;
                }
		
                p++;
		if (p==252)
		{
			enigme=main_enigme(&c.vie.valVie);
		}

		if (p==590)
		{
			enigme=main_enigme(&c.vie.valVie);
		}

deplacementminihero(&mini,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);

            }

            else if(event.key.keysym.sym==SDLK_LEFT)//deplacement a gauche du perso1
            {
                c.directionhero=2;
                choix=2;
                p--;
 scrollingb(&camera, &c.testt);
                gameOver=nbVie(gameOver,c.vie,screen);
                SDL_BlitSurface(back,&camera,screen,&pos_back);
                deplacerhero(&c);
                blithero(&c,screen,choix);

deplacementminihero(&mini,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                gameOver=nbVie(gameOver,c.vie,screen);
            }

            else if (event.key.keysym.sym==SDLK_UP)
            {
                jump(&c,screen,pos_back,back,c.directionhero,&s,camera);

                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

                scrolling(&camera, &c.testt);
miniJump(&mini,choix);
blitminimap (&mini,screen,choix);

            }
            break;
        case SDL_KEYUP:
            if(event.key.keysym.sym==SDLK_UP)
            {
                restartjump(&c,screen,pos_back,back,c.directionhero,camera);

miniJump(&mini,choix);
blitminimap (&mini,screen,choix);
                c.score.posFond.y=-25;

                afficherScore(screen,&c.score,s);

            }

  break;
        }
        if (c.vie.valVie==2)
        {
            c.vie.posVie.y=-15;
            c.vie.posVie.x=702;
        }
        if (c.vie.valVie==1)
        {
            c.vie.posVie.y=-20;
            c.vie.posVie.x=698;
        }

        if (keystate[SDLK_RIGHT] && keystate[SDLK_s])//deplacement a droite avec acceleration perso1
        {
            c.directionhero=1;
            choix=1;
            SDL_BlitSurface(back,&camera,screen,&pos_back);
            deplacerhero_avec_acceleration(&c);
            blithero(&c,screen,choix);

deplacementminihero(&mini,choix);
blitminimap (&mini,screen,choix);
            if(k<c.pos_hero.x)
            {
                s++;
                k=c.pos_hero.x;
            }
            c.score.posFond.y=-25;

            afficherScore(screen,&c.score,s);

            gameOver=nbVie(gameOver,c.vie,screen);

        }


        else if (keystate[SDLK_LEFT] && keystate[SDLK_s])//deplacement a gauche avec acceleration perso1
        {
            c.directionhero=2;
            choix=2;
            SDL_BlitSurface(back,&camera,screen,&pos_back);
            deplacerhero_avec_acceleration(&c);
            blithero(&c,screen,choix);

deplacementminihero(&mini,choix);
blitminimap (&mini,screen,choix);
            if(k<c.pos_hero.x)
            {
                s++;
                k=c.pos_hero.x;
            }
            c.score.posFond.y=-25;

            afficherScore(screen,&c.score,s);

            gameOver=nbVie(gameOver,c.vie,screen);

        }

        if (s<=0)
            s=0;
	}
	

    }
    SDL_EnableKeyRepeat(0,0);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(c.spriteright);
    SDL_FreeSurface(c.spriteleft);

    SDL_FreeSurface(back);
    SDL_FreeSurface(c.vie.vie1);
    SDL_FreeSurface(c.vie.vie2);
    SDL_FreeSurface(c.vie.vie3);
    SDL_FreeSurface(c.vie.vie0);

    SDL_FreeSurface(c.score.fondScore);

    SDL_FreeSurface(c.score.texteScore);

    Mix_FreeChunk(effect);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

