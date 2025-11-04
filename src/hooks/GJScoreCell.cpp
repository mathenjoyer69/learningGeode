#include "GJScoreCell.hpp"

void MyGJScoreCell::loadFromScore(GJUserScore* s) {
    GJScoreCell::loadFromScore(s);

    auto kids = this->getChildren();
    if (!kids || kids->count() == 0) return;
    auto first = kids->objectAtIndex(0);

    if (auto layer = typeinfo_cast<CCLayerColor*>(first)) {
        layer->setColor({ 160, 139, 255 });
        return;
    }
}