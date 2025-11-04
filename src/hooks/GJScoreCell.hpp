#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GJScoreCell.hpp>

class $modify(MyGJScoreCell, GJScoreCell) {
    public:
        virtual void loadFromScore(GJUserScore* s);
};
