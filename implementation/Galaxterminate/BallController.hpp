#include "mitlicense.hpp"

/**
 * @file BallController.hpp
 * Class extending GameController which controls the ball.
 *
 * @date May 21, 2011
 * @author Cedric Wienold
 */

#ifndef _BALLCONTROLLER_HPP
#define _BALLCONTROLLER_HPP

#include "GameController.hpp"
#include "EventTypes.hpp"
#include "EventListener.hpp"
#include "GameObject.hpp"

class BallController : public GameController {
   
   public:
   
      void act(GameLevel* level, GameObject* object, EventListener* listener);
};

#endif /* _BALLCONTROLLER_HPP */
