#include <iostream>
#include <memory>
#include "GameManager.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<GameManager> manager = std::make_unique<GameManager>();
	bool status = manager->OnCreate();
	if (status == true) {
		manager->Run();
	}
	else {
		std::cerr << "Fatal Error Occured. Cannot start this program" << std::endl;
	}

	return 0;
}
