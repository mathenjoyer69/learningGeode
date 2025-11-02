#include "GJGarageLayer.hpp"
#include "../layers/YolaLayer.hpp"

bool MyGJGarageLayer::init() {
    if (!GJGarageLayer::init()) {
        return false;
    }
    auto menu = CCMenu::create();
    this->addChild(menu);

    auto customBtnSprite = CCSprite::create("yolapork.png"_spr);
    customBtnSprite->setScale(.75f);
    m_fields->yolaporkButton = CCMenuItemSpriteExtra::create(
        customBtnSprite,
        nullptr,
        this,
        menu_selector(MyGJGarageLayer::onYolaporkButton)
    );
    m_fields->yolaporkButton->setPosition({264, -131});
    m_fields->yolaporkButton->setScaleY(0.675f);
    menu->addChild(m_fields->yolaporkButton);
    return true;
}

void MyGJGarageLayer::onYolaporkButton(CCObject*) {
    m_fields->yolaporkButton->setScaleY(0.675f);
    auto scene = CCScene::create();
    auto yolaLayer = YolaLayer::create();
    scene->addChild(yolaLayer);
    CCDirector::sharedDirector()->pushScene(scene);
}