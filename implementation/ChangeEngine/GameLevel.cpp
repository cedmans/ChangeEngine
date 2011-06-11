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

int GameLevel::attachImage(std::string object, std::string filename, int tileWidth, int tileHeight) {
   
   #ifdef DEBUG
   fprintf(stderr,"GameLevel: Attaching \"%s\" to object %s\n",filename.c_str(),object.c_str());
   #endif
   
   //make sure object exists here
   if (objects.find(object.c_str()) != objects.end()) {
      
      #ifdef DEBUG
      fprintf(stderr,"GameLevel: Object %s exists. Attaching image \"%s\"\n",object.c_str(), filename.c_str());
      #endif
      
      if (objects[object.c_str()]->attachImage(filename,tileWidth,tileHeight) != EENGINE_SUCCESS) {
	 
	 fprintf(stderr,"GameLevel: Failed to attach image \"%s\" to %s",filename.c_str(),object.c_str());
	 return EATTACHIMAGE_FAILED;
      }
   }
   else {

      #ifdef DEBUG
      fprintf(stderr,"GameLevel: Object %s does not exist. Somebuddy dun fuj'd up\n",object.c_str());
      #endif
      
      return EATTACHIMAGE_INVALID_OBJECT;
   }
   
   return EENGINE_SUCCESS;
}

int GameLevel::addAvatarState(std::string object, int frameCount) {
   
   #ifdef DEBUG
   fprintf(stderr,"GameLevel: Adding level to %s\n",object.c_str());
   #endif
   
   //make sure object exists
   if (objects.find(object.c_str()) != objects.end()) {
      
      #ifdef DEBUG
      fprintf(stderr,"GameLevel: Object %s exists. Adding state.\n",object.c_str());
      #endif
      
      objects[object.c_str()]->addAvatarState(frameCount);
   }
   else {
      
      #ifdef DEBUG
      fprintf(stderr,"GameLevel: Object %s does not exist. Cannot add state.\n",object.c_str());
      #endif
      
      return EADDSTATE_INVALID_OBJECT;
   }
   
   return EENGINE_SUCCESS;
}

int GameLevel::drawObject(GameWindow* window, std::string object, int state, int frame) {
   
   #ifdef DEBUG
   fprintf(stderr,"GameLevel: Drawing %s (s,f)=(%i,%i)\n",object.c_str(),state,frame);
   #endif

   if (objects.find(object.c_str()) != objects.end()) {
      
      //We DRAW NOW
      return objects[object.c_str()]->drawObject(window,state,frame);
   }
   
   return EENGINE_FAILURE;
}

int GameLevel::attachController(const char* object, EventListener* listener, GameController* controller) {

   objects[object]->attachController(listener,controller);
   
   return EENGINE_SUCCESS;
}
