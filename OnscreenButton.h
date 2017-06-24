
#pragma once

#include <string>
#include <vector>
#include "IPOCDrawable.h"
#include "Point2D.h"

enum OnscreenButtonType
{
    TriggerOnUp = 0, TriggerOnDown = 1, TriggerOnHold = 2
};

class OnscreenButton : public IPOCDrawable
{
public:
    OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType);
    OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType, const int& inputZ);
    OnscreenButton(const OnscreenButtonType& inputOnscreenButtonType, const int& inputZ, const Point2D& point);
    ~OnscreenButton();
    void addToUp(IPOCDrawable* drawable, const Point2D& offsetFromTopLeft);
    void addToDown(IPOCDrawable* drawable, const Point2D& offsetFromTopLeft);
    void addToUp(IPOCDrawable* drawable);
    void addToDown(IPOCDrawable* drawable);
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
    vector<IPOCDrawable*> stateUpDrawables;
    vector<IPOCDrawable*> stateDownDrawables;
    vector<Point2D> stateUpOffset;
    vector<Point2D> stateDownOffset;
    Point2D hitBoxTopLeft;
    Point2D hitBoxBottomRight;
    Point2D drawingPosition;
    bool isInside(const Point2D& point);
};