// $Id$
/**
 * @file ChangeEngine.h
 * Game engine which handles most game elements.
 *
 * @date Feb 26, 2011
 * @author Cedric Wienold
 */
// $Log$

#ifndef CHANGEENGINE_H_
#define CHANGEENGINE_H_

#include "GameWindow.h"

/**
 * Main class of ChangeEngine which handles game elements.
 */
class ChangeEngine {
   public:
      static ChangeEngine* Initiate();
      void Destroy();

      bool CreateWindow(int w, int h);
      bool CreateWindow(int w, int h, int x, int y);

   private:
      ChangeEngine();
      virtual ~ChangeEngine();
      static ChangeEngine* pInstance;

      int width, height, xpos, ypos;

      GameWindow *window;
};

#endif /* CHANGEENGINE_H_ */
