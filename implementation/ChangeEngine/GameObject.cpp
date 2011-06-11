/**
 * @file GameObject.cpp
 *
 * @author Cedric Wienold
 * @date May 12, 2011
 */

#include "GameObject.hpp"
#include "errorcodes.hpp"
#include "debug.hpp"

GameObject::GameObject() {
   
   x = y = z = w = h = d = 0;
   avatar = NULL;
   controller = NULL;
}

int GameObject::getX() {
   return x;
}

int GameObject::getY() {
   return y;
}

int GameObject::getZ() {
   return z;
}

int GameObject::getWidth() {
   return w;
}

int GameObject::getHeight() {
   return h;
}

int GameObject::getDepth() {
   return d;
}

void GameObject::setX(int x) {
   this->x = x;
}

void GameObject::setY(int y) {
   this->y = y;
}

void GameObject::setZ(int z) {
   this->z = z;
}

void GameObject::setWidth(int w) {
   this->w = w;
}

void GameObject::setHeight(int h) {
   this->h = h;
}

void GameObject::setDepth(int d) {
   this->d = d;
}

void GameObject::Destroy(GameObject* object) {
   
   #ifdef DEBUG
   fprintf(stderr,"GameObject: Destroying object.\n");
   #endif

   if (object->avatar != NULL) {
      
      delete object->avatar;
   }
   
   delete object;
}

int GameObject::attachImage(std::string filename, int tileWidth, int tileHeight) {
   
   #ifdef DEBUG
   fprintf(stderr,"GameObject: Attaching %s to object.\n",filename.c_str());
   #endif

   if (avatar == NULL) {
      
      avatar = new GameAvatar();
   }
   else {
      
      #ifdef DEBUG
      fprintf(stderr,"GameObject: There's already an attached avatar!\n");
      #endif
      
      return EATTACH_AVATAR_ALREADY_EXISTS;
   }
   
   if ((avatar->attachImage(filename,tileWidth,tileHeight)) != EENGINE_SUCCESS) {
      
      return EATTACHIMAGE_FAILED;
   }
   
   return EENGINE_SUCCESS;
}

int GameObject::addAvatarState(int frameCount) {
   
   #ifdef DEBUG
   fprintf(stderr,"GameObject: Adding state to avatar\n");
   #endif
   
   if (avatar == NULL) {
      
      #ifdef DEBUG
      fprintf(stderr,"GameObject: NO AVATAR HOLY HELL NOOOOO\n");
      #endif
      
      return EADDSTATE_FAILED;
   }
   
   avatar->addAvatarState(frameCount);
   
   return EENGINE_SUCCESS;
}

int GameObject::drawObject(GameWindow* window, int state, int frame) {
   
   if (avatar == NULL) {
      
      return EENGINE_FAILURE;
   }
   
   #ifdef DEBUG
   fprintf(stderr,"GameObject: Drawing object to (%i,%i)\n",state,frame);
   #endif

   return avatar->drawObject(window,x,y,state,frame);
}

int GameObject::attachController(EventListener* listener, GameController* controller) {
   
   if (controller == NULL) {
      
      return EENGINE_FAILURE;
   }
   
   if (controller == NULL) {
      
      return EENGINE_FAILURE;
   }
   
   this->listener = listener;
   
   this->controller = controller;
   
   return EENGINE_SUCCESS;
}

int GameObject::act(GameLevel* level, EventListener* listener) {
   
   if (controller != NULL) {
      
      controller->act(level,this,listener);
   }
   
   return EENGINE_SUCCESS;
}
