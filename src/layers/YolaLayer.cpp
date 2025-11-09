#include "YolaLayer.hpp"
#include <random>

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
    if (!CCLayer::init()) {return false;}
    if (sharedInstance == nullptr) {sharedInstance = this;}

    auto bgMenu = CCMenu::create();
    bgMenu->setID("bg-menu");
    bgMenu->setPosition({0, 0});
    this->addChild(bgMenu);
    auto bgSprite = CCSprite::create("yolapork.png"_spr);
    m_winSize  = CCDirector::sharedDirector()->getWinSize();

    bgSprite->setPosition({m_winSize .width / 2, m_winSize .height / 2});
    bgSprite->setScaleY(4.0f);
    bgSprite->setScaleX(11.5f);
    bgSprite->setID("bg-sprite");
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

    //pong
    backBtn->setPosition({16.25, 20});
    BackMenu->addChild(backBtn);

    auto pongMenu = CCMenu::create();
    pongMenu->setID("pong-menu");
    pongMenu->setPosition({0, 0});
    this->addChild(pongMenu);

    m_rightPong = CCSprite::create("yolapork.png"_spr);
    m_rightPong->setID("right-pong");
    m_rightPong->setPosition({m_winSize .width-50, m_winSize .height / 2});
    m_rightPong->setColor({255, 0, 0});
    pongMenu->addChild(m_rightPong);

    m_leftPong = CCSprite::create("yolapork.png"_spr);
    m_leftPong->setID("left-pong");
    m_leftPong->setPosition({50, m_winSize .height / 2});
    m_leftPong->setColor({0, 0, 255});
    pongMenu->addChild(m_leftPong);

    m_ball = CCSprite::create("yolapork.png"_spr);
    m_ball->setID("ball");
    m_ball->setPosition({m_winSize .width / 2, m_winSize .height / 2});
    m_ball->setColor({255, 255, 255});
    m_ball->setScaleY(0.225f);
    m_ball->setScaleX(0.4f);
    pongMenu->addChild(m_ball);

    m_ballVel = CCPoint(250.0f, 150.0f);
    this->schedule(schedule_selector(YolaLayer::updateBall));

    return true;
}

void YolaLayer::onBackButton(CCObject* sender) {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
    sharedInstance = nullptr;
}

void YolaLayer::resetBall(bool right) {
    m_ball->setPosition({m_winSize.width / 2, m_winSize.height / 2});

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(200, 300);
    int Velocity = dis(gen);
    int sign = (rand() % 2 == 0) ? 1 : -1;
    m_ballVel = CCPoint(right ? Velocity : -1 * Velocity, sign * 150.0f);
}

void YolaLayer::updateBall(float dt) {
    auto pos = m_ball->getPosition();
    pos += m_ballVel * dt;
    m_ball->setPosition(pos);

    const float radius = 10.0f;

    if (pos.y < radius || pos.y > m_winSize.height - radius) {m_ballVel.y *= -1.0f;}

    auto rightPos = m_rightPong->getPosition();
    rightPos.y += (m_ball->getPositionY() - rightPos.y) * 0.05f;
    m_rightPong->setPosition(rightPos);

    auto leftPos = m_leftPong->getPosition();
    auto mouseY = getMousePos().y;
    leftPos.y += (mouseY - leftPos.y) * 0.2f;
    m_leftPong->setPosition(leftPos);
    auto ballBB = m_ball->boundingBox();
    auto leftBB = m_leftPong->boundingBox();
    auto rightBB = m_rightPong->boundingBox();

    if (ballBB.intersectsRect(leftBB) && m_ballVel.x < 0) {m_ballVel.x *= -1.0f;}
    if (ballBB.intersectsRect(rightBB) && m_ballVel.x > 0) {m_ballVel.x *= -1.0f;}
    if (pos.x < 0 || pos.x > m_winSize.width) {resetBall(pos.x > m_winSize.width);}
}
