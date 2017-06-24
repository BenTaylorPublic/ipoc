#include "IPOCFont.h"
#include "Debug.h"
#include "IPOCSettings.h"

IPOCFont::IPOCFont(const std::string& inputName, const std::string& fileName)
{
	name = inputName;

	if (!font.loadFromFile(IPOCSettings::fontFilePath + fileName))
	{
		Debug::write("[ERROR] SFML font didn't load (");
		Debug::write(name);
		Debug::write(")\n");
		Debug::log("[ERROR] SFML font didn't load (");
		Debug::log(name);
		Debug::log(")");
		Debug::commitLogLine();
	}
	else
	{
		Debug::log("[INFO] Loaded font (");
		Debug::log(name);
		Debug::log(")");
		Debug::commitLogLine();		
	}
	
	Debug::notifyOfConstruction(13);
}

IPOCFont::~IPOCFont()
{
	Debug::notifyOfDestruction(13);	
}

 sf::Font* IPOCFont::getFont()
 {
	 return &font;
 }

std::string IPOCFont::getStatusString()
{
	return "Font name=" + name;
}
