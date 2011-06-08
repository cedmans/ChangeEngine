#include "mitlicense.hpp"

#include "ChangeEngine.hpp"

int main(int argc, char** argv) {
   
   ChangeEngine *engine = ChangeEngine::Initiate();
   
   engine->setWindowCaption("Galaxterminate!");
   
   engine->createWindow(800, 600, 32);

   GameAvatar* avatar = new GameAvatar();
   
   avatar->attachImage("spaceship.png",108,101);
   
   SDL_BlitSurface(avatar->getSurface(),NULL,engine->getWindow()->getScreen(),NULL);
   SDL_Flip(engine->getWindow()->getScreen());
   
   SDL_Delay(2000);
   
   engine->Destroy();
   
   return 0;
}
