/**
 * @file GameObject.cpp
 *
 * @author Cedric Wienold
 * @date May 12, 2011
 */

#include "GameObject.hpp"

void GameObject::Destroy(GameObject* object) {
   
   if (object->avatar != NULL) {
      
      delete object->avatar;
   }
   
   delete object;
}
