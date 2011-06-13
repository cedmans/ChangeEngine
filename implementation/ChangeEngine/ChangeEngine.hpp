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
#include "GameController.hpp"
#include "EventListener.hpp"
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
      
      /**
       * Create a managed object for a given level.
       */
      int createGameObject(const char* levelName, const char* objectName);
      
      /**
       * Attach an image to a game object's avatar with a given filename.
       * @param level Name of level to attach image to.
       * @param object Name of object ot attach image to.
       * @param filename Filename of image to attach to object.
       * @param tileWidth Width of a single tile in the image.
       * @param tileHeight Height of a single tile in the image.
       */
      int attachImageToGameObject(std::string level, std::string object, std::string filename, int tileWidth, int tileHeight);
      
      /**
       * Add a state to the avatar tileset manager. A state will be a single row on the tileset.
       * The parameter will be the number of frames on that row. Add states from the top of the
       * tile set to the bottom, in that order specifically.
       * @param frameCount The number of frames on the current row of the tile set.
       */
      int addAvatarState(std::string level, std::string object, int frameCount);
      
      /**
       * Draw an object in a level of the given state and frame to the backbuffer. This will not
       * actually draw anything to the front buffer. To complete drawing, call draw().
       */
      int drawObject(std::string level, std::string object, int state, int frame);
      
      /**
       * Begin the drawing process.
       */
      int drawStart();
      
      /**
       * Complete the drawing process.
       */
      int drawFinish();
      
      /**
       * Attach a controller to the given game object of the given leve.
       */
      int attachControllerToGameObject(const char* level, const char* object, GameController* controller);
      
      /**
       * Poll the event buffer.
       */
      int pollEvent();
      
      /**
       * Runs controller on all objects that have one.
       */
      int actObjects(const char* level);

      /**
       * Sets the transparency color of the given object to the given RGB values.
       */
      int addTransparency(const char* level, const char* object, int r, int g, int b);
      
      GameLevel* getLevel(const char* level);
      
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
