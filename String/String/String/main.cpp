#include "String.h"
#include <iostream>

int main() {
	String test(7,"Moncho");
	String test2(7, "00000000");
	
	std:: cout << (test != test2);

	return 0;
}