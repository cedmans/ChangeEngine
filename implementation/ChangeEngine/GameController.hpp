/**
 * @file GameController.hpp
 * Interface for classes which will control the actions of GameObjects.
 *
 * @date May 21, 2011
 * @author Cedric Wienold
 */

#ifndef _GAMECONTROLLER_HPP
#define _GAMECONTROLLER_HPP

class GameObject;
class GameLevel;

#include "GameLevel.hpp"
#include "EventListener.hpp"

class GameController {
   
   public:
   
      /**
       * Gives the object instructions on how to act given the conditions of the GameLevel.
       * 
       * @param level The current level to give the object a basis upon which to act.
       * @param object The same object that contains this controller, which will be controlled.
       */
      void act(GameLevel* level, GameObject* object, EventListener* listener);
};

#endif /* _GAMECONTROLLER_HPP */
