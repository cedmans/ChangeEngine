/*
 *  @author main.cpp
 *
 *  @date Feb 26, 2011
 *  @author cedric
 */

#include <cstdlib>
#include <iostream>
#include "ChangeEngine.hpp"

using namespace std;

int main(int argc, char **argv) {

   ChangeEngine* engine = NULL;
   
   engine = ChangeEngine::Initiate();

   engine->CreateWindow(640,480);
   
   ChangeEngine::Destroy();

   return(EXIT_SUCCESS);
}
