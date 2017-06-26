#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "Frame.h"
#include "Color.h"
#include <vector>

class IPOCWindow
{
public:
    IPOCWindow();
    ~IPOCWindow();
    void load();
    void handleEvents();
    void openWindow(const int& inputWindowXSize, const int& inputWindowYSize, const std::string& inputWindowName, const std::string& inputWindowType, const bool& hideCursor);
    void drawFrame(Frame* frame);
    void renderWindow();
    void clearWindow();
    void closeWindow();
    sf::RenderWindow* getWindow();
    std::string getStatusString();
private:
    sf::RenderWindow window;

};