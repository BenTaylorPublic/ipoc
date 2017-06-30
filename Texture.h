#pragma once

#include <string>
#include <SFML/Graphics.hpp>

/*
IPOCTexture is a Data Type (Wrapper)
*/
class Texture
{
public:
    Texture(const std::string& inputName, const std::string& fileName);
    ~Texture();
    std::string name; //Name that is mainly used for debugging
    sf::Texture* getTexture(); //Should strictly be used for creating new Sprite objects. AKA don't use this you fuck
    /*
    Returns a string indicating this object's current status, and all objects it manages.
    Should only be used for debugging, but not strictly.
    */
    std::string getStatusString();
private:
    sf::Texture texture; //SFML Texture object that this class wraps
};