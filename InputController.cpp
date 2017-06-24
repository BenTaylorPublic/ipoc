#include "InputController.h"
#include "Debug.h"
#include "Conversions.h"

InputController::InputController()
{
	Debug::notifyOfConstruction(1);
}

InputController::~InputController()
{
	Debug::notifyOfDestruction(1);
}

void InputController::IPOCLoad()
{
	resetInputArrays();
	window = nullptr;
}

void InputController::input()
{
	#pragma region "Letters"
	handleKey(sf::Keyboard::A, 0);
	handleKey(sf::Keyboard::B, 1);
	handleKey(sf::Keyboard::C, 2);
	handleKey(sf::Keyboard::D, 3);
	handleKey(sf::Keyboard::E, 4);
	handleKey(sf::Keyboard::F, 5);
	handleKey(sf::Keyboard::G, 6);
	handleKey(sf::Keyboard::H, 7);
	handleKey(sf::Keyboard::I, 8);
	handleKey(sf::Keyboard::J, 9);
	handleKey(sf::Keyboard::K, 10);
	handleKey(sf::Keyboard::L, 11);
	handleKey(sf::Keyboard::M, 12);
	handleKey(sf::Keyboard::N, 13);
	handleKey(sf::Keyboard::O, 14);
	handleKey(sf::Keyboard::P, 15);
	handleKey(sf::Keyboard::Q, 16);
	handleKey(sf::Keyboard::R, 17);
	handleKey(sf::Keyboard::S, 18);
	handleKey(sf::Keyboard::T, 19);
	handleKey(sf::Keyboard::U, 20);
	handleKey(sf::Keyboard::V, 21);
	handleKey(sf::Keyboard::W, 22);
	handleKey(sf::Keyboard::X, 23);
	handleKey(sf::Keyboard::Y, 24);
	handleKey(sf::Keyboard::Z, 25);
	#pragma endregion

	#pragma region "Numbers"
	handleKey(sf::Keyboard::Num0, 26);
	handleKey(sf::Keyboard::Num1, 27);
	handleKey(sf::Keyboard::Num2, 28);
	handleKey(sf::Keyboard::Num3, 29);
	handleKey(sf::Keyboard::Num4, 30);
	handleKey(sf::Keyboard::Num5, 31);
	handleKey(sf::Keyboard::Num6, 32);
	handleKey(sf::Keyboard::Num7, 33);
	handleKey(sf::Keyboard::Num8, 34);
	handleKey(sf::Keyboard::Num9, 35);
	#pragma endregion

	#pragma region "Numpad"
	handleKey(sf::Keyboard::Numpad0, 36);
	handleKey(sf::Keyboard::Numpad1, 37);
	handleKey(sf::Keyboard::Numpad2, 38);
	handleKey(sf::Keyboard::Numpad3, 39);
	handleKey(sf::Keyboard::Numpad4, 40);
	handleKey(sf::Keyboard::Numpad5, 41);
	handleKey(sf::Keyboard::Numpad6, 42);
	handleKey(sf::Keyboard::Numpad7, 43);
	handleKey(sf::Keyboard::Numpad8, 44);
	handleKey(sf::Keyboard::Numpad9, 45);
	#pragma endregion

	#pragma region "Arrows"
	handleKey(sf::Keyboard::Left, 46);
	handleKey(sf::Keyboard::Right, 47);
	handleKey(sf::Keyboard::Up, 48);
	handleKey(sf::Keyboard::Down, 49);
	#pragma endregion

	#pragma region "F keys"
	handleKey(sf::Keyboard::F1, 50);
	handleKey(sf::Keyboard::F2, 51);
	handleKey(sf::Keyboard::F3, 52);
	handleKey(sf::Keyboard::F4, 53);
	handleKey(sf::Keyboard::F5, 54);
	handleKey(sf::Keyboard::F6, 55);
	handleKey(sf::Keyboard::F7, 56);
	handleKey(sf::Keyboard::F8, 57);
	handleKey(sf::Keyboard::F9, 58);
	handleKey(sf::Keyboard::F10, 59);
	handleKey(sf::Keyboard::F11, 60);
	handleKey(sf::Keyboard::F12, 61);
	#pragma endregion

	#pragma region "Maths"
	handleKey(sf::Keyboard::Add, 62);
	handleKey(sf::Keyboard::Subtract, 63);
	handleKey(sf::Keyboard::Divide, 64);
	handleKey(sf::Keyboard::Multiply, 65);
	#pragma endregion

	#pragma region "Other keys"
	//Row 1
	handleKey(sf::Keyboard::Escape, 66);
	handleKey(sf::Keyboard::BackSlash, 67);
	handleKey(sf::Keyboard::BackSpace, 68);
	handleKey(sf::Keyboard::Comma, 69);
	handleKey(sf::Keyboard::Dash, 70);
	handleKey(sf::Keyboard::Delete, 71);
	handleKey(sf::Keyboard::Equal, 72);
	handleKey(sf::Keyboard::Home, 73);
	handleKey(sf::Keyboard::Insert, 74);
	//Row 2
	handleKey(sf::Keyboard::LAlt, 75);
	handleKey(sf::Keyboard::LBracket, 76);
	handleKey(sf::Keyboard::LControl, 77);
	handleKey(sf::Keyboard::LShift, 78);
	handleKey(sf::Keyboard::LSystem, 79);
	handleKey(sf::Keyboard::Menu, 80);
	handleKey(sf::Keyboard::PageUp, 81);
	handleKey(sf::Keyboard::PageDown, 82);
	handleKey(sf::Keyboard::Pause, 83);
	handleKey(sf::Keyboard::Period, 84);
	handleKey(sf::Keyboard::Quote, 85);
	//Row 3
	handleKey(sf::Keyboard::RAlt, 86);
	handleKey(sf::Keyboard::RBracket, 87);
	handleKey(sf::Keyboard::RControl, 88);
	handleKey(sf::Keyboard::Return, 89);
	handleKey(sf::Keyboard::RShift, 90);
	handleKey(sf::Keyboard::RSystem, 91);
	handleKey(sf::Keyboard::SemiColon, 92);
	handleKey(sf::Keyboard::Slash, 93);
	handleKey(sf::Keyboard::Space, 94);
	handleKey(sf::Keyboard::Tab, 95);
	handleKey(sf::Keyboard::Tilde, 96);
	handleKey(sf::Keyboard::End, 97);
	#pragma endregion

	//Mouse
	#pragma region "Buttons"
	handleMouseButton(sf::Mouse::Left, 0);
	handleMouseButton(sf::Mouse::Middle, 1);
	handleMouseButton(sf::Mouse::Right, 2);
	#pragma endregion

	#pragma region "Mouse point"
		sf::Vector2i windowPosition = sf::Mouse::getPosition(*window->getWindow());
		mousePoint.x = windowPosition.x;
		mousePoint.y = windowPosition.y;
	#pragma endregion 

}

