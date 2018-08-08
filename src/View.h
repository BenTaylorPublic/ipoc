#pragma once
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include <vector>

class View
{
public:
	View();
	~View();
	void IPOCLoad();
	void drawAllAtZ(const unsigned int& zIndex,
					sf::RenderTarget& target) const;
	void addDrawable(Drawable* drawable);
	void removeDrawable(Drawable* drawable);
	void setViewPort(const float& topLeftX,
					 const float& topLeftY,
					 const float& sizeX,
					 const float& sizeY);
private:
	sf::View view;
	std::vector<std::vector<Drawable*> > drawables;
};