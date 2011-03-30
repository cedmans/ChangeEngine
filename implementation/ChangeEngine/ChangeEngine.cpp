/*
 *  @file ChangeEngine.cpp
 *
 *  @date Feb 26, 2011
 *  @author Cedric Wienold
 */

#include "ChangeEngine.h"
#include <stdlib.h>
#include <stdio.h>

// Set singleton to null at start
ChangeEngine* ChangeEngine::pInstance = NULL;

ChangeEngine::ChangeEngine() {

   window = NULL;
}

ChangeEngine::~ChangeEngine() {}

/**
 * Returns the instance of this singleton.
 * @return this class's instance.
 */
ChangeEngine* ChangeEngine::Initiate(void) {

   if (pInstance == NULL) {

      fprintf(stderr,"ChangeEngine Singleton does not exist. Creating...\n");
      pInstance = new ChangeEngine();
   }

   fprintf(stdout,"ChangeEngine Singleton Returned\n");
   return pInstance;
}

void ChangeEngine::Destroy(void) {

   if (window != NULL) {

      window->Destroy();
      window = NULL;
   }

   if (pInstance != NULL) {

      delete pInstance;
      pInstance = NULL;
   }
}

bool ChangeEngine::CreateWindow(int w, int h) {

   width = w;
   height = h;
   xpos = 0;
   ypos = 0;

   window = GameWindow::Initiate(w,h,0,0);

   return true;
}

bool ChangeEngine::CreateWindow(int w, int h, int x, int y) {

   width = w;
   height = h;
   xpos = x;
   ypos = y;

   window = GameWindow::Initiate(w,h,x,y);

   return true;
}
