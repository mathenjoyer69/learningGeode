#include "GJListLayer.hpp"
#include "../layers/FriendsLayer.hpp"

bool MyGJListLayer::init(BoomListView* listView, const char* title, cocos2d::ccColor4B color, float width, float height, int p5) {
    if (!GJListLayer::init(listView, title, color, width, height, p5)) {return false;}

    // if (auto node = this->getChildByID("list-view")) {
    //     if (auto list = typeinfo_cast<CustomListView*>(node)) {
    //         for (auto* obj : CCArrayExt<CCObject*>(list->m_entries)) {
    //             if (auto s = typeinfo_cast<GJUserScore*>(obj)) {
    //                 log::info("friend: {}", s->m_userName);
    //             }
    //         }
    //     }
    // }
    auto menu = CCMenu::create();
    menu->setPosition({0, 0});
    menu->setID("my-menu");
    auto btnSprite = CCSprite::createWithSpriteFrameName("GJ_menuBtn_001.png");
    auto friendLyrBtn = CCMenuItemSpriteExtra::create(
        btnSprite,
        nullptr,
        this,
        menu_selector(MyGJListLayer::openLayer)
    );
    friendLyrBtn->setPosition({476.75, 11.25});
    menu->addChild(friendLyrBtn);
    this->addChild(menu);
    return true;
}

void MyGJListLayer::openLayer(CCObject*) {
    auto scene = CCScene::create();
    scene->setID("friends-scene");
    auto FriendsLayer = FriendsLayer::create();
    scene->addChild(FriendsLayer);
    CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene));
}
