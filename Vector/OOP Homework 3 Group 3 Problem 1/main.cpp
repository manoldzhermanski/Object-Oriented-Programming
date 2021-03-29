#include "Vector.h"
#include <iostream>

int main() {
	Vector<int> test(5);
	test.push_back(5);
	test.push_back(5);
	test.push_back(2);
	Vector<int> test2(5);
	test2.push_front(5);
	test2.push_front(4);
	test2.push_front(7);
	test-= test2;
	std::cout << test;
}