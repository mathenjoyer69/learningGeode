#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class YolaLayer : public CCLayer {
    public:
        static YolaLayer* create();
        void onBackButton(CCObject*);

    private:
        virtual bool init();
        static YolaLayer* sharedInstance;
        CCSprite* bgSprite;
};