/*
 *  @file GameWindow.cpp
 *
 *  @date Feb 26, 2011
 *  @author Cedric Wienold
 */

#include <stdio.h>
#include <stdlib.h>
#include "GameWindow.h"

GameWindow* GameWindow::pInstance = NULL;

GameWindow::GameWindow(int w, int h, int x, int y) :
   width(w), height(h), xpos(x), ypos(y) {}

GameWindow::~GameWindow() {

   if (this->pInstance == NULL) {
      free(pInstance);
   }
}

GameWindow* GameWindow::Initiate(int w, int h, int x, int y) {

   if (pInstance == NULL) {

      fprintf(stdout,"GameWindow does not exist. Creating...\n");
      pInstance = new GameWindow(w,h,x,y);
   }
   else {

      fprintf(stdout,"WARNING: GameWindow already exists. Doing nothing.\n");
   }

   fprintf(stdout,"GameWindow instance returning.\n");
   return pInstance;
}

void GameWindow::Destroy() {

   if (pInstance != NULL) {

      delete pInstance;
      pInstance = NULL;
   }
}
