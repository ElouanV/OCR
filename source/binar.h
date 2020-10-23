#ifndef BINAR_H
#define BINAR_H

#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"
#include "sdltools.h"

float mean(int i, int j, int r);
float eacrtype(int i, int j, int r);
void binar(SDL_Surface* image, int r, float k);


#endif
