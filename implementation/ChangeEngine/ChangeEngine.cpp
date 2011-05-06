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
#include <stdio.h>

// Set singleton to null at start
ChangeEngine* ChangeEngine::pInstance = NULL;

ChangeEngine::ChangeEngine() {

   window = NULL;
}

ChangeEngine::~ChangeEngine() {
	
	if (window != NULL) {
		
		delete window;
	}
}

ChangeEngine* ChangeEngine::Initiate(void) {

   if (pInstance == NULL) {

      #ifdef DEBUG
         fprintf(stderr,"ChangeEngine Singleton does not exist. Creating.\n");
      #endif
      pInstance = new ChangeEngine();
   }
   
   #ifdef DEBUG
      fprintf(stdout,"ChangeEngine Singleton Returned\n");
   #endif

   return pInstance;
}

void ChangeEngine::Destroy(void) {

   // Destroy the window if it's there
   if (window != NULL) {
      
      #ifdef DEBUG
         fprintf(stderr,"Window found. Destroying.\n");
      #endif

      window->Destroy();
   }
   else {
      
      #ifdef DEBUG
         fprintf(stderr,"No window found. Not destroying.\n");
      #endif
   }

   // Make sure the instance of ChangeEngine shall be destroyed.
   if (pInstance != NULL) {
      
      #ifdef DEBUG
            fprintf(stderr,"ChangeEngine instance found. Destroying.\n");
      #endif

      delete pInstance;
      
      if (pInstance != NULL)
			fprintf(stderr,"engine instance NOT NULL\n");
		else
			fprintf(stderr,"engine IS REALLY NULL\N");
      pInstance = NULL;
   }
   else {
      
      #ifdef DEBUG
            fprintf(stderr,"No ChangeEngine instance found. Not destroying.\n");
      #endif
   }
}

bool ChangeEngine::CreateWindow(int w, int h) {

   window = GameWindow::Initiate(pInstance,w,h,0,0);

   return true;
}

bool ChangeEngine::CreateWindow(int w, int h, int x, int y) {

   window = GameWindow::Initiate(pInstance,w,h,x,y);

   return true;
}
