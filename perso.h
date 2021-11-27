#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

typedef struct
{
    SDL_Surface* vie3;
    SDL_Surface* vie2;
    SDL_Surface* vie1;
    SDL_Surface* vie0;
    SDL_Rect posVie;
    int valVie;
} Vie;

typedef struct
{
    SDL_Surface *fondScore;
    SDL_Rect posFond;
    SDL_Surface *texteScore;
    TTF_Font *police;
    SDL_Rect posScore;
    int scoreActuel;
} Score;


typedef struct
{
    SDL_Surface *spriteright;
    SDL_Surface *spriteleft;
    SDL_Rect pos_hero,testt;
    SDL_Rect rectright[3],rectleft[3];
    int frame,directionhero,ground;
    Vie vie;
    Score score;
} hero;

int main_perso(SDL_Surface *screen,hero c, hero d);
int main_perso1(SDL_Surface *screen,hero c);
int main_perso2(SDL_Surface *screen,hero c);
void init(hero* hero);
void setright(hero* hero);
void setleft(hero* hero);
void animation(hero *hero);
void deplacerhero(hero *hero);
void deplacerhero_avec_acceleration(hero *hero);
void blithero(hero *hero, SDL_Surface *screen, int choix);


int nbVie(int gameOver,Vie vie, SDL_Surface *screen);

void afficherScore(SDL_Surface *ecran, Score *score,int s );

void jump(hero *hero,SDL_Surface *screen,SDL_Rect pos_back,SDL_Surface *back,int choix,int *s,SDL_Rect camera);

void restartjump(hero *hero,SDL_Surface *screen,SDL_Rect pos_back,SDL_Surface *back,int choix,SDL_Rect camera);

void init2(hero *hero);

#endif
