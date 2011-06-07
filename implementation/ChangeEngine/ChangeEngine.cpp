/**
 *  @file ChangeEngine.cpp
 *
 *  @date May 12, 2011
 *  @author Cedric Wienold
 */

#ifdef DEBUG
    #include <stdlib.h>
#endif

#include "ChangeEngine.hpp"
#include <stdio.h>

// Set singleton to null at start
ChangeEngine* ChangeEngine::pInstance = NULL;

ChangeEngine::ChangeEngine() {

   window = NULL;
}

ChangeEngine* ChangeEngine::Initiate(void) {

   #ifdef DEBUG
   fprintf(stderr,"ChangeEngine: Initiate\n");
   #endif

   //Initiate ChangeEngine if it doesn't already exist
   if (pInstance == NULL) {

      #ifdef DEBUG
         fprintf(stderr,"ChangeEngine: ChangeEngine Singleton does not exist. Creating.\n");
      #endif
      pInstance = new ChangeEngine();
   }

   //Create event listener
   if (pInstance->listener == NULL) {

      pInstance->listener = new EventListener();
   }


   #ifdef DEBUG
      fprintf(stderr,"ChangeEngine: ChangeEngine Singleton Returned\n");
   #endif

   return pInstance;
}

void ChangeEngine::Destroy(void) {

   #ifdef DEBUG
   fprintf(stderr,"ChangeEngine: Destroy\n");
   #endif

   // Clean up engine objects
   
   //If this engine is initialized
   if (pInstance != NULL) {
      
      //Destroy any levels in the array
      for(std::map<std::string,GameLevel*>::iterator it=pInstance->levels.begin(); it!=pInstance->levels.end(); it++) {
         
         GameLevel::Destroy((*it).second);
      }
      
      //See if the GameWindow has been initialized
      if (pInstance->window != NULL) {
         
         #ifdef DEBUG
         fprintf(stderr,"ChangeEngine: Window has been initialized. Destroying.\n");
         #endif
         
         GameWindow::Destroy();
      }
      #ifdef DEBUG
      else {
         
         fprintf(stderr,"ChangeEngine: Window not created yet. Not destroying.\n");
      }
      #endif

      //Destroy the game engine instance
      delete pInstance;
   }
}

int ChangeEngine::createWindow(int w, int h, int bpp) {
   
   return this->createWindow(0,0,w,h,bpp);
}

int ChangeEngine::createWindow(int x, int y, int w, int h, int bpp) {

   #ifdef DEBUG
   fprintf(stderr,"ChangeEngine: CreateWindow\n");
   #endif
   
   //Create game window
   window = GameWindow::Initiate(pInstance);

   int result = window->CreateWindow(x,y,w,h,bpp);

   if (window == NULL) {

      #ifdef DEBUG
      fprintf(stderr,"ChangeEngine: EINITIATE_FAILED\n");
      #endif
      
      return EINITIATE_FAILED;
   }

   if (result != EENGINE_SUCCESS) {

         #ifdef DEBUG
         fprintf(stderr,"ChangeEngine: EWINDOW_FAILED\n");
         #endif
   
         return EWINDOW_FAILED;
   }

   return EENGINE_SUCCESS;
}

GameWindow* ChangeEngine::getWindow() {

   return window;
}

EventListener* ChangeEngine::getEventListener() {

   return listener;
}

void ChangeEngine::setWindowCaption(const char* caption) {

   SDL_WM_SetCaption(caption,NULL);
}


int ChangeEngine::createLevel(const char* levelName) {
   
   //Make sure the level name doesn't already exist
   if(levels.find(levelName) == levels.end()) {
      
      levels[levelName] = new GameLevel();
   }
   
   return EENGINE_SUCCESS;
}
