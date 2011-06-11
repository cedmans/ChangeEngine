#include "mitlicense.hpp"

#include "ChangeEngine.hpp"
#include "KeyboardController.hpp"

int main(int argc, char** argv) {
   
   ChangeEngine *engine = ChangeEngine::Initiate();
   
   engine->setWindowCaption("Galaxterminate!");
   
   engine->createWindow(800, 600, 32);
   
   engine->createLevel("Level1");
   engine->createGameObject("Level1","Object1");
   engine->attachImageToGameObject("Level1","Object1","spaceship.png",37,32);
   engine->attachControllerToGameObject("Level1","Object1",(GameController*)(new KeyboardController()));
   
   int event, key;

   bool gameRunning = true;
   
   while (gameRunning) {

      engine->drawStart();
      engine->drawObject("Level1","Object1",0,0);
      engine->drawFinish();

      engine->pollEvent();
      
      event = engine->getEventListener()->getEvent();
      
      switch (event) {
	 
	 case CE_KEYDOWN:
	    if (engine->getEventListener()->getKey() == CE_KB_ESCAPE)
	       gameRunning = false;
	    break;
	 case CE_QUIT:
	    gameRunning = false;
	    break;
	 default:
	    break;
      }
      
      engine->actObjects("Level1");
      
   }
      
   engine->Destroy();
   
   return 0;
}
