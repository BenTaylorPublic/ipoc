#pragma once
#include <string>
#include "Window.h"
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
    bool getKeyboardStatus(const PhysicalButton& inputKey, const ButtonStatus& inputStatus);
    bool getMouseStatus(const Mouse& inputButton, const ButtonStatus& inputStatus);
    const Point2D& getMousePoint();
    void setGraphicsWindow(Window* inputWindow);
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
    std::queue<int> buttonDownKeyboard; //Used to mark ButtonDown to ButtonHold
    std::queue<int> buttonDownMouse; //Used to mark ButtonDown to ButtonHold
    std::queue<int> buttonUpKeyboard; //Used to mark ButtonUp to ButtonUntouched
    std::queue<int> buttonUpMouse; //Used to mark ButtonUp to ButtonUntouched
    
    Window* window; //Needed for mouse location relative to window
};