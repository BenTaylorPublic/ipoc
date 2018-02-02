#include "InputController.h"
#include "Debug.h"
#include "Conversions.h"

InputController::InputController()
{
}

InputController::~InputController()
{
}

void InputController::IPOCLoad()
{
    resetInputArrays();
    window = nullptr;
}

void InputController::input()
{
    handlePhysicalButton(sf::Keyboard::A, 0);
    handlePhysicalButton(sf::Keyboard::B, 1);
    handlePhysicalButton(sf::Keyboard::C, 2);
    handlePhysicalButton(sf::Keyboard::D, 3);
    handlePhysicalButton(sf::Keyboard::E, 4);
    handlePhysicalButton(sf::Keyboard::F, 5);
    handlePhysicalButton(sf::Keyboard::G, 6);
    handlePhysicalButton(sf::Keyboard::H, 7);
    handlePhysicalButton(sf::Keyboard::I, 8);
    handlePhysicalButton(sf::Keyboard::J, 9);
    handlePhysicalButton(sf::Keyboard::K, 10);
    handlePhysicalButton(sf::Keyboard::L, 11);
    handlePhysicalButton(sf::Keyboard::M, 12);
    handlePhysicalButton(sf::Keyboard::N, 13);
    handlePhysicalButton(sf::Keyboard::O, 14);
    handlePhysicalButton(sf::Keyboard::P, 15);
    handlePhysicalButton(sf::Keyboard::Q, 16);
    handlePhysicalButton(sf::Keyboard::R, 17);
    handlePhysicalButton(sf::Keyboard::S, 18);
    handlePhysicalButton(sf::Keyboard::T, 19);
    handlePhysicalButton(sf::Keyboard::U, 20);
    handlePhysicalButton(sf::Keyboard::V, 21);
    handlePhysicalButton(sf::Keyboard::W, 22);
    handlePhysicalButton(sf::Keyboard::X, 23);
    handlePhysicalButton(sf::Keyboard::Y, 24);
    handlePhysicalButton(sf::Keyboard::Z, 25);

    handlePhysicalButton(sf::Keyboard::Num0, 26);
    handlePhysicalButton(sf::Keyboard::Num1, 27);
    handlePhysicalButton(sf::Keyboard::Num2, 28);
    handlePhysicalButton(sf::Keyboard::Num3, 29);
    handlePhysicalButton(sf::Keyboard::Num4, 30);
    handlePhysicalButton(sf::Keyboard::Num5, 31);
    handlePhysicalButton(sf::Keyboard::Num6, 32);
    handlePhysicalButton(sf::Keyboard::Num7, 33);
    handlePhysicalButton(sf::Keyboard::Num8, 34);
    handlePhysicalButton(sf::Keyboard::Num9, 35);

    handlePhysicalButton(sf::Keyboard::Numpad0, 36);
    handlePhysicalButton(sf::Keyboard::Numpad1, 37);
    handlePhysicalButton(sf::Keyboard::Numpad2, 38);
    handlePhysicalButton(sf::Keyboard::Numpad3, 39);
    handlePhysicalButton(sf::Keyboard::Numpad4, 40);
    handlePhysicalButton(sf::Keyboard::Numpad5, 41);
    handlePhysicalButton(sf::Keyboard::Numpad6, 42);
    handlePhysicalButton(sf::Keyboard::Numpad7, 43);
    handlePhysicalButton(sf::Keyboard::Numpad8, 44);
    handlePhysicalButton(sf::Keyboard::Numpad9, 45);

    handlePhysicalButton(sf::Keyboard::Left, 46);
    handlePhysicalButton(sf::Keyboard::Right, 47);
    handlePhysicalButton(sf::Keyboard::Up, 48);
    handlePhysicalButton(sf::Keyboard::Down, 49);

    handlePhysicalButton(sf::Keyboard::F1, 50);
    handlePhysicalButton(sf::Keyboard::F2, 51);
    handlePhysicalButton(sf::Keyboard::F3, 52);
    handlePhysicalButton(sf::Keyboard::F4, 53);
    handlePhysicalButton(sf::Keyboard::F5, 54);
    handlePhysicalButton(sf::Keyboard::F6, 55);
    handlePhysicalButton(sf::Keyboard::F7, 56);
    handlePhysicalButton(sf::Keyboard::F8, 57);
    handlePhysicalButton(sf::Keyboard::F9, 58);
    handlePhysicalButton(sf::Keyboard::F10, 59);
    handlePhysicalButton(sf::Keyboard::F11, 60);
    handlePhysicalButton(sf::Keyboard::F12, 61);

    handlePhysicalButton(sf::Keyboard::Add, 62);
    handlePhysicalButton(sf::Keyboard::Subtract, 63);
    handlePhysicalButton(sf::Keyboard::Divide, 64);
    handlePhysicalButton(sf::Keyboard::Multiply, 65);

    //Row 1
    handlePhysicalButton(sf::Keyboard::Escape, 66);
    handlePhysicalButton(sf::Keyboard::BackSlash, 67);
    handlePhysicalButton(sf::Keyboard::BackSpace, 68);
    handlePhysicalButton(sf::Keyboard::Comma, 69);
    handlePhysicalButton(sf::Keyboard::Dash, 70);
    handlePhysicalButton(sf::Keyboard::Delete, 71);
    handlePhysicalButton(sf::Keyboard::Equal, 72);
    handlePhysicalButton(sf::Keyboard::Home, 73);
    handlePhysicalButton(sf::Keyboard::Insert, 74);
    //Row 2
    handlePhysicalButton(sf::Keyboard::LAlt, 75);
    handlePhysicalButton(sf::Keyboard::LBracket, 76);
    handlePhysicalButton(sf::Keyboard::LControl, 77);
    handlePhysicalButton(sf::Keyboard::LShift, 78);
    handlePhysicalButton(sf::Keyboard::LSystem, 79);
    handlePhysicalButton(sf::Keyboard::Menu, 80);
    handlePhysicalButton(sf::Keyboard::PageUp, 81);
    handlePhysicalButton(sf::Keyboard::PageDown, 82);
    handlePhysicalButton(sf::Keyboard::Pause, 83);
    handlePhysicalButton(sf::Keyboard::Period, 84);
    handlePhysicalButton(sf::Keyboard::Quote, 85);
    //Row 3
    handlePhysicalButton(sf::Keyboard::RAlt, 86);
    handlePhysicalButton(sf::Keyboard::RBracket, 87);
    handlePhysicalButton(sf::Keyboard::RControl, 88);
    handlePhysicalButton(sf::Keyboard::Return, 89);
    handlePhysicalButton(sf::Keyboard::RShift, 90);
    handlePhysicalButton(sf::Keyboard::RSystem, 91);
    handlePhysicalButton(sf::Keyboard::SemiColon, 92);
    handlePhysicalButton(sf::Keyboard::Slash, 93);
    handlePhysicalButton(sf::Keyboard::Space, 94);
    handlePhysicalButton(sf::Keyboard::Tab, 95);
    handlePhysicalButton(sf::Keyboard::Tilde, 96);
    handlePhysicalButton(sf::Keyboard::End, 97);

    //Mouse
    handleLeftClick(98);
    handlePhysicalButton(sf::Mouse::Right, 99);
    handlePhysicalButton(sf::Mouse::Middle, 100);

    sf::Vector2f windowPosition = window->getWindow()->mapPixelToCoords(sf::Mouse::getPosition(*window->getWindow()), sf::View(sf::FloatRect(0, 0, 1920, 1080)));
    mousePoint.x = windowPosition.x;
    mousePoint.y = windowPosition.y;
}

