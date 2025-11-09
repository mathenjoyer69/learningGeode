#include "FriendsLayer.hpp"

FriendsLayer* FriendsLayer::sharedInstance = nullptr;

FriendsLayer* FriendsLayer::create() {
    auto ret = new FriendsLayer();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool FriendsLayer::init() {
    if (!CCLayer::init()) {return false;}
    if (sharedInstance == nullptr) {sharedInstance = this;}

    auto bgMenu = CCMenu::create();
    bgMenu->setID("bg-menu");
    bgMenu->setPosition({0, 0});
    this->addChild(bgMenu);
    auto bgSprite = CCSprite::create("yolapork.png"_spr);
    auto m_winSize  = CCDirector::sharedDirector()->getWinSize();

    auto friendsMenu = CCMenu::create();
    friendsMenu->setPosition({0, 0});
    friendsMenu->setID("friends-menu");
    this->addChild(friendsMenu);
    return true;
}