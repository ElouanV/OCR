#include <err.h> 
#include "grayscale.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "sdltools.h"

int main ()
{
	SDL_Surface* image;
	SDL_Surface* screen_surface;
	init_sdl();
	image = load_image("my_image.jpg");
	grayscale(image);
	screen_surface = display_image(image);
	wait_for_keypressed();
	SDL_FreeSurface(image);
	SDL_FreeSurface(screen_surface);
}