void InputController::resetInputArrays()
{
    for (int i = 0; i < AMOUNT_OF_PHYSICAL_BUTTONS; i++)
        physicalButtonStatusArray[i] = ButtonUntouched;
}

void InputController::markStartOfLoop()
{

    physicalButtonDown.push(-1);
    physicalButtonUp.push(-1);

    onscreenButtonToClearTrigger.push(nullptr);
}

void InputController::markEndOfLoop()
{

    int currentIndex = -1;

    //Down to hold
    //Keyboard Down to hold
    do
    {
        currentIndex = physicalButtonDown.front();
        physicalButtonDown.pop();

        if (currentIndex == -1) //Escape character
            break;
        else
        {
            physicalButtonStatusArray[currentIndex] = ButtonHold;
        }
    } while (true);

    //Up to Untouched
    //Keyboard Up to Untouched
    do
    {
        currentIndex = physicalButtonUp.front();
        physicalButtonUp.pop();

        if (currentIndex == -1) //Escape character
            break;
        else
        {
            physicalButtonStatusArray[currentIndex] = ButtonUntouched;
        }
    } while (true);


    while (onscreenButtonToClearTrigger.size() >= 1)
    {
        OnscreenButton* temp = onscreenButtonToClearTrigger.front();
        if (temp == nullptr)
        {
            onscreenButtonToClearTrigger.pop();
            return;
        } else
        {
            temp->clearTriggered();
            onscreenButtonToClearTrigger.pop();
        }
    }
}

