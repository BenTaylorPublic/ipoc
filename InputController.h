#pragma once
#include <string>
#include "IPOCWindow.h"
#include "InputEnums.h"
#include "Point2D.h"
#include <SFML/Graphics.hpp>
#include <queue>

class InputController
{
public:
    InputController();
    ~InputController();
    void IPOCLoad();
    bool getKeyboardStatus(const Key& inputKey, const ButtonStatus& inputStatus);
    bool getMouseStatus(const Mouse& inputButton, const ButtonStatus& inputStatus);
    const Point2D& getMousePoint();
    void setGraphicsWindow(IPOCWindow* inputWindow);
    void input();
    void markStartOfLoop(); //Used to mark ButtonDown to ButtonHold, and ButtonUp to ButtonUntouched
    void markEndOfLoop(); //Used to mark ButtonDown to ButtonHold, and ButtonUp to ButtonUntouched
    std::string getStatusString();
private:
    void handleKey(const sf::Keyboard::Key& inputKey, const int& index);
    void handleMouseButton(const sf::Mouse::Button& inputMouse, const int& index);
    Point2D mousePoint;
    void resetInputArrays();
    ButtonStatus inputKeyboardArray[98];
    ButtonStatus inputMouseArray[3];
    queue<int> buttonDownKeyboard; //Used to mark ButtonDown to ButtonHold
    queue<int> buttonDownMouse; //Used to mark ButtonDown to ButtonHold
    queue<int> buttonUpKeyboard; //Used to mark ButtonUp to ButtonUntouched
    queue<int> buttonUpMouse; //Used to mark ButtonUp to ButtonUntouched
    
    IPOCWindow* window; //Needed for mouse location relative to window
};