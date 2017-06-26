#include "Font.h"
#include "Debug.h"
#include "Settings.h"

Font::Font(const std::string& inputName, const std::string& fileName)
{
	name = inputName;

	if (!font.loadFromFile(Settings::fontFilePath + fileName))
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
