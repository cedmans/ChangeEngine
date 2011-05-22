#include "mitlicense.hpp"

/**
 * @file GameAvatar.hpp
 * This class describes a 2-D sprite-based avatar built with a tile set. Its only function to to
 * maintain the tile set, and draw it out on request.
 *
 * The frames are stored with one state per row. Every call for the next frame will loop through
 * the available frames in that row/state.
 *
 * When constructing the tile set, the user must add each state row separately with the number of
 * frames it holds.
 *
 * @date May 22, 2011
 * @author Cedric Wienold
 */

#ifndef GAMEAVATAR_HPP_
#define GAMEAVATAR_HPP_

#include <vector>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class GameAvatar {
   private:
      SDL_Surface tileSet;
      int tileWidth,tileHeight;

      std::vector<int> frameNumber;

      static SDL_Surface* loadImage(const char* filename);

   public:
      GameAvatar(const char* filename);
};

#endif /* GAMEAVATAR_HPP_ */
