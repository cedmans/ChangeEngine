/*
 *  @file main.cpp
 *
 *  @date May 21, 2011
 *  @author Cedric Wienold
 */

#include "mitlicense.hpp"

#include <cstdlib>
#include <iostream>
#include "ChangeEngine.hpp"

using namespace std;

const int SCREENWIDTH = 640;
const int SCREENHEIGHT = 480;
const int SCREENBPP = 32;

int main(int argc, char **argv) {

   bool gameRunning = true;

   ChangeEngine* engine = NULL;
   
   engine = ChangeEngine::Initiate();

   engine->setWindowCaption("Event Test");

   engine->createWindow(SCREENWIDTH,SCREENHEIGHT,SCREENBPP);

   /** RUN GAME */

   int event, key;

   while (gameRunning) {

      while( engine->getEventListener()->pollEvent()) {

         event = engine->getEventListener()->getEvent();
         switch(event) {

            case CE_QUIT:
               fprintf(stdout,"Tester: Received CE_QUIT\n");
               gameRunning = false;
               break;
            case CE_KEYDOWN:
               fprintf(stdout,"Tester: Received CE_KEYDOWN\n");

               key = engine->getEventListener()->getKey();
               break;
         }
      }
   }

   /** END GAME */

   ChangeEngine::Destroy();

   return(EXIT_SUCCESS);
}
