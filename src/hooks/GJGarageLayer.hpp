#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GJGarageLayer.hpp>

class $modify(MyGJGarageLayer, GJGarageLayer) {
    bool init();
    void onYolaporkButton(CCObject*);

    struct Fields {
        CCMenuItemSpriteExtra* yolaporkButton;
    };
};