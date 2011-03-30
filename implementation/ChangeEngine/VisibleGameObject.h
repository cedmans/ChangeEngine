/*
 * @file VisibleGameObject.h
 *
 * @date Feb 27, 2011
 * @author Cedric Wienold
 */

#ifndef VISIBLEGAMEOBJECT_H_
#define VISIBLEGAMEOBJECT_H_

#include "GameObject.h"

class VisibleGameObject: public GameObject {
   public:
      VisibleGameObject(int,int,int);
      virtual ~VisibleGameObject();
};

#endif /* VISIBLEGAMEOBJECT_H_ */
