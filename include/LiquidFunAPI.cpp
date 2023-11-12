#include <Box2D/Box2D.h>
#include <iostream>
#include <vector>

#include "LiquidFunAPI.h"
#include "Utils.h"
extern "C" {
  void LiquidEngine_Initialize(LiquidFunEngine* engine){
//         engine->initalize();
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

float** Render(LiquidFunEngine* engine){
    std::vector<std::vector<float> >  vectors = engine->render();
    float** postions = Utils::worldPostionsToDynamicArray(vectors);
    
    return postions;
}
}
