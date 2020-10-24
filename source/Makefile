	#OCR Makefile
CC=gcc

CPPFLAGS= `pkg-config --cflags sdl` -MMD
CFLAGS= -Wall -Wextra -std=c99 -O3 -g -Werror 
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image -lm


SRC= main.c grayscale.c pixel_operations.c sdltools.c binar.c noiseremoving.c #skrewcorrection.h
OBJ=${SRC:.c=.o}
DEP=${SRC:.c=.d}

all: main

main:${OBJ}



clean:
	${RM} ${OBJ} #remove object files
	${RM} ${DEP} #remove depedency files
	${RM} main   #remove main program




-include ${DEP}
#END
