
/*
 // BaseWidget.h
 // create by Samir Ahmad
 */

#ifndef BaseWidget_h
#define BaseWidget_h

#include <iostream>
#include <Box2D/Box2D.h>

class BaseWidget{
private:
    int m_id;
    std::string m_tag;
    b2Body* m_body;
    b2BodyDef* m_bodyDefinition;
    
public:
    BaseWidget();
    BaseWidget(const int& id, b2Body* body,const std::string& tag, b2BodyDef* bodyDefinition): m_tag(tag), m_id(id), m_bodyDefinition(bodyDefinition), m_body(body) {
        
    };
    
    ~BaseWidget();
    std::vector<float> getPosition();
    virtual void rotate() = 0;
    virtual void translate() = 0;
};


#endif
