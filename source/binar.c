#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"
#include "sdltools.h"
#include "binar.h"

float mean(int i, int j, int r);
//TODO

float ecartype(int i, int j, int r);
//TODO

void binar(SDL_Surface* image, int r, float k)
{
	int w = image->w;
	int h = image->h;
	float m;
	float s;
	float t;
	Uint32 pixel;
	Uint8 ng;
	for(i = 0; i < w; i++)
	{
		for(j = 0; j< 0 ; j++)
		{
			m = mean(i, j, r); // TODO
			// s = ecartype(i,j,r); TODO
			t = m*(1-k*(1-s/r);
			pixel = get_pixel(image, i, j);
			SDL_GetRGB(pixel, image-> format, &ng);
			if (ng > t)
			{
				Uint32 newpixel = SDL_MapRGB(image-> format, 1, 1, 1);
				put_pixel(image, i, j, newpixel);
			}

		}
	}
}
