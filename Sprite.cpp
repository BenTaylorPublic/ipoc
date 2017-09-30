#include "Sprite.h"
#include "Debug.h"
#include "Settings.h"

Sprite::Sprite()
{
    setZ(DEFAULT_Z_VALUE);
    Debug::notifyOfConstruction(3);
}

Sprite::Sprite(Texture& inputTexture)
{
    setZ(DEFAULT_Z_VALUE);
    sprite.setTexture(*inputTexture.getTexture());
    Debug::notifyOfConstruction(3);
}

Sprite::Sprite(Texture& inputTexture, const unsigned int& inputZ)
{
    setZ(inputZ);
    sprite.setTexture(*inputTexture.getTexture());
    Debug::notifyOfConstruction(3);
}

Sprite::~Sprite()
{
    Debug::notifyOfDestruction(3);
}

void Sprite::setTexture(Texture& inputTexture)
{
    sprite.setTexture(*inputTexture.getTexture());
}

void Sprite::setPosition(const Point2D& newPoint)
{
    sprite.setPosition(sf::Vector2f(newPoint.x, newPoint.y));
}

Point2D Sprite::getPosition()
{
    Point2D result;
    result.x = sprite.getPosition().x;
    result.y = sprite.getPosition().y;
    return result;
}

int Sprite::getWidth()
{
    return sprite.getGlobalBounds().width;
}

int Sprite::getHeight()
{
    return sprite.getGlobalBounds().height;
}

void Sprite::draw(sf::RenderTarget& target)
{
    target.draw(sprite);
}

std::string Sprite::getStatusString()
{
    return "N/A";
}
