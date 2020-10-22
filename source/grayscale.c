#include "grayscale.h"
#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"
#include "sdltools.h"

void grayscale(SDL_Surface *image)
{
	Uint8 r, g, b;
	for(int i = 0; i < image->w; i++)
	{
		for(int j = 0; j < image->h; j++)
		{
			Uint32 pixel = get_pixel(image, i, j);
			SDL_GetRGB(pixel, image->format, &r, &g, &b);
			Uint8 average = 0.3*r + 0.59*g + 0.11*b;
			Uint32 newpixel = SDL_MapRGB(image->format, average, average, average);
			put_pixel(image, i, j, newpixel);
		}
	}
}






























