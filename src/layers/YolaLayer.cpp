#include "YolaLayer.hpp"

YolaLayer* YolaLayer::sharedInstance = nullptr;

YolaLayer* YolaLayer::create() {
    auto ret = new YolaLayer();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool YolaLayer::init() {
    if (!CCLayer::init()) {
        return false;
    }
    
    auto bgMenu = CCMenu::create();
    bgMenu->setPosition({0, 0});
    this->addChild(bgMenu);
    auto bgSprite = CCSprite::create("yolapork.png"_spr);
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    bgSprite->setPosition({winSize.width / 2, winSize.height / 2});
    bgSprite->setScaleY(4.0f);
    bgSprite->setScaleX(11.5f);
    bgSprite->setID("bg-menu");
    bgMenu->addChild(bgSprite);

    auto BackMenu = CCMenu::create();
    BackMenu->setPosition({7.75, 277});
    BackMenu->setAnchorPoint({0.5, 0.5});
    BackMenu->setContentSize({100, 40});
    BackMenu->setID("back-menu");
    this->addChild(BackMenu);
    auto backBtnSprite = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
    auto backBtn = CCMenuItemSpriteExtra::create(
        backBtnSprite,
        nullptr,
        this,
        menu_selector(YolaLayer::onBackButton)
    );
    backBtn->setPosition({16.25, 20});
    BackMenu->addChild(backBtn);

    return true;
}

void YolaLayer::onBackButton(CCObject* sender) {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
    sharedInstance = nullptr;
}