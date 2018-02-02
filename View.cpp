#include "View.h"
#include "Settings.h"
#include "Debug.h"

View::View()
{
    view = sf::View(sf::FloatRect(0, 0, 1920, 1080));
    Debug::notifyOfConstruction(13);
}

View::~View()
{
    Debug::notifyOfDestruction(13);
}

void View::IPOCLoad()
{
    std::vector<Drawable*> toAdd;
    for (unsigned int i = 0; i < HIGHEST_Z_INDEX; i++)
    {
        drawables.push_back(toAdd);
    }
}

void View::drawAllAtZ(const unsigned int& zIndex, sf::RenderTarget& target) const
{
    target.setView(view);
    for (unsigned int i = 0; i < drawables.at(zIndex).size(); i++)
    {
        drawables.at(zIndex).at(i)->draw(target);
    }
}

void View::addDrawable(Drawable* drawable)
{
    drawables.at(drawable->getZIndex()).push_back(drawable);
    drawable->registerId(ID_DRAWABLE);
}

void View::removeDrawable(Drawable* drawable)
{
    unsigned int zIndex = drawable->getZIndex();

    for (unsigned int i = 0; i < drawables.at(zIndex).size(); i++)
    {
        if (drawables.at(zIndex).at(i)->matches(drawable, ID_DRAWABLE))
        {
            drawables.at(zIndex).erase(drawables.at(zIndex).begin() + i);
            drawable->clearId(ID_DRAWABLE);
            return;
        }
    }
}

void View::setViewPort(const float& topLeftX, const float& topLeftY, const float& sizeX, const float& sizeY)
{
    view.setViewport(sf::FloatRect(topLeftX, topLeftY, sizeX, sizeY));
}