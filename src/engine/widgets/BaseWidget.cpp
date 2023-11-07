
#include "BaseWidget.h"




std::vector<float> BaseWidget::getPosition(){
    return {m_body->GetPosition().x, m_body->GetPosition().y};
}
