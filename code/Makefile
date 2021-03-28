prog:ennemy.o main.o
	gcc ennemy.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf  -g
main.o:main.c
	gcc -c main.c -g
ennemy.o:ennemy.c
	gcc -c ennemy.c -g
clean: 
	rm -fr prog
	rm -fr ennemy.o
	rm -fr main.o
execute:
	./prog
