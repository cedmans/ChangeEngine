/**
 * @file GameWindow.cpp
 *
 * @author Cedric Wienold
 * @date May 12, 2011
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

   #ifdef DEBUG
   fprintf(stderr,"GameWindow: Initiate\n");
   #endif

   int result = EENGINE_SUCCESS;

   if (pInstance == NULL) {

      #ifdef DEBUG
         fprintf(stderr,"GameWindow: Window not found. Creating.\n");
      #endif

      pInstance = new GameWindow();
   }

   result = SDL_Init(SDL_INIT_EVERYTHING);

   if (result != EENGINE_SUCCESS) {

      #ifdef DEBUG
         fprintf(stderr,"GameWindow: SDL Initialization FAILED.\n");
      #endif

      delete pInstance;
      return NULL;
   }

   pInstance->engine = engine;

   return pInstance;
}

void GameWindow::Destroy() {

   #ifdef DEBUG
   fprintf(stderr,"GameWindow: Destroy\n");
   #endif

   if (pInstance != NULL) {

      #ifdef DEBUG
            fprintf(stderr,"GameWindow: GameWindow instance found. Destroying.\n");
      #endif

      //Check if I made my screen
      if (pInstance->getScreen() != NULL) {

         SDL_FreeSurface(pInstance->getScreen());
      }

      SDL_Quit();
      delete pInstance;
   }
   #ifdef DEBUG
   else {

      fprintf(stderr,"GameWindow: No GameWindow instance found. Not destroying.\n");
   }
   #endif
}

GameWindow::GameWindow() {

   screen = NULL;
}

GameWindow::~GameWindow() {}

int GameWindow::CreateWindow(int x, int y, int width, int height, int bpp) {

   #ifdef DEBUG
   fprintf(stderr,"GameWindow: CreateWindow\n");
   #endif
   
   this->width = width;
   this->height = height;
   this->x = x;
   this->y = y;

   //Set up the screen
   screen = SDL_SetVideoMode(width,height,bpp,SDL_SWSURFACE);

   if (screen == NULL) {

      #ifdef DEBUG
      fprintf(stderr,"GameWindow: ESETVIDEOMODE_FAILED\n");
      #endif
      
      return ESETVIDEOMODE_FAILED;
   }

   return EENGINE_SUCCESS;
}

SDL_Surface* GameWindow::getScreen() {

   return screen;
}

