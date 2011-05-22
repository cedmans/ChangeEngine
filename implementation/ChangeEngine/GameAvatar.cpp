/**
 * @file GameAvatar.cpp
 *
 * @date May 22, 2011
 * @author Cedric Wienold
 */

#include "GameAvatar.hpp"
#include "SDL/SDL_image.h"

SDL_Surface* GameAvatar::loadImage(const char* filename) {

   // Algorithm source: http://lazyfoo.net/SDL_tutorials/lesson03/linux/cli/index.php
   SDL_Surface* loadedImage = NULL;

   SDL_Surface* optimizedImage = NULL;

   loadedImage = IMG_Load(filename);

   if (loadedImage != NULL) {

      //Create optimized image
      optimizedImage = SDL_DisplayFormat(loadedImage);

      //Free old image
      SDL_FreeSurface(loadedImage);
   }

   return optimizedImage;
}
