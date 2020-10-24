#include <err.h>
#include "SDL/SDL.h"
#include "pixel_operations.h"
#include "SDL/SDL_image.h"
#include "sdltools.h"
#include <stdio.h>


void array_swap(int *array, size_t i, size_t j)
{
	int inter = array[i];
	array[i] = array[j];
	array[j] = inter;
}



void sortarray(int *array, size_t size)
{
	for (size_t i = 0; i < size-1; i ++)
	{
		size_t min_index = i;
		for (size_t j = i+1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		array_swap(array, i, min_index);
	}
}

int median(SDL_Surface* image, int i, int j, int r)
{
	int size = r*r;
	int *valtab = (int *) calloc (size,sizeof(int));
	int h = image->h;
	int w = image->w;
	int counter = 0;
	Uint8 ng, g, b;
	Uint32 pixel;
	for(int x = i - r/2; x < i+r/2; x ++)
	{
		if ((x<0)||(x>w))
		{
			size -=1;
			continue;
		}
		for(int y = j -r/2; y < j+r/2; y++)
		{
			if ((y<0)||(y > h))
			{
				size -=1;
				continue;
			}
			pixel = get_pixel(image, x, y);
			SDL_GetRGB(pixel, image->format, &ng, &g, &b);
			valtab[counter] = ng;
		}
	}
	sortarray(valtab, size);
	int median = valtab[size/2];
	free(valtab);
	return median;
}

void noiserimage(SDL_Surface* image, int r)
{
	int w = image->w;
	int h = image->h;
	int med;
	for (int i = 0; i<w; i++)
	{
		for (int j = 0; j <h ; j++)
		{
			med = median(image, i, j, r);
			printf("[NOICEREMOVING] : pixel %i, %i median : %i \n", i, j, med);
			Uint32 newpixel = SDL_MapRGB(image->format, med, med, med);
			put_pixel(image, i, j, newpixel);
		}
	}
}



