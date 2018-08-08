#pragma once

#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Point2D.h"
#include "Color.h"

class Line : public Drawable
{
public:
	Line();
	~Line();
	void draw(sf::RenderTarget& target) const override;
	void setPosition(const Point2D& newPoint) override;
	void setPosition2(const Point2D& newPoint);
	void setColor(const Color& color);
private:
	sf::Vertex line[2];
};