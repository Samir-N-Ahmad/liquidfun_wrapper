//
//  LiquidFunEngine.cpp
//  liquidFunAPI
//
//  Created by Samir Ahmad on 01/11/2023.
//

#include <iostream>

#include "LiquidFunEngine.h"



void LiquidFunEngine::initalize(b2Vec2 gravity){
    m_worldGravity = gravity;
    m_world = new b2World(m_worldGravity);
}

LiquidFunEngine::LiquidFunEngine() {
    m_world = nullptr;
}

LiquidFunEngine& LiquidFunEngine::instance(){
    static LiquidFunEngine instance;
    return instance;
}

void LiquidFunEngine::dispose() {
    std::cout<< "desposing Liquid fun API";
}


void LiquidFunEngine::addCircle(float radius, float xPosition, float yPosition) {
    
    b2BodyDef* bodyDef = new b2BodyDef();
    b2Body* body = m_world->CreateBody(bodyDef);
    body->SetType(b2BodyType::b2_dynamicBody);
    body->SetTransform(b2Vec2(xPosition, yPosition), 1);
    
    BaseWidget* circle  = new CircleWidget(1, body, "ad", bodyDef, 2);
    
    m_widgets[1] = circle;
}

void LiquidFunEngine::draw(){

    for (int i = 0; i < 100; ++i) {
        m_world->Step(0.1, 0.2, 0.2);
      }

    
}
    
std::vector<std::vector<float> > LiquidFunEngine::render(){
    if(!m_widgets.empty()) {
        return {m_widgets.at(0)->getPosition()};
    }
}
