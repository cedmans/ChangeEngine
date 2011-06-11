#include "mitlicense.hpp"

/**
 * @file GameObject.hpp
 * Game object for interacting with our wonderful game.
 *
 * @date May 12, 2011
 * @author Cedric Wienold
 */

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include <string>
#include "GameAvatar.hpp"
#include "GameController.hpp"
#include "EventListener.hpp"

class GameObject {
   public:

      /**
       * Return the X coordinate of this object.
       * @return The X coordinate of this object.
       */
      int getX();

      /**
       * Return the Y coordinate of this object.
       * @return The Y coordinate of this object.
       */
      int getY();

      /**
       * Return the Z coordinate of this object.
       * @return The Z coordinate of this object.
       */
      int getZ();

      /**
       * Return the width of the object.
       * @return the width of the object.
       */
      int getWidth();

      /**
       * Return the height of the object.
       * @return the height of the object.
       */
      int getHeight();

      /**
       * Return the depth of the object.
       * @return the depth of the object.
       */
      int getDepth();
      
      void setX(int);
      void setY(int);
      void setZ(int);
      void setWidth(int);
      void setHeight(int);
      void setDepth(int);
      
      GameObject();
      
      /**
       * Destroy this object and its related avatar, if applicable.
       * @param object the game object ot destroy.
       */
      static void Destroy(GameObject* object);
      
      /**
       * Attach an image to this object's avatar.
       * @param filename Filename of the image to attach to the avatar.
       */
      int attachImage(std::string filename, int tileWidth, int tileHeight);
      
      int addAvatarState(int frameCount);
      
      int drawObject(GameWindow* window, int state, int frame);

      int attachController(EventListener* listener, GameController* controller);
      
      int act(GameLevel* level, EventListener* listener);

   private:
      int x, y;
      int z; //In 2D games, good for z-buffering. But I don't think I'll get to that.

      int w,h,d; //width, height, depth (latter is probably useless in 2D games)

      GameAvatar* avatar;
      EventListener* listener;
      
      GameController* controller;

};

#endif /* GAMEOBJECT_HPP_ */
