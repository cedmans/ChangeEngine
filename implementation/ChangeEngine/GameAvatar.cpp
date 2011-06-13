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

   #ifdef DEBUG
   fprintf(stderr,"GameAvatar: Destructing avatar.\n");
   #endif

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
   
   this->tileWidth = tileWidth;
   this->tileHeight = tileHeight;
   
   return EENGINE_SUCCESS;
}

int GameAvatar::addAvatarState(int frameCount) {

   #ifdef DEBUG
   fprintf(stderr,"GameAvatar: Adding state\n");
   #endif
   
   frameSet.push_back(frameCount);
   
   return EENGINE_SUCCESS;
}

int GameAvatar::drawObject(GameWindow* window, int x, int y, int state, int frame) {
   
   SDL_Rect *srcrect = new SDL_Rect();
   SDL_Rect *dstrect = new SDL_Rect();
   
   //Position the crop rect around the frame we want
   srcrect->x = state*tileWidth;
   srcrect->y = frame*tileHeight;
   srcrect->w = tileWidth;
   srcrect->h = tileHeight;
   
   #ifdef DEBUG
   fprintf(stderr,"GameAvatar: Drawing object to (%ix%i),(%i,%i)\n",x,y,state,frame);
   #endif

   //Now we totally want to set the destination rect for the output
   dstrect->x = x;
   dstrect->y = y;
   dstrect->w = tileWidth;
   dstrect->h = tileHeight;
   
   //Blit to the window's surface
   //SDL_BlitSurface(tileSet,&srcrect,window->getScreen(),&dstrect);
   SDL_BlitSurface(tileSet,srcrect,window->getScreen(),dstrect);
   
   delete srcrect;
   delete dstrect;
   
   return EENGINE_SUCCESS;
}

int GameAvatar::addTransparency(int r, int g, int b) {
   
   if (this->tileSet == NULL)
      return EENGINE_FAILURE;
   
   int colorkey = SDL_MapRGB(this->tileSet->format, r, g, b);
   
   SDL_SetColorKey(this->tileSet, SDL_SRCCOLORKEY, colorkey);
   
   return EENGINE_SUCCESS;
}
