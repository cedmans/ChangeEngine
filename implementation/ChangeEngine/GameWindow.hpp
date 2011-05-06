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

//Forward declaration to manage circular dependency
class ChangeEngine;

class GameWindow {
   private:
      static GameWindow* pInstance;
      
      ChangeEngine* engine;
      
      int width, height, x, y;
   
   public:
		GameWindow();
      virtual ~GameWindow();
      
      static GameWindow* Initiate(ChangeEngine* engine, int w, int h, int x, int y);
      void Destroy();
};

#endif /* GAMEWINDOW_HPP_ */

