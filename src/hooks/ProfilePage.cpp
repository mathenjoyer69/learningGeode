#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/ProfilePage.hpp>

class $modify(MyProfilePage, ProfilePage) {
    bool init(int accountID, bool ownProfile) {
        if (!ProfilePage::init(accountID, ownProfile)) {return false;}
        auto kids = this->getChildren();
        if (!kids || kids->count() == 0) {return true;}

        auto layer = typeinfo_cast<CCLayer*>(kids->objectAtIndex(0));
        auto menu = typeinfo_cast<CCMenu*>(layer->getChildByID("main-menu"));

        auto btn_sprite = CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");
        auto addfriendbtn = CCMenuItemSpriteExtra::create(
            btn_sprite,
            this,
            menu_selector(MyProfilePage::onAddFriend)
        );
        addfriendbtn->setID("add-friend-btn");
        addfriendbtn->setPosition({0, -223});
        addfriendbtn->setZOrder(50);
        menu->addChild(addfriendbtn);
        return true;
    }
    void onAddFriend(CCObject*) {
        log::info("Add Friend button clicked!");
    }
};