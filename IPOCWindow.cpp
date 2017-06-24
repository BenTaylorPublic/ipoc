
#include "IPOCWindow.h"
#include "Debug.h"
#include "IPOCSettings.h"

IPOCWindow::IPOCWindow()
{
	Debug::notifyOfConstruction(9);
}

IPOCWindow::~IPOCWindow()
{
	Debug::notifyOfDestruction(9);	
}

void IPOCWindow::load()
{
	//nothing yet
}

void IPOCWindow::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode < 128)
			{
				std::string temp = "";
				temp += static_cast<char>(event.text.unicode);
				//Debug::write(&temp);
			}
		}
	}
}

void IPOCWindow::openWindow(const int& inputWindowXSize, const int& inputWindowYSize, const std::string& inputWindowName, const std::string& inputWindowType, const bool& hideCursor)
{
	if (inputWindowType == "borderless window")
	{
		window.create(sf::VideoMode(inputWindowXSize, inputWindowYSize), inputWindowName, sf::Style::None);
	} else if (inputWindowType == "windowed")
	{
		window.create(sf::VideoMode(inputWindowXSize, inputWindowYSize), inputWindowName, sf::Style::Default);
	} else if (inputWindowType == "fullscreen")
	{
		window.create(sf::VideoMode(inputWindowXSize, inputWindowYSize), inputWindowName, sf::Style::Fullscreen);
	}
	
	if (hideCursor)
		window.setMouseCursorVisible(false); // Hide cursor

	window.display();
}

void IPOCWindow::drawFrame(IPOCFrame* frame)
{
	frame->markStartOfDrawing();
	IPOCDrawable* drawable = frame->getNextDrawable();
	while (drawable != nullptr)
	{
		drawable->draw(window);
		drawable = frame->getNextDrawable();
	}
}

void IPOCWindow::renderWindow()
{
	window.display();
}

void IPOCWindow::clearWindow()
{
	window.clear();
}

void IPOCWindow::closeWindow()
{
	window.close();
}

sf::RenderWindow* IPOCWindow::getWindow()
{
	return &window;
}

std::string IPOCWindow::getStatusString()
{
	return "N/A";
}