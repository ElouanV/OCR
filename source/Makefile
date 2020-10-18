	#Commande du compilateur
CPP=gcc
	#Option d'optimisation du programme
CFLAGS=-O3
	#Linker
LDFLAGS=-lSDL -lSDL_mixer
	#Nom du programme
EXEC=OCR




	#Define the default target
all:	${EXEC}
	#Define dependencies and compilation information
OCR:	main.o
	gcc main.o
main.o:	main.c
	gcc -c main.c



clean : 
	rm -fr *.o
mrproper: clean
	rm -fr ${EXEC}