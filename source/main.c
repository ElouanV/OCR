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
	SDL_SaveBMP(image,"grayscaled.bmp");
	update_surface(screen_surface,image);
	printf("Wait for key pressed\n");
	wait_for_keypressed();
	//int h = image->h; not used yet
	//int w = image->w; not used yet
	printf("Binarizartion en cours\n");
	 binar(image,60,0.38); // int *p =   //not used yet
	printf("Binarization terminée\n");
	//printf("mat 0 0 %i\n");
	update_surface(screen_surface,image);
	//screen_surface = display_image(image);
	printf("Wait for key pressed\n");
	wait_for_keypressed();
	SDL_SaveBMP(image,"binarized.bmp");
	SDL_FreeSurface(image);
	SDL_FreeSurface(screen_surface);
}
