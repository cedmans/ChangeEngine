/**
 * @file GameWindow.cpp
 * 
 * @author Cedric Wienold
 * @date May 3, 2011
 */

#ifdef DEBUG
	#include <stdio.h>
#endif

#include "GameWindow.hpp"
#include <stdlib.h>

GameWindow* GameWindow::pInstance = NULL;

GameWindow* GameWindow::Initiate(ChangeEngine* engine, int w, int h, int x, int y) {
      
   if (pInstance == NULL) {
      
      #ifdef DEBUG
         fprintf(stderr,"Window not found. Creating.\n");
      #endif
      
      pInstance = new GameWindow();
   }
   
   pInstance->width = w;
   pInstance->height = h;
   pInstance->x = x;
   pInstance->y = y;
   
   return pInstance;
}

void GameWindow::Destroy() {

   if (pInstance != NULL) {
      
      #ifdef DEBUG
            fprintf(stderr,"GameWindow instance found. Destroying.\n");
      #endif

      delete pInstance;
      pInstance = NULL;
   }
   else {
      
      #ifdef DEBUG
            fprintf(stderr,"No GameWindow instance found. Not destroying.\n");
      #endif
   }
}

GameWindow::GameWindow() {}

GameWindow::~GameWindow() {
   
   if (this->pInstance != NULL) {
      
      delete pInstance;
   }
}

