#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GJListLayer.hpp>

class $modify(MyGJListLayer, GJListLayer) {
    bool init(BoomListView* listView, const char* title, cocos2d::ccColor4B color, float width, float height, int p5);
};