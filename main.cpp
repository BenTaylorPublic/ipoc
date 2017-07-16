
#include "MasterController.h"
#include <iostream>

int main()
{

    MasterController masterController;     

    masterController.IPOCLoad();
    masterController.start();
    
    return 0;
}