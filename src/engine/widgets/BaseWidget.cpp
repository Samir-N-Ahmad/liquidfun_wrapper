
#include "BaseWidget.h"




std::vector<float> BaseWidget::getPosition(){
    b2Transform transform = m_body->GetTransform();
    return {m_body->GetPosition().x, m_body->GetPosition().y};
}

std::vector<float> BaseWidget::getTransformation() {
    
    return {m_body->GetTransform().p.x, m_body->GetTransform().p.y, m_body->GetTransform().q.GetAngle()};
}