void InputController::resetInputArrays()
{
	for (int i = 0; i < 98; i++)
		inputKeyboardArray[i] = ButtonUntouched;
	for (int i = 0; i < 3; i++)
		inputMouseArray[i] = ButtonUntouched;
}

void InputController::markStartOfLoop()
{
	buttonDownKeyboard.push(-1);
	buttonDownMouse.push(-1);
	buttonUpKeyboard.push(-1);
	buttonUpMouse.push(-1);
}

void InputController::markEndOfLoop()
{
	int currentIndex = -1;
	
	//Down to hold
	//Keyboard Down to hold
	do
	{
		currentIndex = buttonDownKeyboard.front();
		buttonDownKeyboard.pop();
		
		if (currentIndex == -1) //Escape character
			break;
		else
		{
			inputKeyboardArray[currentIndex] = ButtonHold;
		}
	}
	while(true);
	
	//Mouse Down to hold
	do
	{
		currentIndex = buttonDownMouse.front();
		buttonDownMouse.pop();
		
		if (currentIndex == -1) //Escape character
			break;
		else
		{
			inputMouseArray[currentIndex] = ButtonHold;
		}
	}
	while(true);
	
	//Up to Untouched
	//Keyboard Up to Untouched
	do
	{
		currentIndex = buttonUpKeyboard.front();
		buttonUpKeyboard.pop();
		
		if (currentIndex == -1) //Escape character
			break;
		else
		{
			inputKeyboardArray[currentIndex] = ButtonUntouched;
		}
	}
	while(true);
	
	//Mouse Down to hold
	do
	{
		currentIndex = buttonUpMouse.front();
		buttonUpMouse.pop();
		
		if (currentIndex == -1) //Escape character
			break;
		else
		{
			inputMouseArray[currentIndex] = ButtonUntouched;
		}
	}
	while(true);
}

