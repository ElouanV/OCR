#include <err.h> 
#include "grayscale.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "sdltools.h"
#include "binar.h"
#include <stdlib.h>
#include <stdio.h>
#include "noiseremoving.h"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Execute fail : not enough arguments\n");
		printf("You have to give the past of the image that you want to binarize in parameters\n");
		printf("For exemple : ./main image/my_image.jpg\n");
		return 1;
	}

	printf("Pre-processing is running");
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
	SDL_SaveBMP(image,"result/grayscaled.bmp");
	update_surface(screen_surface,image);
	//noiserimage(image,7); //This function do not word yet, it return a black surface. // FIXME
	int h = image->h; 
	int w = image->w;
	printf("Binarization runing . . .\n");
		// Call binar function from binar.h
	binar(image,14,0.3); // int *p =   //not used yet
	printf("Binarization done\n");
	printf("Press a key to display binarization\n");
	wait_for_keypressed();
	update_surface(screen_surface,image);
	printf("Press a key to leave\n");
	wait_for_keypressed();
	printf("Program ending successfully, copy of each steps have been save in the directory /result.\n");
		// Save image after binarization
	SDL_SaveBMP(image,"result/binarized.bmp");
		// Free surfaces before leaving program
	SDL_FreeSurface(image);
	SDL_FreeSurface(screen_surface);
	printf("Image size : %i x %i \n", h, w);
	return 0;
}
