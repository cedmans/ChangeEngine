/**
 * @file GameObject.cpp
 *
 * @author Cedric Wienold
 * @date May 12, 2011
 */

#include "GameObject.hpp"
#include "errorcodes.hpp"
#include "debug.hpp"

void GameObject::Destroy(GameObject* object) {
   
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
