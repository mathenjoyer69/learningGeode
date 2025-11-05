#include "GJScoreCell.hpp"

void MyGJScoreCell::loadFromScore(GJUserScore* s) {
    GJScoreCell::loadFromScore(s);

    auto kids = this->getChildren();
    if (!kids || kids->count() == 0) return;
    auto first = kids->objectAtIndex(0);

    if (auto layer = typeinfo_cast<CCLayerColor*>(first)) {
        if (s->m_demons > 100){
            layer->setColor({ 160, 139, 255 });
        }
        else if (s->m_demons > 50){
            layer->setColor({ 255, 140, 0 });
        }
        else if (s->m_demons > 10){
            layer->setColor({ 255, 215, 0 });
        }
        else {
            layer->setColor({ 255, 255, 255 });
        }
        return;
    }
}