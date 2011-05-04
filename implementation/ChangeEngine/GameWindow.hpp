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

class GameWindow {
   private:
      virtual ~GameWindow();
      
      static GameWindow* pInstance;
      
      int width, height, x, y;
   
   public:
      static GameWindow* Initiate(int w, int h, int x, int y);
      void Destroy();
};

#endif /* GAMEWINDOW_HPP_ */

