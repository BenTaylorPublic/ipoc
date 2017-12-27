
#include "Window.h"
#include "Debug.h"
#include "Settings.h"

Window::Window()
{
}

Window::~Window()
{
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
		temp += static_cast<char> (event.text.unicode);
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
    frame->drawAll(window);
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

const sf::RenderWindow* Window::getWindow() const
{
    return &window;
}

std::string Window::getStatusString() const
{
    return "N/A";
}