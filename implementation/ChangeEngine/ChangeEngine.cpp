/**
 *  @file ChangeEngine.cpp
 *
 *  @date Feb 26, 2011
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

   window = GameWindow::Initiate(pInstance);
//~ 
   //~ int result = window->CreateWindow(0,0,w,h);
//~ 
   //~ if (window == NULL) {
//~ 
      //~ return EINITIATE_FAILED;
   //~ }
//~ 
   //~ if (result != EENGINE_SUCCESS) {
//~ 
      //~ return EWINDOW_FAILED;
   //~ }

   return EENGINE_SUCCESS;
}

int ChangeEngine::CreateWindow(int x, int y, int w, int h) {

   //~ window = GameWindow::Initiate(pInstance);
//~ 
   //~ if (window == NULL) {
//~ 
      //~ return EINITIATE_FAILED;
   //~ }
//~ 
   //~ int result = window->CreateWindow(x,y,w,h);
//~ 
   //~ if (result != EENGINE_SUCCESS) {
//~ 
      //~ return EWINDOW_FAILED;
   //~ }
//~ 
   return EENGINE_SUCCESS;
}

GameWindow* ChangeEngine::getWindow() {

   return window;
}
