/*
 *  @author main.cpp
 *
 *  @date Feb 26, 2011
 *  @author cedric
 */

#include <cstdlib>
#include <iostream>
#include "ChangeEngine.h"

using namespace std;

int main(int argc, char **argv) {

   ChangeEngine* engine = ChangeEngine::Initiate();
   ChangeEngine* engine2 = ChangeEngine::Initiate();

   cout << "Engine: " << engine << endl;
   cout << "Engine2: " << engine2 << endl;

   engine->CreateWindow(640,480,0,0);
   engine->Destroy();

   return(EXIT_SUCCESS);
}
