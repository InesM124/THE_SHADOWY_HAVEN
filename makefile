game:main.o menu.o main_perso.o main_perso1.o main_perso2.o perso.o main_enigme.o enigme.o save.o monster1.o background.o scrolling.o f.o minimap.o amelioration_menu.o collisionbb.o
	gcc -o game main.o menu.o main_perso.o main_perso1.o main_perso2.o perso.o main_enigme.o enigme.o save.o monster1.o background.o scrolling.o f.o minimap.o amelioration_menu.o collisionbb.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

main.o:main.c 
	gcc -c main.c 

menu.o:menu.c
	gcc -c menu.c

main_perso.o:main_perso.c 
	gcc -c main_perso.c 

main_perso1.o:main_perso1.c 
	gcc -c main_perso1.c 

main_perso2.o:main_perso2.c 
	gcc -c main_perso2.c 

perso.o:perso.c
	gcc -c perso.c

main_enigme.o:main_enigme.c
	gcc -c main_enigme.c

enigme.o:enigme.c
	gcc -c enigme.c

save.o:save.c
	gcc -c save.c

monster1.o:monster1.c
	gcc -c monster1.c

background.o:background.c
	gcc -c background.c

scrolling.o:scrolling.c
	gcc -c scrolling.c

f.o:f.c
	gcc -c f.c

minimap.o:minimap.c
	gcc -c minimap.c

amelioration_menu.o:amelioration_menu.c
	gcc -c amelioration_menu.c

collisionbb.o:collisionbb.c
	gcc -c collisionbb.c


