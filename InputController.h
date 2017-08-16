#pragma once
#include <string>
#include "Window.h"
#include "InputEnums.h"
#include "Point2D.h"
#include <SFML/Graphics.hpp>
#include <queue>

class InputController {
public:
    InputController();
    ~InputController();
    void IPOCLoad();
    bool getPhysicalButtonStatus(const PhysicalButton& inputPhysicalButton, const ButtonStatus& inputStatus);
    const Point2D& getMousePoint();
    void setGraphicsWindow(Window* inputWindow);
    void input();
    void markStartOfLoop(); //Used to mark ButtonDown to ButtonHold, and ButtonUp to ButtonUntouched
    void markEndOfLoop(); //Used to mark ButtonDown to ButtonHold, and ButtonUp to ButtonUntouched
    std::string getStatusString();
private:
    void handlePhysicalButton(const sf::Keyboard::Key& inputButton, const int& index);
    void handlePhysicalButton(const sf::Mouse::Button& inputButton, const int& index);
    Point2D mousePoint;
    void resetInputArrays();
    ButtonStatus physicalButtonStatusArray[AMOUNT_OF_PHYSICAL_BUTTONS];
    std::queue<int> physicalButtonDown; //Used to mark ButtonDown to ButtonHold
    std::queue<int> physicalButtonUp; //Used to mark ButtonUp to ButtonUntouched

    Window* window; //Needed for mouse location relative to window
};