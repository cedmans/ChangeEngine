/**
 * @file GameWindow.cpp
 *
 * @author Cedric Wienold
 * @date May 3, 2011
 */

#ifdef DEBUG
	#include <stdio.h>
#endif

#include <stdlib.h>

#include "GameWindow.hpp"
#include "errorcodes.hpp"
#include "SDL/SDL.h"

GameWindow* GameWindow::pInstance = NULL;

GameWindow* GameWindow::Initiate(ChangeEngine* engine) {

   int result = EENGINE_SUCCESS;

   if (pInstance == NULL) {

      #ifdef DEBUG
         fprintf(stderr,"Window not found. Creating.\n");
      #endif

      pInstance = new GameWindow();
   }

   result = SDL_Init(SDL_INIT_EVERYTHING);

   if (result != EENGINE_SUCCESS) {

      #ifdef DEBUG
         fprintf(stderr,"SDL Initialization FAILED.\n");
      #endif

      delete pInstance;
      return NULL;
   }

   pInstance->engine = engine;

   return pInstance;
}

void GameWindow::Destroy() {

   if (pInstance != NULL) {

      #ifdef DEBUG
            fprintf(stderr,"GameWindow instance found. Destroying.\n");
      #endif

      if (pInstance->getScreen() != NULL) {

         SDL_FreeSurface(pInstance->getScreen());
      }

      SDL_Quit();
      delete pInstance;
   }
   #ifdef DEBUG
   else {

      fprintf(stderr,"No GameWindow instance found. Not destroying.\n");
   }
   #endif
}

GameWindow::GameWindow() {

   screen = NULL;
}

GameWindow::~GameWindow() {}

int GameWindow::CreateWindow(int x, int y, int width, int height) {

   //~ this->width = width;
   //~ this->height = height;
   //~ this->x = x;
   //~ this->y = y;
//~ 
   //~ //Set up the screen
   //~ //screen = SDL_SetVideoMode(width,height,32,SDL_SWSURFACE);
//~ 
   //~ if (screen == NULL) {
//~ 
      //~ return ESETVIDEOMODE_FAILED;
   //~ }
//~ 
   return EENGINE_SUCCESS;
}

SDL_Surface* GameWindow::getScreen() {

   return screen;
}

