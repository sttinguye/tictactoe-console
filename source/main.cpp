// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include <stdexcept> // for catching exceptions
// Add more standard header files as required
// #include <string>

// Add your project's header files here
 #include "CGame.h"

// Main program
int main ()
{
	std::cout << "ASDT_Lab01_TrungTinNguyen_1120436 started." << '\n';

	try
	{
		CGame game1;

		if (CGlobal::RC_SUCCESS != game1.run())
		{
			std::cerr << "Something goes wrong...\nClosing the Game Center...\nPlease RUN!!\n";
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception caught in main(): " << ex.what() << std::endl;
	}

	return 0;
}
