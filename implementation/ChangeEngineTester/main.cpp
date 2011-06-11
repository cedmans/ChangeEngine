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
   
   /** Make a level */
   engine->createLevel("Level1");
   
   /** Construct the ship */
//   engine->createGameObject("Level1","Ship");
   //Give the ship an image with tile width and height of 36x33
/*   if (engine->attachImageToGameObject("Level1","Ship","./images/spaceship.png",36,33) != EENGINE_SUCCESS) {
      
      fprintf(stderr,"Could not attach image!\n");
      fflush(stderr);
      return -1;
   }
   //Add states
   engine->addAvatarState("Level1","Ship",3);
   engine->addAvatarState("Level1","Ship",3);
   engine->addAvatarState("Level1","Ship",3);
   fflush(stderr);*/

   /** RUN GAME */

   int event, key;

   while (gameRunning) {

//      if (engine->drawObject("Level1","Ship",0,0) != EENGINE_SUCCESS)
//         fprintf(stderr,"*** DRAW FAILED ***\n");
      
//      if (SDL_Flip(engine->getWindow()->getScreen()) != 0) 
//         fprintf(stderr,"*** FLIP FAILED ***\n");

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
               
               switch(key) {
                  
                  case CE_KB_ESCAPE:
                     fprintf(stdout,"Tester: Received CE_KB_ESCAPE\n");
                     gameRunning = false;
                     break;
                  default:
                     fprintf(stdout,"Tester: Received CE_KB_somethingelse\n");
                     break;
               }
               
               break;
            case CE_KEYUP:
               fprintf(stdout,"Tester: Received CE_KEYUP\n");
               
               key = engine->getEventListener()->getKey();
               
               break;
            default:
               break;
         }
      }
   }

   /** END GAME */

   ChangeEngine::Destroy();

   return(EXIT_SUCCESS);
}
