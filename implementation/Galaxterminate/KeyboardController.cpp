/**
 *  @file KeyboardController.cpp
 *
 *  @date May 12, 2011
 *  @author Cedric Wienold
 */

#include "KeyboardController.hpp"

void KeyboardController::act(GameLevel* level, GameObject* object, EventListener* listener) {
   
   int event, key;
   
   event = listener->getEvent();
   
   switch( event ) {
      
      case CE_KEYDOWN {
	 
	 key = listener->getKey();
	 
	 switch( key ) {
	    
	    case CE_KB_RIGHT:
	       object->setX(object->getX() + 10);
	       break;
	    case CE_KB_LEFT:
	       object->setX(object->getX() - 10);
	       break;
	    
	    default:
	       break;
	 }
      }
      
      default:
	 break;
   }
}
