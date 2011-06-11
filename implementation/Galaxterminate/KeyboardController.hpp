#include "mitlicense.hpp"

/**
 * @file KeyboardController.hpp
 * Class extending GameController which gives simple keyboard access.
 *
 * @date May 21, 2011
 * @author Cedric Wienold
 */

#ifndef _KEYBOARDCONTROLLER_HPP
#define _KEYBOARDCONTROLLER_HPP

#include "GameController.hpp"
#include "EventTypes.hpp"
#include "EventListener.hpp"
#include "GameObject.hpp"

class KeyboardController : public GameController {
   
   public:
   
      void act(GameLevel* level, GameObject* object, EventListener* listener);
};

#endif /* _KEYBOARDCONTROLLER_HPP */
