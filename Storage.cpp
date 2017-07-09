#include "Debug.h"
#include "Storage.h"
#include "Settings.h"

Storage::Storage()
{
    Debug::notifyOfConstruction(8);
}

Storage::~Storage()
{
    Debug::notifyOfDestruction(8);
}

std::string Storage::getStatusString()
{
    return "N/A";
}
