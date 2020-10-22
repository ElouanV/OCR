	#OCR Makefile
CC=gcc

CPPFLAGS= `pkg-config --cflags sdl` -MMD
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image


SRC= main.c grayscale.c pixel_operations.c sdltools.c binar.c
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
