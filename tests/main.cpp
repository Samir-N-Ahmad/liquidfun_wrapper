


#include <iostream>
#include "LiquidFunAPI.h"
#include "LiquidFunEngine.h"
#include "../src/utils/Utils.h"

int main(){
    LiquidFunEngine* engine = LiquidFunEngine::instance();
    engine->initalize(b2Vec2(1,2));
    float a = 2.2;
    engine->addCircle(&a, &a, &a);
    engine->addCircle(&a, &a, &a);
    engine->addCircle(&a, &a, &a);
    LiquidFunEngine* engine3 = LiquidFunEngine::instance();

    std::vector<std::vector<float>> render = engine->render();
    float** renderDynamic = Utils::worldPostionsToDynamicArray(render);
    for(int i = 0; i < 3; i ++) {
        std::cout << renderDynamic[i][0] << " " << renderDynamic[i][1] << std::endl;
    }
    std::cout << LiquidFunEngine::instance()->toString();
    std::cout << "main";
    return 0;
}
