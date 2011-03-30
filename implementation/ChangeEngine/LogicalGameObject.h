/*
 * @file LogicalGameObject.h
 *
 * @date Feb 27, 2011
 * @author Cedric Wienold
 */

#ifndef LOGICALGAMEOBJECT_H_
#define LOGICALGAMEOBJECT_H_

#include "GameObject.h"

class LogicalGameObject: public GameObject {
   public:
      LogicalGameObject(int,int,int);
      virtual ~LogicalGameObject();
};

#endif /* LOGICALGAMEOBJECT_H_ */
