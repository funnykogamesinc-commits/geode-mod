#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/CCLabelBMFont.hpp>

using namespace geode::prelude;

// ===== GLOBAL FONT HOOK =====
// This hooks into the creation of EVERY label in the game
class $modify(CCLabelBMFont) {
    static CCLabelBMFont* create(const char* str, const char* fntFile) {
        // We intercept the font file request and replace it with yours
        return CCLabelBMFont::create(str, "Lemon Milk.fnt");
    }
};

// ===== MENU LAYER HOOK =====
class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        ccColor3B orange = { 255, 165, 0 };

        // ===== MAIN MENU BUTTON COLORS =====
        auto mainMenu = this->getChildByID("main-menu-menu");
        if (mainMenu) {
            auto playBtn = mainMenu->getChildByID("play-button");
            auto iconBtn = mainMenu->getChildByID("icon-kit-button");
            auto toolsBtn = mainMenu->getChildByID("editor-button");

            if (playBtn) static_cast<CCRGBAProtocol*>(playBtn)->setColor(orange);
            if (iconBtn) static_cast<CCRGBAProtocol*>(iconBtn)->setColor(orange);
            if (toolsBtn) static_cast<CCRGBAProtocol*>(toolsBtn)->setColor(orange);
        }

        // ===== RAINBOW MORE GAMES BUTTON =====
        auto bottomMenu = this->getChildByID("bottom-menu");
        if (bottomMenu) {
            auto moreGamesBtn = bottomMenu->getChildByID("more-games-button");
            if (moreGamesBtn) {
                auto rainbowAction = CCRepeatForever::create(
                    CCSequence::create(
                        CCTintTo::create(0.3f, 255, 0, 0),
                        CCTintTo::create(0.3f, 255, 165, 0),
                        CCTintTo::create(0.3f, 255, 255, 0),
                        CCTintTo::create(0.3f, 0, 255, 0),
                        CCTintTo::create(0.3f, 0, 0, 255),
                        CCTintTo::create(0.3f, 128, 0, 128),
                        nullptr
                    )
                );
                moreGamesBtn->runAction(rainbowAction);
            }
        }

        // ===== CORNER IMAGE (Profilepic.png) =====
        auto cornerImage = CCSprite::create("Profilepic.png");
        if (cornerImage) {
            cornerImage->setScale(0.4f);
            auto winSize = CCDirector::sharedDirector()->getWinSize();
            
            float padding = 20.0f;
            float xPos = winSize.width - (cornerImage->getScaledContentSize().width / 2) - padding;
            float yPos = winSize.height - (cornerImage->getScaledContentSize().height / 2) - padding;

            cornerImage->setPosition({xPos, yPos});
            this->addChild(cornerImage);
        }

        return true;
    }
};
