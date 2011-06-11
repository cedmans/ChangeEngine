#include "mitlicense.hpp"

/**
 * @file EventListener.hpp
 * Listener used for grabbing events.
 *
 * @date May 21, 2011
 * @author Cedric Wienold
 */

#ifndef _EVENTLISTENER_HPP
#define _EVENTLISTENER_HPP

#include "SDL/SDL.h"

class EventListener {
   public:
      /**
       * Poll the system for events. This is generally run in a loop for as long as you wish to
       * listen for events.
       */
      bool pollEvent();

      /**
       * Receive the currently held event.
       * @return Event that the listener has heard.
       */
      int getEvent();

      /**
       * If the event is a keypress, this will return which key.
       * @return The keypress triggering the event.
       */
      int getKey();
   private:
      SDL_Event event;
};

#endif /* _EVENTLISTENER_HPP */
