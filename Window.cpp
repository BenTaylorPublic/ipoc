
#include "Window.h"
#include "Debug.h"
#include "Settings.h"

Window::Window()
{
	Debug::notifyOfConstruction(9);
}

Window::~Window()
{
	Debug::notifyOfDestruction(9);	
}

void Window::load()
{
	//nothing yet
}

void Window::handleEvents()
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

void Window::openWindow(const int& inputWindowXSize, const int& inputWindowYSize, const std::string& inputWindowName, const std::string& inputWindowType, const bool& hideCursor)
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

void Window::drawFrame(Frame* frame)
{
	frame->markStartOfDrawing();
	Drawable* drawable = frame->getNextDrawable();
	while (drawable != nullptr)
	{
		drawable->draw(window);
		drawable = frame->getNextDrawable();
	}
}

void Window::renderWindow()
{
	window.display();
}

void Window::clearWindow()
{
	window.clear();
}

void Window::closeWindow()
{
	window.close();
}

sf::RenderWindow* Window::getWindow()
{
	return &window;
}

std::string Window::getStatusString()
{
	return "N/A";
}