#include "../State/PlayerEditGender.h"
#include "../functions.h"
#include "../Game/DudeObject.h"
#include "../Game/Game.h"
#include "../Graphics/Renderer.h"
#include "../ResourceManager.h"
#include "../UI/ImageList.h"
#include "../UI/Image.h"
#include "../UI/TextArea.h"
#include "../UI/ImageButton.h"

namespace Falltergeist
{
    namespace State
    {
        PlayerEditGender::PlayerEditGender() : State()
        {
        }

        PlayerEditGender::~PlayerEditGender()
        {
        }

        void PlayerEditGender::init()
        {
            if (_initialized) return;
            State::init();

            setFullscreen(false);
            setModal(true);

            Point bgPos = Point((Game::getInstance()->renderer()->size() - Point(640, 480)) / 2);
            int bgX = bgPos.x();
            int bgY = bgPos.y();

            auto bg = new UI::Image("art/intrface/charwin.frm");
            bg->setPosition(bgPos + Point(236, 0));

            _maleImage = new UI::ImageList({
                                            "art/intrface/maleoff.frm",
                                            "art/intrface/maleon.frm"
                                        }, bgX+260, bgY+2);
            _maleImage->mouseClickHandler().add(std::bind(&PlayerEditGender::onMaleButtonPress, this, std::placeholders::_1));

            _femaleImage = new UI::ImageList({
                                                                    "art/intrface/femoff.frm",
                                                                    "art/intrface/femon.frm"
                                                                    }, bgX+310, bgY+2);
            _femaleImage->mouseClickHandler().add(std::bind(&PlayerEditGender::onFemaleButtonPress, this, std::placeholders::_1));

            auto doneBox = new UI::Image("art/intrface/donebox.frm");
            doneBox->setPosition(bgPos + Point(250, 42));

            auto doneLabel = new UI::TextArea(_t(MSG_EDITOR, 100), bgX+281, bgY+45);
            doneLabel->setFont("font3.aaf", {0xb8, 0x9c, 0x28, 0xff});

            auto doneButton = new UI::ImageButton(UI::ImageButton::Type::SMALL_RED_CIRCLE, bgX+260, bgY+45);
            doneButton->mouseClickHandler().add(std::bind(&PlayerEditGender::onDoneButtonClick, this, std::placeholders::_1));

            addUI(bg);
            addUI(doneBox);
            addUI(doneButton);
            addUI(doneLabel);
            addUI(_maleImage);
            addUI(_femaleImage);
            setGender(Game::getInstance()->player()->gender());
        }

        void PlayerEditGender::onDoneButtonClick(Event::Mouse* event)
        {
            Game::getInstance()->player()->setGender(_gender);
            Game::getInstance()->popState();
        }

        void PlayerEditGender::onFemaleButtonPress(Event::Mouse* event)
        {
            setGender(GENDER::FEMALE);
        }

        void PlayerEditGender::onMaleButtonPress(Event::Mouse* event)
        {
            setGender(GENDER::MALE);
        }

        void PlayerEditGender::onKeyDown(Event::Keyboard* event)
        {
            switch (event->keyCode())
            {
                case SDLK_ESCAPE:
                    Game::getInstance()->popState();
                    break;
                case SDLK_RETURN:
                    Game::getInstance()->player()->setGender(_gender);
                    Game::getInstance()->popState();
                    break;
                case SDLK_LEFT:
                case SDLK_RIGHT:
                    setGender(_gender);
                    break;
            }
        }

        void PlayerEditGender::setGender(GENDER gender)
        {
            _gender = gender;
            _maleImage->setCurrentImage(gender == GENDER::MALE ? 1 : 0);
            _femaleImage->setCurrentImage(gender == GENDER::FEMALE ? 1 : 0);
        }
    }
}
