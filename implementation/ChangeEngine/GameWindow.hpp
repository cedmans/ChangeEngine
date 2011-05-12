#include "mitlicense.hpp"

/**
 * @file GameWindow.hpp
 * Game window which creates and controls the output window for the game.
 *
 * @date May 3, 2011
 * @author Cedric Wienold
 */

#ifndef GAMEWINDOW_HPP_
#define GAMEWINDOW_HPP_

#include "SDL/SDL.h"

//Forward declaration to manage circular dependency
class ChangeEngine;

class GameWindow {
   private:
      static GameWindow* pInstance;

      ChangeEngine* engine;

      int width, height, x, y;

      //Main screen surface
      SDL_Surface* screen;

   public:
		GameWindow();
      ~GameWindow();

      static GameWindow* Initiate(ChangeEngine* engine);
      static void Destroy();

      int CreateWindow(int x, int y, int width, int height);
      
      //Expose variables
      SDL_Surface* getScreen();
};

#endif /* GAMEWINDOW_HPP_ */

