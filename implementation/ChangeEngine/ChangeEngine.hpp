#include "mitlicense.hpp"

/**
 * @file ChangeEngine.hpp
 * Game engine which handles most game elements.
 *
 * @date May 12, 2011
 * @author Cedric Wienold
 */

#ifndef CHANGEENGINE_HPP_
#define CHANGEENGINE_HPP_

#include <map>
#include <string>

#include "debug.hpp"

#include "GameWindow.hpp"
#include "GameObject.hpp"
#include "GameLevel.hpp"
#include "InputListener.hpp"
#include "EventTypes.hpp"
#include "errorcodes.hpp"

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
       * @param bpp The window's color depth.
       * @return True if creation was successful. False otherwise.
       */
      int createWindow(int w, int h, int bpp);

      /**
       * Create the game engine's window with the given width and heigh at (x,y).
       * @param w The window's width.
       * @param h The window's height.
       * @param x The x coordinate of the window on the screen.
       * @param y The y coordinate of the window on the screen.
       * @param bpp The window's color depth.
       * @return True if creation was successful. False otherwise.
       */
      int createWindow(int x, int y, int w, int h, int bpp);

      /**
       * Return the game engine's window.
       * @return The game engine's window, or NULL if it does not exist.
       */
      GameWindow* getWindow();

      /**
       * TODO: Build functions to access listener without needing to return it here.
       */
      EventListener* getEventListener();

      /**
       * Sets the title text of the game window.
       * @param caption The desired text of the game window.
       */
      void setWindowCaption(const char* caption);
      
      /**
       * Creates a level for the game engine to manage.
       * @param levelName The custom name of the level to create. Your choice here.
       */
      int createLevel(const char* levelName);
      
   private:

      /**
       * The game engine's singleton.
       */
      static ChangeEngine* pInstance;

      /**
       * Window for the game engine.
       */
      GameWindow *window;

      /**
       * Event listener
       */
      EventListener *listener;
      
      //// Now for managed objects, so the user need not care about lots of crap for memory handling
      
      /**
       * Array of levels.
       */
      std::map<std::string,GameLevel*> levels;
};

#endif /* CHANGEENGINE_H_ */
