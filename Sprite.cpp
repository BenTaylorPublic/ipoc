#include "Sprite.h"
#include "Debug.h"
#include "Settings.h"

Sprite::Sprite()
{
    name = "";
    setZ(DEFAULT_Z_VALUE);
    Debug::notifyOfConstruction(3);
}

Sprite::Sprite(const std::string& inputName)
{
    name = inputName;
    setZ(DEFAULT_Z_VALUE);
    Debug::notifyOfConstruction(3);
}

Sprite::Sprite(const std::string& inputName, Texture& inputTexture)
{
    name = inputName;
    setZ(DEFAULT_Z_VALUE);
    sprite.setTexture(*inputTexture.getTexture());
    Debug::notifyOfConstruction(3);
}

Sprite::Sprite(const std::string& inputName, Texture& inputTexture, const unsigned int& inputZ)
{
    name = inputName;
    setZ(inputZ);
    sprite.setTexture(*inputTexture.getTexture());
    Debug::notifyOfConstruction(3);
}

Sprite::Sprite(Texture& inputTexture)
{
    name = "";
    setZ(DEFAULT_Z_VALUE);
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
    return "Sprite name=" + name;
}
