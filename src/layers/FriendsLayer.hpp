#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class FriendsLayer : public CCLayer {
    public:
        static FriendsLayer* create();
        //void onBackButton(CCObject*);
        
    private:
        virtual bool init();
        static FriendsLayer* sharedInstance;
};