/**
 * @file GameAvatar.cpp
 *
 * @date May 22, 2011
 * @author Cedric Wienold
 */

#include "GameAvatar.hpp"
#include "SDL/SDL_image.h"
#include "errorcodes.hpp"
#include "debug.hpp"

GameAvatar::~GameAvatar() {

   if (tileSet != NULL) {
      
      SDL_FreeSurface(tileSet);
   }
}

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

int GameAvatar::attachImage(std::string filename, int tileWidth, int tileHeight) {

   #ifdef DEBUG
   fprintf(stderr,"GameAvatar: Attaching image %s\n",filename.c_str());
   #endif
   
   tileSet = GameAvatar::loadImage(filename.c_str());
   
   if (tileSet == NULL) {
      
      return EATTACHIMAGE_FAILED;
   }
   
   tileWidth = tileWidth;
   tileHeight = tileHeight;
   
   return EENGINE_SUCCESS;
}

int GameAvatar::addAvatarState(int frameCount) {

   #ifdef DEBUG
   fprintf(stderr,"GameAvatar: Adding state\n");
   #endif
   
   frameSet.push_back(frameCount);
   
   return EENGINE_SUCCESS;
}
