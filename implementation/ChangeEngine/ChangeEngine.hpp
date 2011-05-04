#include "mitlicense.hpp"

/**
 * @file ChangeEngine.hpp
 * Game engine which handles most game elements.
 *
 * @date May 3, 2011
 * @author Cedric Wienold
 */

#ifndef CHANGEENGINE_HPP_
#define CHANGEENGINE_HPP_

#define DEBUG

#include "GameWindow.hpp"

/**
 * Main class of ChangeEngine which handles game elements.
 */
class ChangeEngine {
   public:
      static ChangeEngine* Initiate();
      void Destroy();

      // Publicize important game engine objects
      GameWindow* getWindow();

   private:
      ChangeEngine();
      virtual ~ChangeEngine();
      static ChangeEngine* pInstance;

      bool CreateWindow(int w, int h);
      bool CreateWindow(int w, int h, int x, int y);
      
      int width, height, xpos, ypos;

      GameWindow *window;
};

#endif /* CHANGEENGINE_H_ */
