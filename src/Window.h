#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "Frame.h"
#include "Color.h"
#include <vector>

class Window
{
public:
	Window();
	~Window();
	void load();
	void handleEvents();
	void openWindow(const int& inputWindowXSize,
					const int& inputWindowYSize,
					const std::string& inputWindowName,
					const std::string& inputWindowType,
					const bool& hideCursor);
	void drawFrame(Frame* frame);
	void renderWindow();
	void clearWindow();
	void closeWindow();
	const sf::RenderWindow* getWindow() const;
	std::string getStatusString() const;
private:
	sf::RenderWindow window;

};