#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"

typedef enum state state ;
enum state { waiting, following, attacking};
typedef struct E_S
   {  
      SDL_Surface *sprite_monster;
      SDL_Rect  monster;
      SDL_Rect m[ 3 ];
      
      int frame;
      int direction;
      state etat;
       

   } E_S;

typedef struct collisionbb1 
{ int x;
  int y;
  int w;
  int h;
}collisionbb1;

 
void clip1 (E_S * enemy);
void clip2 (E_S * enemy);
void initializem(E_S * enemy);
void aff1 ( E_S * enemy, SDL_Surface* screen,SDL_Rect relcoord );
void aff2 ( E_S * enemy, SDL_Surface* screen ,SDL_Rect relcoord);
void animate_monsterB(E_S * enemy);
void move_monsterB(E_S * enemy);
void move_monster2B(E_S * enemy);
void updateEnemy (E_S *enemy, SDL_Rect* camera ) ;

int coll_bb(collisionbb1* obstacle ,SDL_Rect camera );
int coll_bb1(collisionbb1* obstacle ,SDL_Rect camera );
int coll_bb2(collisionbb1* obstacle ,SDL_Rect camera );
int coll_bb3(collisionbb1* obstacle ,SDL_Rect camera );
int coll_bb4(collisionbb1* obstacle ,SDL_Rect camera );

//void AI_monster(second_entity *enemy, hero *c );


