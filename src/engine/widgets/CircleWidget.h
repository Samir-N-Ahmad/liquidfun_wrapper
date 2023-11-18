/*
 // CircleWidget.h
 // created by Samir Ahmad
 */


#ifndef CircleWidget_h
#define CircleWidget_h

#include "BaseWidget.h"

class CircleWidget: public BaseWidget{
private:
    float m_radius;
    CircleWidget();

    
public:
    CircleWidget(const int& id, b2Body* body,const std::string& tag, b2BodyDef* bodyDefinition, const double& radius);
    
    void rotate() override;
    
    float getRadius();
    void translate() override;
};

#endif
