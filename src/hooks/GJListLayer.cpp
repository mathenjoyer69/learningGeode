#include "GJListLayer.hpp"

bool MyGJListLayer::init(BoomListView* listView, const char* title, cocos2d::ccColor4B color, float width, float height, int p5) {
    if (!GJListLayer::init(listView, title, color, width, height, p5)) {return false;}

    if (auto node = this->getChildByID("list-view")) {
        if (auto list = typeinfo_cast<CustomListView*>(node)) {
            for (auto* obj : CCArrayExt<CCObject*>(list->m_entries)) {
                if (auto s = typeinfo_cast<GJUserScore*>(obj)) {
                    log::info("friend: {}", s->m_userName);
                }
            }
        }
    }
    return true;
}