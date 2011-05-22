/**
 *  @file EventListener.cpp
 *
 *  @date May 21, 2011
 *  @author Cedric Wienold
 */

#include "debug.hpp"

#include "InputListener.hpp"
#include "EventTypes.hpp"
#include "errorcodes.hpp"

bool EventListener::pollEvent() {

   return SDL_PollEvent(&event);
}

int EventListener::getEvent() {

   return event.type;
}

int EventListener::getKey() {

   return event.key.keysym.sym;
}
