/*
 * @file GameObject.h
 *
 * @date Feb 27, 2011
 * @author Cedric Wienold
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "GameWindow.h"

class GameObject {
   private:
      int x, y, z;

   public:
      GameObject(int,int,int);
      virtual ~GameObject();
};

#endif /* GAMEOBJECT_H_ */
