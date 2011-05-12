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

      /**
       * Construct the engine with a null window.
       */
      ChangeEngine();

      /**
       * Initiates the engine if it is not already initiated and returns a pointer to its singleton.
       * @return A pointer to the game engine object, or NULL on failure.
       */
      static ChangeEngine* Initiate();

      /**
       * Shuts down the game engine and removes it from memory.
       * This function will make every effort to detect leftover engine-created objects
       * and destroy them before exiting.
       */
      static void Destroy();


      /**
       * Create the game engine's window with the given width and heigh at (0,0).
       * @param w The window's width.
       * @param h The window's height.
       * @return True if creation was successful. False otherwise.
       */
      int CreateWindow(int w, int h);

      /**
       * Create the game engine's window with the given width and heigh at (x,y).
       * @param w The window's width.
       * @param h The window's height.
       * @param x The x coordinate of the window on the screen.
       * @param y The y coordinate of the window on the screen.
       * @return True if creation was successful. False otherwise.
       */
      int CreateWindow(int x, int y, int w, int h);

      // Publicize important game engine objects

      /**
       * Return the game engine's window.
       * @return The game engine's window, or NULL if it does not exist.
       */
      GameWindow* getWindow();

   private:

      /**
       * The game engine's singleton.
       */
      static ChangeEngine* pInstance;

      GameWindow *window;
};

#endif /* CHANGEENGINE_H_ */
