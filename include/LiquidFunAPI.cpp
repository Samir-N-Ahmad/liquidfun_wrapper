#include "LiquidFunAPI.h"
#include <Box2D/Box2D.h>
#include <iostream>

extern "C" {
  void LiquidEngine_Initialize(LiquidFunEngine* engine){
         engine->initalize();
  }
  void LiquidEngine_Draw(LiquidFunEngine* engine){
    engine->draw();
  }
  void LiquidEngine_Dispose(LiquidFunEngine* engine){
    engine->dispose();
  }

  int32_t Health_Check(){
    return 11;
  }
}
