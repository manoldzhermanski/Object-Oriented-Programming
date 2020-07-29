#include "Planet.h"
#include <iostream>

int main() {
	
	Planet test[2];
	createArray(test,2);
	printArray(test,2);
	std::cout<< biggestDiameter(test, 2);
	
	return 0;
}
