//
//  LiquidFunEngine.h
//  liquidFunAPI
//
//  Created by Samir Ahmad on 01/11/2023.
//

#ifndef LiquidFunEngine_h
#define LiquidFunEngine_h
#include <map>
#include <iostream>

#include "widgets/BaseWidget.h"
#include "widgets/CircleWidget.h"

class LiquidFunEngine{
    
private:
    std::vector<BaseWidget*> m_widgets;
    b2World* m_world;
    std::string m_log;
    b2Vec2 m_worldGravity;
    LiquidFunEngine();
    ~LiquidFunEngine();

    
public:
    static LiquidFunEngine* instance();
    void dispose();
    void initalize(b2Vec2 gravity);
    void draw();
    void addCircle(float* radius, float* xPosition, float* yPosition);
    std::vector<std::vector<float> > render();
    char* toString();
    static std::string a(){
        return "a";
    }


};

#endif /* LiquidFunEngine_h */
