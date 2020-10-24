#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"
#include "sdltools.h"
#include "binar.h"
#include <stdlib.h>
#include <math.h>

float pixelmean(int i, int j, int r, SDL_Surface* image)	
{
	// * Compute the mean of the pixel in a given size window
	// -- Param --
	//  - int i and int j : position of the pixel
	//  - int r : size of the window
	//  - SDL_Surface* image : image 
	float sum = 0;
	int w = image->w;
	int h = image->h;
	long size = w*h;
	Uint8 ng, g, b;	
	Uint32 pixel;
	for (int x = i - r/2; x  < i + r/2; x++)
	{
		if ((x<0)|| (x > w))
		{
			continue;
		}
		for (int y = j - r/2; y < j + r/2; y++)
		{

			if ((y < 0)||((long)(x*h+y) >= size))
			{
				continue;
			}
			else
			{
				pixel = get_pixel(image, x, y);
				SDL_GetRGB(pixel, image->format, &ng, &g, &b);
				sum += (float)ng;
			}
			
		}
	}
	float m = sum/(float)(r*r);
	return m;
}

void matrixmean(float *mean, int h, int w, int r, SDL_Surface* image)
{
	// * Build the matrix of all value of mean of pixel of the image
	// * Will be used to compute local standard deviation (s) of each pixels
	// * Take in parameter a matrix to complete, h and w which are the number of columns and
        //   raws of the matrix, r is the size of the centered windows, and *mat is the 
	//   matrix to compute.
	for(int i = 0; i<w; i++)
	{
		for(int j = 0; j<h; j++)
		{
			mean[i*h+j] = pixelmean(i, j, r, image);
		}
	}

}

float stddev(int i, int j, int r, float *mean, SDL_Surface* image)
{
	int w = image->w;
	int h = image->h;
	long size = w*h;
	float sum = 0;
	Uint8 ng, g, b;
	Uint32 pixel;
	pixel = get_pixel(image, i, j);
	SDL_GetRGB(pixel, image->format, &ng, &g, &b);
	float m;
	float sl;
	for(int x = i-r/2; x < i+ r/2; x ++)
	{
		if ((x<0)||(x>w))
		{
			continue;
		}
		for(int y = j -r/2; y < j +r/2; y++)
		{
			if ((y<0)||(long)(x*h+y) >= size)
			{
				continue;
			}
			else
			{
				m = mean[x*h+y];
				sl = (float)ng - m;
				sum += sl*sl;
			}
		}
	}
	float ssquare = sum /(r*r);
	float s = sqrt(ssquare);
	return s;
}

int *binar(SDL_Surface* image, int r, float k)
{

	int w = image->w;
	int h = image->h;
	float m;
	float s;
	float t;
	int * mat;
	mat = (int *) malloc((h*w)*sizeof(int));
	float *mean;
	mean = (float *) malloc((h*w)*sizeof(float));
	if ((mean == NULL)||(mat == NULL))
	{
		printf("[binar] : allocation failed");
		exit(EXIT_FAILURE);
	}
	matrixmean(mean, h, w, r, image);
	Uint32 pixel;
	Uint8 ng, g, b;
	ng = 3;
	for(int i = 0; i < w; i++)
	{
		for(int j = 0; j < h ; j++)
		{
			m = mean[i*h+j];
			s = stddev(i,j,r, mean, image);
			//TODO
			t = m*(1-k*(1-s/128));
			pixel = get_pixel(image, i, j);
			SDL_GetRGB(pixel, image-> format, &ng, &g, &b);
			if (ng > t)
			{
				//printf("0");	
				mat[i*h + j] = 0;
				//To show binarisation on the image :
				Uint32 newpixel = SDL_MapRGB(image->format, 255, 255, 255);
				put_pixel(image, i, j, newpixel);
			}
			else
			{
				//printf("1");
				mat[i*h+j] = 1;
				// To show binarization on the image : 
				Uint32 newpixel = SDL_MapRGB(image->format, 0, 0, 0);
				put_pixel(image, i, j, newpixel);
			}
		}
	}
	return mat;

}







