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
         
         #ifdef DEBUG
         fprintf(stderr,"GameEngine: Destroying level %s.\n",(*it).first.c_str());
         #endif

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
   
   #ifdef DEBUG
   fprintf(stderr,"GameEngine: Creating level %s.\n",levelName);
   #endif
   
   //Make sure the level name doesn't already exist
   if(levels.find(levelName) == levels.end()) {
      
      #ifdef DEBUG
      fprintf(stderr,"GameEngine: Level %s is unique, creating.\n",levelName);
      #endif
      
      levels[levelName] = new GameLevel();
   }
   #ifdef DEBUG
   else {
      
      fprintf(stderr,"GameEngine: Level %s already exists. This ain't right.",levelName);
      return ELEVELCREATE_ALREADY_EXISTS;
   }
   #endif
   
   return EENGINE_SUCCESS;
}

int ChangeEngine::createGameObject(const char* levelName, const char* objectName) {
   
   #ifdef DEBUG
   fprintf(stderr,"GameEngine: Creating Object (%s:%s)\n",levelName,objectName);
   #endif
   
   //If the level doesn't exist, this is bad
   if(levels.find(levelName) == levels.end()) {
      
      #ifdef DEBUG
      fprintf(stderr,"GameEngine: Uh oh, level %s DOESN'T EXIST\n",levelName);
      #endif
      
      return EOBJECTCREATE_INVALID_LEVEL;
   }
            
   //Make object in level
   if ((levels[levelName]->createGameObject(objectName)) != EENGINE_SUCCESS) {
      
      return EOBJECTCREATE_CREATE_FAILED;
   }
   
   return EENGINE_SUCCESS;
}

int ChangeEngine::attachImageToGameObject(std::string level, std::string object, std::string filename, int tileWidth, int tileHeight) {

   #ifdef DEBUG
   fprintf(stderr,"GameEngine: Attaching image \"%s\" to object (%s:%s)\n",filename.c_str(),level.c_str(),object.c_str());
   #endif
   
   //Check if level exists
   if (levels.find(level) == levels.end())
   {
      #ifdef DEBUG
      fprintf(stderr,"GameEngine: Uh oh, level %s DOESN'T EXIST\n",level.c_str());
      #endif
      
      return EATTACHIMAGE_INVALID_LEVEL;
   }
   
   if ((levels[level]->attachImage(object,filename,tileWidth,tileHeight)) != EENGINE_SUCCESS) {
      
      return EATTACHIMAGE_FAILED;
   }

   return EENGINE_SUCCESS;
}
int ChangeEngine::addAvatarState(std::string level, std::string object, int frameCount) {
   
   #ifdef DEBUG
   fprintf(stderr,"GameEngine: Adding state\n");
   #endif
   
   //Check if level exists
   if (levels.find(level) == levels.end())
   {
      #ifdef DEBUG
      fprintf(stderr,"GameEngine: Uh oh, level %s DOESN'T EXIST\n",level.c_str());
      #endif
      
      return EADDSTATE_INVALID_LEVEL;
   }
   
   if ((levels[level]->addAvatarState(object,frameCount)) != EENGINE_SUCCESS) {
      
      return EADDSTATE_FAILED;
   }

   return EENGINE_SUCCESS;
}

int ChangeEngine::drawObject(std::string level, std::string object, int state, int frame) {
   
   #ifdef DEBUG
   fprintf(stderr,"ChangeEngine: Drawing %s to level %s\n",object.c_str(),level.c_str());
   #endif

   if (levels.find(level) == levels.end()) {
      
      return EENGINE_FAILURE;
   }
   
   if ((levels[level]->drawObject(window,object,state,frame)) != EENGINE_SUCCESS) {
      
      return EENGINE_FAILURE;
   }
   
   return EENGINE_SUCCESS;
}

int ChangeEngine::drawStart() {
   
   SDL_FillRect(this->window->getScreen(), &(this->window->getScreen())->clip_rect, SDL_MapRGB(this->window->getScreen()->format, 0x00, 0x00, 0x00));
   
   return EENGINE_SUCCESS;
}

int ChangeEngine::drawFinish() {
   
   //Complete the drawing process
   SDL_Flip(window->getScreen());
   
   return EENGINE_SUCCESS;
}

int ChangeEngine::attachControllerToGameObject(const char* level, const char* object, GameController* controller) {

   levels[level]->attachController(object, this->listener, controller);

   return EENGINE_SUCCESS;
}

int ChangeEngine::pollEvent() {

   if (!(listener->pollEvent()))
      return EENGINE_FAILURE;

   return EENGINE_SUCCESS;
}

int ChangeEngine::actObjects(const char* level) {

   levels[level]->actObjects(this->getEventListener());
   
   return EENGINE_SUCCESS;
}
