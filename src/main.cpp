#include "MasterController.h"
#include <iostream>
/*! \mainpage Welcome to IPOC Documentation
	Not sure what to show here yet
 */
int main()
{

	MasterController masterController;

	masterController.IPOCLoad();
	masterController.start();

	std::cout << "END OF LINE\n";
	return 0;
}