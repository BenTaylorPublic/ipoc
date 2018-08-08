#include "Texture.h"
#include "Debug.h"
#include "Settings.h"

Texture::Texture(const std::string& inputName,
				 const std::string& fileName)
{
	name = inputName;
	if (!texture.loadFromFile(Settings::imageFilePath + fileName))
	{
		Debug::writeLine("[ERROR] SFML texture didn't load (" + inputName + ")");
		Debug::logLine("[ERROR] SFML texture didn't load (" + inputName + ")");
	} else
	{
		Debug::logLine("[INFO] Loaded texture (" + inputName + ")");
	}
	Debug::notifyOfConstruction(1);
}

Texture::~Texture()
{
	Debug::notifyOfDestruction(1);
}

const sf::Texture* Texture::getTexture() const
{
	return &texture;
}

std::string Texture::getStatusString() const
{
	return "Texture name=" + name;
}
