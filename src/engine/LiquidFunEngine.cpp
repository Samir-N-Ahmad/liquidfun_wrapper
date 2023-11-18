//
//  LiquidFunEngine.cpp
//  liquidFunAPI
//
//  Created by Samir Ahmad on 01/11/2023.
//

#include <iostream>
#include <sstream>

#include "LiquidFunEngine.h"



void LiquidFunEngine::initalize(b2Vec2 gravity){
    m_worldGravity = gravity;
    m_world = new b2World(m_worldGravity);
}

LiquidFunEngine::LiquidFunEngine() {
    m_world = nullptr;
}

LiquidFunEngine::~LiquidFunEngine() {
}

LiquidFunEngine* LiquidFunEngine::instance(){
    static LiquidFunEngine instance;
    return &instance;
}

void LiquidFunEngine::dispose() {
    LiquidFunEngine::~LiquidFunEngine();

}

void LiquidFunEngine::addCircle(float* radius, float* xPosition, float* yPosition) {
    b2BodyDef* bodyDef = new b2BodyDef();
    b2Body* body = m_world->CreateBody(bodyDef);
    body->SetType(b2BodyType::b2_dynamicBody);
    body->SetTransform(b2Vec2(*xPosition, *yPosition), 1);
    
    BaseWidget* circle  = new CircleWidget(1, body, "ad", bodyDef, 2);
    
    m_widgets.push_back(circle);
}

void LiquidFunEngine::draw(){

    for (int i = 0; i < 100; ++i) {
        m_world->Step(0.1, 2, 2);
      }

    
}
    
std::vector<std::vector<float> > LiquidFunEngine::render(){
    std::vector<std::vector<float>> widgets= {};
    if(!m_widgets.empty()) {
        for(BaseWidget* widget: m_widgets) {
            widgets.push_back(widget->getTransformation());
        }
    }
    return  widgets;
}

char* LiquidFunEngine::toString(){
    std::stringstream stringStream;
    
    stringStream  << "=================================================== " << std::endl;
    stringStream  << "==============LiquidEngine instance================ " << std::endl;
    stringStream  << "=================================================== " << std::endl;

    stringStream  << "world : " << std::endl;
    stringStream  << "  body count  : " << m_world->GetBodyCount() << std::endl;
    stringStream  << "  gravity  : " << m_world->GetGravity().x << " " << m_world->GetGravity().y << std::endl;
    stringStream << std::endl;
    stringStream << std::endl;

    
    stringStream  << "-------------------------------," << std::endl;

    
    stringStream  << "widgets: " << std::endl;
    
    for(BaseWidget* widget: m_widgets){
        stringStream << "   id: "  << std::endl;
        stringStream << "   position   x : " << widget->getPosition()[0] << "    y :" << widget->getPosition()[1] << std::endl;
        stringStream << "   --------------------------"<<std::endl;
    }
    m_log = stringStream.str();
    return m_log.data();
}
