#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

// This mod safely adds a new Map Packs button to the top-right menu.
class $modify(DanielMapPackButton, MenuLayer) {

    // This is the function that our new button will call when clicked.
    void onDanielMapPackButton(CCObject* sender) {
        // This is the correct and safe way to open the Map Packs screen.
        // We create a temporary CreatorLayer just to call its onMapPacks function.
        // This is a standard and stable technique in Geode modding.
        CreatorLayer::create()->onMapPacks(sender);
    }

    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        // We find the menu on the top-right of the screen.
        // This is the menu that holds the Settings, Profile, and other buttons.
        if (auto menu = this->getChildByID("right-side-menu")) {

            // Create the sprite for our new button using the Map Packs sprite.
            auto btnSprite = CCSprite::createWithSpriteFrameName("GJ_mapPacksBtn_001.png");
            
            // Create the button itself.
            auto newButton = CCMenuItemSpriteExtra::create(
                btnSprite,
                this,
                // We tell the button to call our new function when clicked.
                menu_selector(DanielMapPackButton::onDanielMapPackButton)
            );

            // Set the developer ID for our new button.
            newButton->setID("daniel-mappack-button");

            // Add our new button to the menu.
            menu->addChild(newButton);

            // IMPORTANT: We tell the menu to update its layout.
            // This will automatically position our new button next to the others.
            menu->updateLayout();
        }

        return true;
    }
};