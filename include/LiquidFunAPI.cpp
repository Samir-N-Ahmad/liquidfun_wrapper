#include <Box2D/Box2D.h>
#include <iostream>
#include <vector>

#include "LiquidFunAPI.h"
#include "Utils.h"
extern "C" {
  LiquidFunEngine* LiquidEngine_Initialize(){
        LiquidFunEngine* engine= LiquidFunEngine::instance();
        engine->initalize(b2Vec2(1,1));
        return engine;
  }
  void LiquidEngine_Draw(LiquidFunEngine* engine){
    std::cout << "CPP === drawing " << engine << std::endl;
      
    engine->draw();
  }
  void LiquidEngine_Dispose(LiquidFunEngine* engine){
        std::cout << "CPP === Destroying  " << engine << std::endl;

    engine->dispose();
  }

  int32_t Health_Check(){
    return 11;
  }

float** Liquid_Render(LiquidFunEngine* engine){
    std::cout << "CPP === Rendering"<< engine << std::endl;
    std::vector<std::vector<float> >  render = engine->render();
    float** postions = Utils::worldPostionsToDynamicArray(render);
    return postions;
}

char* to_string(LiquidFunEngine* engine){
    std:: cout << "CPP === to_string  " << engine <<  std::endl;
    
    char* q = engine->toString();
    
    return q;
}
}
