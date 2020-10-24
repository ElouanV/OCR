#include <err.h> 
#include "grayscale.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "sdltools.h"
#include "binar.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Execute fail : not enough arguments\n");
		printf("You have to give the past of the image that you want to binarize in parameters\n");
		printf("For exemple : ./main my_image.jpg\n");
		return 1;
	}

	printf(" Here is the demonstration of pre-processing of our program, between each step\n");
	printf("you have to press any key to display changes made on the image\n");
		// Initialize SDL :
	SDL_Surface* image;
	SDL_Surface* screen_surface = NULL;
	init_sdl();
	image = load_image(argv[1]);
	screen_surface = display_image(image);
	printf("Wait for key pressed\n");
	wait_for_keypressed();
		// Call grayscale function from grayscale.h
	grayscale(image);
	printf("Grayscale done\n");
		// Save a copy of the file after grayscale
	SDL_SaveBMP(image,"grayscaled.bmp");
	update_surface(screen_surface,image);
	//int h = image->h; not used yet
	//int w = image->w; not used yet
	printf("Binarizartion runing . . .\n");
		// Call binar function from binar.h
	binar(image,21,0.5); // int *p =   //not used yet
	printf("Binarization done\n");
	printf("Press a key to display binarization\n");
	wait_for_keypressed();
	update_surface(screen_surface,image);
	printf("Press a key to leave\n");
	wait_for_keypressed();
	printf("Programing ending successfully, copy of each steps have been save in the current directory.\n");
		// Save image after binarization
	SDL_SaveBMP(image,"binarized.bmp");
	SDL_FreeSurface(image);
	SDL_FreeSurface(screen_surface);

	return 0;
}
