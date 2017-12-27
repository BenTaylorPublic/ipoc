
#pragma once

#include <string>
#include <vector>
#include "Drawable.h"
#include "Identifiable.h"
#include "Point2D.h"

enum OnscreenButtonType {
    TriggerOnUp = 0, TriggerOnDown = 1, TriggerOnHold = 2
};

class OnscreenButton : public Drawable {
public:
    OnscreenButton();
    OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType);
    OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType, const unsigned int& inputZ);
    OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType, const unsigned int& inputZ, const Point2D& point);
    ~OnscreenButton();
    void addToUp(Drawable* drawable, const Point2D& offsetFromTopLeft);
    void addToDown(Drawable* drawable, const Point2D& offsetFromTopLeft);
    void addToUp(Drawable* drawable);
    void addToDown(Drawable* drawable);
    void setHitBox(const Point2D& inputTopLeft, const Point2D& inputBottomRight);
    void setPosition(const Point2D& newPoint) override;
    bool mouseDown(const Point2D& mousePoint);
    void mouseHold(const Point2D& mousePoint);
    bool mouseUp(const Point2D& mousePoint);
    void setButtonTriggerType(const OnscreenButtonType& inputOnscreenButtonType);
    void clearTriggered();
    bool isTriggered() const;
    void draw(sf::RenderTarget& target) const override;
    std::string getStatusString() const;
private:
    bool triggered = false;
    bool stateUp = true;
    OnscreenButtonType onscreenButtonType;
    std::vector<Drawable*> stateUpDrawables;
    std::vector<Drawable*> stateDownDrawables;
    std::vector<Point2D> stateUpOffset;
    std::vector<Point2D> stateDownOffset;
    Point2D hitBoxTopLeft;
    Point2D hitBoxBottomRight;
    Point2D drawingPosition;
    bool isInside(const Point2D& point) const;
};