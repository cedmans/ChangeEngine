/**
 *  @file BallController.cpp
 *
 *  @date May 12, 2011
 *  @author Cedric Wienold
 */

#include "BallController.hpp"

void BallController::act(GameLevel* level, GameObject* object, EventListener* listener) {

      static int xvel = 1;
      static int yvel = 1;

      if (object->getX() <= 0) {
	 
	 xvel = 1;
      }
      
      if ((object->getX() + object->getWidth()) >= level->getWidth()) {
	 
	 xvel = -1;
      }

      if (object->getY() <= 0) {
	 
	 yvel = 1;
      }
      
      if (level->getHeight() <= (object->getY() + object->getHeight())) {
	 
	 yvel = -1;
      }
      
      object->setX(object->getX() + xvel);
      object->setY(object->getY() + yvel);
}
