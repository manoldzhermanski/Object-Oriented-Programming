#include "Planet.h"
#include <iostream>

int main() {
	Planet p;
	p.init();
	p.print();
	neededSeconds(p);

	Planet test[2];
	createArray(test,2);
	printArray(test,2);
	biggestDiameter(test, 2);
	
	return 0;
}
