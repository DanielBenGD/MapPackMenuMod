#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class $modify(DanielMapPackButton, MenuLayer) {

    void onDanielMapPackButton(CCObject* sender) {
        CreatorLayer::create()->onMapPacks(sender);
    }

    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        if (auto menu = this->getChildByID("right-side-menu")) {
            auto btnSprite = CCSprite::createWithSpriteFrameName("GJ_mapPacksBtn_001.png");

            auto newButton = CCMenuItemSpriteExtra::create(
                btnSprite,
                this,
                menu_selector(DanielMapPackButton::onDanielMapPackButton)
            );

            newButton->setID("daniel-mappack-button");

            menu->addChild(newButton);

            menu->updateLayout();
        }

        return true;
    }
};
