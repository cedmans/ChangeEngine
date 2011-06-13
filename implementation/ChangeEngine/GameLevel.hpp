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

class GameController;

#include <map>
#include <string>

#include "GameObject.hpp"
#include "GameController.hpp"
#include "EventListener.hpp"
#include "debug.hpp"
#include "errorcodes.hpp"

#include "SDL/SDL.h"

class GameLevel {
   private:      
      /**
       * Array of game objects being handled by this engine.
       */
      std::map<std::string, GameObject*> objects;
      
      int width, height;
   
   public:
   
      GameLevel();
   
      /**
       * Destroy the given level and all managed objects therein.
       */
      static void Destroy(GameLevel* level);
      
      /**
       * Create a game object to be managed by the level.
       */
      int createGameObject(std::string objectName);
      
      /**
       * Attached an image to an avatar of the desired object in this level.
       */
      int attachImage(std::string object, std::string filename, int tileWidth, int tileHeight);
      
      /**
       * Add state with given number of frames to desired object in this level.
       */
      int addAvatarState(std::string object, int frameCount);
      
      /**
       * Draw an object of the given state and frame.
       */
      int drawObject(GameWindow* window, std::string object, int state, int frame);
      
      /**
       * Attach a controller to the given object.
       */
      int attachController(const char* object, EventListener* listener, GameController* controller);
      
      /**
       * Run controller on all objects that have one.
       */
      int actObjects(EventListener* listener);
      
      int addTransparency(const char* object, int r, int g, int b);
      
      void setWidth(int w);
      void setHeight(int h);
      
      int getWidth();
      int getHeight();
};

#endif /* _GAMELEVEL_HPP */
