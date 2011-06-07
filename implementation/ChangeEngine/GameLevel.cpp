/**
 *  @file GameLevel.cpp
 *
 *  @date May 12, 2011
 *  @author Cedric Wienold
 */

#include "GameLevel.hpp"

void GameLevel::Destroy(GameLevel* level) {

   #ifdef DEBUG
   fprintf(stderr,"GameLevel: Destroying level.\n");
   #endif
   
   //Go through managed objects array and destroy each one.
   for(std::map<std::string,GameObject*>::iterator it = level->objects.begin(); it != level->objects.end(); it++) {
      
      //Sanity check
      if ((*it).second != NULL) {
	 
	 #ifdef DEBUG
	 fprintf(stderr,"GameLevel: Destroying object %s.\n",(*it).first.c_str());
	 #endif
   
	 //This is where I would call GameObject::Destroy(*it) or something along those lines
	 GameObject::Destroy((*it).second);
      }
   }
   
   delete level;
}

int GameLevel::createGameObject(std::string objectName) {

   //make sure object doesn't already exist here
   if (objects.find(objectName.c_str()) != objects.end()) {
      
      #ifdef DEBUG
      fprintf(stderr,"GameLevel: Object %s already exists.\n",objectName.c_str());
      #endif
      
      return EOBJECT_ALREADY_EXISTS;
   }
   else {

      #ifdef DEBUG
      fprintf(stderr,"GameLevel: Object %s does not exist. Should create now.\n",objectName.c_str());
      #endif
      
      objects[objectName] = new GameObject();
   }
   
   return EENGINE_SUCCESS;
}

