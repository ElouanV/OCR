#ifndef BINAR_H
#define BINAR_H

#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"
#include "sdltools.h"

float mean(int i, int j, int r, int * mat, int h);
float eacrtype(int i, int j, int r);
int *binar(SDL_Surface* image, int r, float k);


#endif
