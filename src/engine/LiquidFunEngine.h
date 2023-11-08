//
//  LiquidFunEngine.h
//  liquidFunAPI
//
//  Created by Samir Ahmad on 01/11/2023.
//

#ifndef LiquidFunEngine_h
#define LiquidFunEngine_h
#include <map>

#include "widgets/BaseWidget.h"
#include "widgets/CircleWidget.h"

class LiquidFunEngine{
    
private:
    std::map<int, BaseWidget*> m_widgets;
    b2World* m_world;
    b2Vec2 m_worldGravity;
    
    void initalize(b2Vec2 gravity);
    LiquidFunEngine();
    
    
public:
    static LiquidFunEngine& instance();
    void dispose();
    void draw();
    void addCircle(float radius, float xPosition, float yPosition);
    std::vector<std::vector<float> > render();

};

#endif /* LiquidFunEngine_h */