bool InputController::getPhysicalButtonStatus(const PhysicalButton& inputPhysicalButton, const ButtonStatus& inputStatus) const
{
    if ((inputStatus == ButtonDown || inputStatus == ButtonHold) && physicalButtonStatusArray[(int) inputPhysicalButton] == ButtonDown)
        return true;
    else if (inputStatus == ButtonHold && physicalButtonStatusArray[(int) inputPhysicalButton] == ButtonHold)
        return true;
    else if (inputStatus == ButtonUntouched && physicalButtonStatusArray[(int) inputPhysicalButton] == ButtonUntouched)
        return true;
    else if (inputStatus == ButtonUp && physicalButtonStatusArray[(int) inputPhysicalButton] == ButtonUp)
        return true;
    else
        return false;
}

const Point2D& InputController::getMousePoint() const
{
    return mousePoint;
}

void InputController::handlePhysicalButton(const sf::Keyboard::Key& inputButton, const int& index)
{
    if (sf::Keyboard::isKeyPressed(inputButton))
    {
        //Key is currently DOWN according to SFML
        if (physicalButtonStatusArray[index] == ButtonUntouched)
        {
            physicalButtonDown.push(index);
            physicalButtonStatusArray[index] = ButtonDown;
        }
    } else
    {
        //Key is currently UP according to SFML
        if (physicalButtonStatusArray[index] == ButtonHold)
        {
            physicalButtonUp.push(index);
            physicalButtonStatusArray[index] = ButtonUp;
        }
    }
}

void InputController::handlePhysicalButton(const sf::Mouse::Button& inputButton, const int& index)
{
    if (sf::Mouse::isButtonPressed(inputButton))
    {
        //Key is currently DOWN according to SFML
        if (physicalButtonStatusArray[index] == ButtonUntouched)
        {
            physicalButtonDown.push(index);
            physicalButtonStatusArray[index] = ButtonDown;
        }
    } else
    {
        //Key is currently UP according to SFML
        if (physicalButtonStatusArray[index] == ButtonHold)
        {
            physicalButtonUp.push(index);
            physicalButtonStatusArray[index] = ButtonUp;
        }
    }
}

void InputController::handleLeftClick(const int& index)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        //left click is down
        if (physicalButtonStatusArray[index] == ButtonUntouched)
        {

            for (OnscreenButton* it : onscreenButtons)
            {
                if (it->mouseDown(mousePoint))
                {
                    onscreenButtonToClearTrigger.push(it);
                }
            }

            physicalButtonDown.push(index);
            physicalButtonStatusArray[index] = ButtonDown;

        } else if (physicalButtonStatusArray[index] == ButtonHold)
        {
            for (OnscreenButton* it : onscreenButtons)
            {
                it->mouseHold(mousePoint);
            }
        }
    } else
    {
        //left click is up
        if (physicalButtonStatusArray[index] == ButtonHold)
        {
            physicalButtonUp.push(index);
            physicalButtonStatusArray[index] = ButtonUp;

            for (OnscreenButton* it : onscreenButtons)
            {
                if (it->mouseUp(mousePoint))
                {
                    onscreenButtonToClearTrigger.push(it);
                }
            }
        }
    }
}

void InputController::addOnscreenButton(OnscreenButton* onscreenButtonToAdd)
{
    onscreenButtons.push_back(onscreenButtonToAdd);
    onscreenButtonToAdd->registerId(ID_ONSCREEN_BUTTON);
}

void InputController::removeOnscreenButton(OnscreenButton* onscreenButtonToRemove)
{
    for (unsigned int i = 0; i < onscreenButtons.size(); i++)
    {
        if (onscreenButtonToRemove->matches(onscreenButtons[i], ID_ONSCREEN_BUTTON))
        {
            onscreenButtons.erase(onscreenButtons.begin() + i);
            onscreenButtonToRemove->clearId(ID_ONSCREEN_BUTTON);
            return;
        }
    }
}

void InputController::setGraphicsWindow(Window* inputWindow)
{
    window = inputWindow;
}

std::string InputController::getStatusString() const
{
    return "N/A";
}


