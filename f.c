#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "f.h"
#include "perso.h"
void clip1 (E_S * enemy)
{  int i;
for(i=0;i<3;i++) 
               {
                 enemy->m[ i ].x = 100 * i;
                enemy->m[ i ].y = 0;
                enemy->m[ i ].w = 100;
                enemy->m[ i ].h = 100;
                }
    
 }  
  


void clip2 (E_S * enemy)
{  int i;

     for(i=0;i<3;i++) 
      {
        enemy->m[ i ].x = 100 * i;
        enemy->m[ i ].y = 100;
        enemy->m[ i ].w = 100;
        enemy->m[ i ].h = 100;
      }
}



void initializem(E_S * enemy)
   {

       enemy->sprite_monster = IMG_Load("ennemi_spr.png");

     
       enemy->monster.x = 10000;
       enemy->monster.y = 300;
       enemy->frame=0;
       enemy->etat=waiting;
       enemy->direction=0;
       

   }

 void aff1 ( E_S * enemy, SDL_Surface* screen ,SDL_Rect relcoord)
{ 
   clip1 (enemy);
   SDL_BlitSurface(enemy->sprite_monster, &(enemy->m[enemy->frame]), screen, &relcoord);
   SDL_Flip(screen);
}
void aff2 ( E_S * enemy, SDL_Surface* screen, SDL_Rect relcoord )
{  
   clip2 (enemy);
   SDL_BlitSurface(enemy->sprite_monster, &(enemy->m[enemy->frame]), screen, &relcoord);
   SDL_Flip(screen);
  
}

void animate_monsterB(E_S * enemy)
{

if (enemy->frame <= 3)
{
   
enemy->frame += 1;


}


if (enemy->frame >=3)
{
enemy->frame = 0;


}

//SDL_Delay(40);


}  

void move_monsterB(E_S * enemy)
{  
     enemy->monster.x-=5;
       
 }   

void move_monster2B(E_S * enemy)
{          
enemy->monster.x+=5;
}

 void updateEnemy (E_S *enemy, SDL_Rect* camera) 
{ int d, s1=500, s2=30;
    //c->pos_hero.x;
            
  switch (enemy->etat)
   {
      case waiting:
       
d=((enemy->monster.x)-(camera->x));
 if (d<=0)
        enemy->etat=waiting;

         
       if ((s2<d)&&(d<=s1))
        enemy->etat=following;
         
        
      break;
      case following:
        d=((enemy->monster.x)-(camera->x+130));
       if ((s2<d)&&(d<=s1))
        enemy->etat=following;
        if ((0<d)&&(d<=s2))
        enemy->etat=attacking;
        
      break;
      case attacking:
       d=((enemy->monster.x)-(camera->x+130));
        if ((0<d)&&(d<=s2))
        enemy->etat=attacking;
        if (d<=0)
        enemy->etat=waiting;
      
      break;

   }

}
/*void AI_monster(E_S *enemy, hero*c )
{ SDL_Surface* screen;
SDL_Surface *background;
SDL_Rect pos_back;
int i;

   switch (enemy->etat)
   {
      case waiting:
        
       // l'ennemi s'anime mais reste à la même position 
       afficher2 ( enemy,  screen );
       animate_monster(enemy);
        
      break;
      case following:
        
        afficher2 ( enemy,  screen );
         animate_monster(enemy);
         //SDL_BlitSurface(background,NULL,screen,&pos_back);
         move_monster(enemy);
      break;
      case attacking:
         for(i=0;i<3;i++) 
      {
        enemy->m[ i ].x = 100 * i;
        enemy->m[ i ].y = 300;
        enemy->m[ i ].w = 100;
        enemy->m[ i ].h = 100;
      }
    
   
   SDL_BlitSurface(enemy->sprite_monster, &(enemy->m[enemy->frame]), screen, &enemy->monster);
   SDL_Flip(screen);
  



         animate_monster(enemy);
         //SDL_BlitSurface(background,NULL,screen,&pos_back);
         move_monster(enemy);

      break;

   }

    //updateEnemy (enemy, posHero ) ;
 if (enemy->etat==waiting)
 printf("1");
}*/

