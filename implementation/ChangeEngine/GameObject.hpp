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

      // TODO: Add a generic way of handling intelligence
      // Think of an "input thinker." One will be for the real player, so the function passed in
      // can be an input handler. Another can be an artificial intelligence thing.


   private:
      int x, y;
      int z; //In 2D games, good for z-buffering. But I don't think I'll get to that.

      int w,h,d; //width, height, depth (latter is probably useless in 2D games)

      GameAvatar* avatar;

};

#endif /* GAMEOBJECT_HPP_ */
