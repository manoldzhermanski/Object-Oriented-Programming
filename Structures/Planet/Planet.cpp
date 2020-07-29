#include "Planet.h"
#include <iostream>

int main() {
	Planet p;
	p.init();
	p.print();
	std::cout << neededSeconds(p) << std::endl;

	Planet test[2];
	createArray(test,2);
	printArray(test,2);
	std::cout<< biggestDiameter(test, 2) << std::endl;
	
	return 0;
}
