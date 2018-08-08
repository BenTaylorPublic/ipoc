#include "MasterController.h"
#include <iostream>

int main()
{

	MasterController masterController;

	masterController.IPOCLoad();
	masterController.start();

	std::cout << "END OF LINE\n";
	return 0;
}