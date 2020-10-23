#include <err.h> 
#include "grayscale.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "sdltools.h"
#include "binar.h"
#include <stdlib.h>
#include <stdio.h>

int main ()
{
	SDL_Surface* image;
	SDL_Surface* screen_surface = NULL;
	init_sdl();
	image = load_image("my_image.jpg");
	screen_surface = display_image(image);
	printf("Wait for key pressed\n");
	wait_for_keypressed();
	grayscale(image);
	update_surface(screen_surface,image);
	printf("Wait for key pressed\n");
	wait_for_keypressed();
	int h = image->h;
	int w = image->w;
	int mat[w][h];
	printf("Binarizartion en cours\n");
	binar(image,1,1);
	printf("Binarization terminée\n");
	printf("mat 0 0 %i\n",mat[0][0]);
	update_surface(screen_surface,image);
	//screen_surface = display_image(image);
	printf("Wait for key pressed\n");
	wait_for_keypressed();
	SDL_FreeSurface(image);
	SDL_FreeSurface(screen_surface);
}
