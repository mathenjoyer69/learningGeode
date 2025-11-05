#include "ProfilePage.hpp"

bool MyProfilePage::init(int accountID, bool ownProfile) {
    if (!ProfilePage::init(accountID, ownProfile)) {return false;}
    auto kids = this->getChildren();
    if (!kids || kids->count() == 0) return true;

    auto layer = typeinfo_cast<CCLayer*>(kids->objectAtIndex(0));
    auto menu = typeinfo_cast<CCMenu*>(layer->getChildByID("main-menu"));

    auto addFriendBtn = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png"),
        this,
        menu_selector(MyProfilePage::onAddFriend)
    );
    addFriendBtn->setID("add-friend-btn");
    addFriendBtn->setPosition({0, -223});
    addFriendBtn->setZOrder(50);
    menu->addChild(addFriendBtn);

    return true;
}

void MyProfilePage::onAddFriend(CCObject* sender) {
    log::info("Add Friend button clicked!");
}