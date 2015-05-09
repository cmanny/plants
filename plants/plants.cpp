#include "StateEngine.h"
#include "Entity.h"
#include "RunningState.h"
#include <iostream>

int main() {
 
  // Instantiate game instance
  StateEngine* engine = new StateEngine( 
      640, 
      480, 
      60, 
      string("Plants"));
  engine->start();

  return 0;
}
