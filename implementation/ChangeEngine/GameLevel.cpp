/**
 *  @file GameLevel.cpp
 *
 *  @date May 12, 2011
 *  @author Cedric Wienold
 */

#include "GameLevel.hpp"

void GameLevel::Destroy(GameLevel* level) {
   
   //Go through managed objects array and destroy each one.
   for(std::map<std::string,GameObject*>::iterator it = level->objects.begin(); it != level->objects.end(); it++) {
      
      //Sanity check
      if ((*it).second != NULL) {
	 
	 //This is where I would call GameObject::Destroy(*it) or something along those lines
      }
   }
   
   delete level;
}

int GameLevel::createGameObject(std::string objectName) {
   
   if (objects.find(objectName.c_str()) != objects.end()) {
      
      #ifdef DEBUG
      fprintf(stderr,"GameEngine: Object %s already exists.\n",objectName.c_str());
      #endif
   }
   else {

      #ifdef DEBUG
      fprintf(stderr,"GameEngine: Object %s does not exist. Should create now.\n",objectName.c_str());
      #endif
   }
   
   return EENGINE_SUCCESS;
}

