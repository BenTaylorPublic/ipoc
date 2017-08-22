#include "Font.h"
#include "Debug.h"
#include "Settings.h"

Font::Font(const std::string& inputName, const std::string& fileName)
{
    name = inputName;

    if (!font.loadFromFile(Settings::fontFilePath + fileName))
    {
	Debug::writeLine("[ERROR] SFML font didn't load (" + name + ")");
	Debug::logLine("[ERROR] SFML font didn't load (" + name + ")");
    } else
    {
	Debug::logLine("[INFO] Loaded font (" + name + ")");
    }

    Debug::notifyOfConstruction(13);
}

Font::~Font()
{
    Debug::notifyOfDestruction(13);
}

sf::Font* Font::getFont()
{
    return &font;
}

std::string Font::getStatusString()
{
    return "Font name=" + name;
}
