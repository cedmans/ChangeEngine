#include "mitlicense.hpp"

/**
 * @file GameLevel.hpp
 * Level of the game containing actual game objects and regulating interations between said objects.
 *
 * @date May 12, 2011
 * @author Cedric Wienold
 */

#ifndef _GAMELEVEL_HPP
#define _GAMELEVEL_HPP

#include <map>
#include <string>

#include "GameObject.hpp"
#include "debug.hpp"
#include "errorcodes.hpp"

#include "SDL/SDL.h"

class GameLevel {
   private:      
      /**
       * Array of game objects being handled by this engine.
       */
      std::map<std::string, GameObject*> objects;
   
   public:
   
      /**
       * Destroy the given level and all managed objects therein.
       */
      static void Destroy(GameLevel* level);
      
      /**
       * Create a game object to be managed by the level.
       */
      int createGameObject(std::string objectName);
};

#endif /* _GAMELEVEL_HPP */
