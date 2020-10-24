#ifndef BINAR_H
#define BINAR_H

#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"
#include "sdltools.h"

float pixelmean(int i, int j, int r, SDL_Surface* image);
void matrixmean(float *mean, int h, int w, int r, SDL_Surface* image);
float stddev(int i, int j, int r, float *mean, SDL_Surface *image);
int *binar(SDL_Surface* image, int r, float k);


#endif
