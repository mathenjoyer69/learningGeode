#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LeaderboardsLayer.hpp>
#include "../layers/FriendsLayer.hpp"

class $modify(MyLeaderboardsLayer, LeaderboardsLayer) {
    bool init(LeaderboardState p0) {
        if (!LeaderboardsLayer::init(p0)) {return false;}

        auto menu = CCMenu::create();
        menu->setPosition({0, 0});
        menu->setID("my-menu");
        auto btnSprite = CCSprite::createWithSpriteFrameName("GJ_menuBtn_001.png");
        auto friendLyrBtn = CCMenuItemSpriteExtra::create(
            btnSprite,
            nullptr,
            this,
            menu_selector(MyLeaderboardsLayer::openLayer)
        );
        friendLyrBtn->setPosition({435.75, -18.75});
        menu->addChild(friendLyrBtn);
        this->addChild(menu);

        return true;
    }
    void openLayer(CCObject*) {
        auto scene = CCScene::create();
        scene->addChild(FriendsLayer::create());
        CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene));
    }
};