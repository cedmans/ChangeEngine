#include "mitlicense.hpp"

#include "ChangeEngine.hpp"
#include "KeyboardController.hpp"
#include "BallController.hpp"

int main(int argc, char** argv) {
   
   ChangeEngine *engine = ChangeEngine::Initiate();
   
   engine->setWindowCaption("Galaxterminate!");
   
   engine->createWindow(800, 600, 32);
   
   engine->createLevel("Level1");
   engine->getLevel("Level1")->setWidth(800);
   engine->getLevel("Level1")->setHeight(600);
   
   engine->createGameObject("Level1","Object1");
   engine->attachImageToGameObject("Level1","Object1","spaceship.png",37,32);
   engine->addTransparency("Level1","Object1",255,255,255);
   engine->attachControllerToGameObject("Level1","Object1",(GameController*)(new KeyboardController()));
   
   engine->createGameObject("Level1","Ball");
   engine->attachImageToGameObject("Level1","Ball","red_ball.png",200,200);
   engine->addTransparency("Level1","Ball",255,255,255);
   engine->attachControllerToGameObject("Level1","Ball",(GameController*)(new BallController()));
   

   int frame=0;
   
   int event;

   bool gameRunning = true;
   
   while (gameRunning) {

      frame == 2 ? frame = 0 : frame++;

      engine->drawStart();
      engine->drawObject("Level1","Object1",0,frame);
      engine->drawObject("Level1","Ball",0,0);
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
