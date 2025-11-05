#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/ProfilePage.hpp>

class $modify(MyProfilePage, ProfilePage) {
    public:
        virtual bool init(int acountID, bool ownProfile);
}