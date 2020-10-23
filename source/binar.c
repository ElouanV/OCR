#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"
#include "sdltools.h"
#include "binar.h"
#include <stdlib.h>

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
	Uint8 ng, g, b;
	ng = 3;
	for(size_t i = 0; i < w; i++)
	{
		for(size_t j = 0; j < h ; j++)
		{
			m = 1 ;//mean(i, j, r); // TODO
			s = 1 ;//ecartype(i,j,r);
		       	      //TODO
			t = 125;//m*(1-k*(1-s/r));
			pixel = get_pixel(image, i, j);
			SDL_GetRGB(pixel, image-> format, &ng, &g, &b);
			if (ng > t)
			{
				
				//mat[i*h + j] = 1;
				//To show binarisation on the image :
				Uint32 newpixel = SDL_MapRGB(image->format, 255, 255, 255);
				put_pixel(image, i, j, newpixel);
			}
			else
			{
			
				//mat[i*h + j] = 0;
				// To show binarization on the image : 
				Uint32 newpixel = SDL_MapRGB(image->format, 0, 0, 0);
				put_pixel(image, i, j, newpixel);
			}
		}
	}
}







