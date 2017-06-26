#include "IPOCTexture.h"
#include "Debug.h"
#include "Settings.h"

IPOCTexture::IPOCTexture(const std::string& inputName, const std::string& fileName)
{
	name = inputName;
	if (!texture.loadFromFile(Settings::imageFilePath + fileName))
	{
		Debug::write("[ERROR] SFML texture didn't load (");
		Debug::write(inputName);
		Debug::write(")\n");
		Debug::log("[ERROR] SFML texture didn't load (");
		Debug::log(inputName);
		Debug::log(")");
		Debug::commitLogLine();
	}
	else
	{
		Debug::log("[INFO] Loaded texture (");
		Debug::log(inputName);
		Debug::log(")");
		Debug::commitLogLine();
	}
	Debug::notifyOfConstruction(15);	
}

IPOCTexture::~IPOCTexture()
{
	Debug::notifyOfDestruction(15);
}

sf::Texture* IPOCTexture::getTexture()
{
	return &texture;
}

std::string IPOCTexture::getStatusString()
{
	return "Texture name=" + name;
}
