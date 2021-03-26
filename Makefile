prog:fonctions.o main.o
	gcc ennemy.o ennemy.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf  -g
main.o:main.c
	gcc -c main.c -g
fonctions.o:ennemy.c
	gcc -c ennemy.c -g
clean: 
	rm -fr prog
	rm -fr ennemy.o
	rm -fr main.o
execute:
	./prog
