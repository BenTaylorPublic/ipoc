
#pragma once

#include <string>
#include <vector>
#include "Drawable.h"
#include "Point2D.h"

enum OnscreenButtonType
{
    TriggerOnUp = 0, TriggerOnDown = 1, TriggerOnHold = 2
};

class OnscreenButton : public Drawable
{
public:
    OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType);
    OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType, const int& inputZ);
    OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType, const int& inputZ, const Point2D& point);
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
    void setOnscreenButtonManagerId(const int& newId);
    int& getOnscreenButtonManagerId();
    void clearTriggered();
    bool isTriggered();
    void draw(sf::RenderTarget& target) override;
    std::string getStatusString();
private:
    bool triggered = false;
    bool stateUp = true;
    int onscreenButtonManagerId = -1;
    OnscreenButtonType onscreenButtonType;
    vector<Drawable*> stateUpDrawables;
    vector<Drawable*> stateDownDrawables;
    vector<Point2D> stateUpOffset;
    vector<Point2D> stateDownOffset;
    Point2D hitBoxTopLeft;
    Point2D hitBoxBottomRight;
    Point2D drawingPosition;
    bool isInside(const Point2D& point);
};