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

    this->setKeypadEnabled(true);
    
    auto friendsMenu = CCMenu::create();
    friendsMenu->setPosition({184, 32});
    friendsMenu->setContentSize({200, 248});
    friendsMenu->setID("friends-menu");
    this->addChild(friendsMenu);
    return true;
}

void FriendsLayer::keyBackClicked() {
    sharedInstance = nullptr;
}
