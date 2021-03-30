#include "Rational.h"
#include <iostream>

int main() {

	Rational test(1,2);
	Rational test2(1, 3);
	std::cout << (test2 <= test);
}