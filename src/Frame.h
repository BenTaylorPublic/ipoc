#pragma once

#include <string>
#include <vector>
#include "Drawable.h"
#include "View.h"
#include <SFML/Graphics.hpp>

class Frame
{
public:
	Frame();
	~Frame();
	void IPOCLoad();
	void markAsDrawable();
	bool isDrawable() const;
	void addToFrame(Drawable* drawable);
	void removeFromFrame(Drawable* drawable);
	void drawAll(sf::RenderTarget& target);
	void setViewPort(const unsigned int& viewIndex,
					 const float& topLeftX,
					 const float& topLeftY,
					 const float& sizeX,
					 const float& sizeY);
	std::string getStatusString() const;
private:
	std::vector<View*> views;
	bool isDrawableBool;
};