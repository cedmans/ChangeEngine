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
#include "errorcodes.hpp"
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

   if (pInstance == NULL) {

      #ifdef DEBUG
         fprintf(stderr,"ChangeEngine: ChangeEngine Singleton does not exist. Creating.\n");
      #endif
      pInstance = new ChangeEngine();
   }

   #ifdef DEBUG
      fprintf(stdout,"ChangeEngine: ChangeEngine Singleton Returned\n");
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

int ChangeEngine::CreateWindow(int w, int h) {
   
   return this->CreateWindow(0,0,w,h);
}

int ChangeEngine::CreateWindow(int x, int y, int w, int h) {

   #ifdef DEBUG
   fprintf(stderr,"ChangeEngine: CreateWindow\n");
   #endif
   
   window = GameWindow::Initiate(pInstance);

   int result = window->CreateWindow(x,y,w,h);

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