bool InputController::getKeyboardStatus(const Key& inputKey, const ButtonStatus& inputStatus)
{
	if ((inputStatus == ButtonDown || inputStatus==ButtonHold)  && inputKeyboardArray[(int)inputKey] == ButtonDown)
		return true;
	else if (inputStatus == ButtonHold && inputKeyboardArray[(int)inputKey] == ButtonHold)
		return true;
	else if (inputStatus == ButtonUntouched && inputKeyboardArray[(int)inputKey] == ButtonUntouched)
		return true;
	else if (inputStatus == ButtonUp && inputKeyboardArray[(int)inputKey] == ButtonUp)
		return true;
	else
		return false;
}

bool InputController::getMouseStatus(const Mouse& inputButton, const ButtonStatus& inputStatus)
{
	if ((inputStatus == ButtonDown || inputStatus == ButtonHold) && inputMouseArray[(int)inputButton] == ButtonDown)
		return true;
	else if (inputStatus == ButtonHold && inputMouseArray[(int)inputButton] == ButtonHold)
		return true;
	else if (inputStatus == ButtonUntouched && inputMouseArray[(int)inputButton] == ButtonUntouched)
		return true;
	else if (inputStatus == ButtonUp && inputMouseArray[(int)inputButton] == ButtonUp)
		return true;
	else
		return false;
}

const Point2D& InputController::getMousePoint()
{
	return mousePoint;
}

void InputController::handleKey(const sf::Keyboard::Key& inputKey, const int& index)
{
	if (sf::Keyboard::isKeyPressed(inputKey))
	{
		//Key is currently DOWN according to SFML
		if (inputKeyboardArray[index] == ButtonUntouched)
		{
			buttonDownKeyboard.push(index);
			inputKeyboardArray[index] = ButtonDown;
		}
	}
	else 
	{
		//Key is currently UP according to SFML
		if (inputKeyboardArray[index] == ButtonHold)
		{
			buttonUpKeyboard.push(index);
			inputKeyboardArray[index] = ButtonUp;
		}
	}	
}

void InputController::handleMouseButton(const sf::Mouse::Button& inputButton, const int& index)
{
	if (sf::Mouse::isButtonPressed(inputButton))
	{
		//Button is currently DOWN according to SFML
		if (inputMouseArray[index] == ButtonUntouched)
		{
			buttonDownMouse.push(index);
			inputMouseArray[index] = ButtonDown;
		}
	}
	else 
	{
		//Button is currently UP according to SFML
		if (inputMouseArray[index] == ButtonHold)
		{
			buttonUpMouse.push(index);
			inputMouseArray[index] = ButtonUp;
		}
	}	
}

void InputController::setGraphicsWindow(IPOCWindow* inputWindow)
{
	window = inputWindow;
}

std::string InputController::getStatusString()
{
	return "N/A";
}


