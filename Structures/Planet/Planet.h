#pragma once
#include <iostream>
#include <string>

struct Planet
{
	std::string name;
	double distanceToSun;
	double mass;
	double diameter;

	void init() {
		std::cin >> name;
		std::cin >> distanceToSun;
		std::cin >> diameter;
		std::cin >> mass;
	}

	void print() {
		std::cout << "Name : " << name << std::endl;
		std::cout << "Distance to the Sun : " << distanceToSun << std::endl;
		std::cout << "Diameter : " << diameter << std::endl;
		std::cout << "Mass : " << mass << std::endl;

	}

};

double neededSeconds(Planet p) {
	return p.distanceToSun / 299792;
}

void createArray(Planet* arr, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		arr[i].init();
	}
}

void printArray(Planet* arr, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		arr[i].print();
	}
}

void biggestDiameter(Planet* arr, unsigned size) {
	Planet biggestDiam;
	for (unsigned i = 0; i < size - 1; i++) {
		if (arr[i].diameter > arr[i + 1].diameter) {
			biggestDiam = arr[i];
		}
	}

	biggestDiam.print();
}
