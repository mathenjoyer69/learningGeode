#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class YolaLayer : public CCLayer {
    public:
        CCSprite* m_leftPong;
        CCSprite* m_rightPong ;
        CCSprite* m_ball;
        
        CCPoint m_ballVel;
        CCSize m_winSize;

        void updateBall(float dt);
        void resetBall(bool right);

        static YolaLayer* create();
        void onBackButton(CCObject*);
        
    private:
        virtual bool init();
        static YolaLayer* sharedInstance;
        CCSprite* bgSprite;
};