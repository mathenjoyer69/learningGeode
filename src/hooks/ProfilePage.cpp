#include "ProfilePage.hpp"

bool MyProfilePage::init(int acountID, bool ownProfile) {
    if (!ProfilePage::init(acountID, ownProfile)) {
        return false;
    }

    return true;
}