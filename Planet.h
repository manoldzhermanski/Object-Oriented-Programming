#pragma once
#include <iostream>
#include <string>

struct Planet
{
	std::string name;
	double distanceToSun;
	double mass;
	double radius;

	void init() {
		std::cin >> name;
		std::cin >> distanceToSun;
		std::cin >> radius;
		std::cin >> mass;
	}

	void print() {
		std::cout << "Name : " << name << std::endl;
		std::cout << "Distance to the Sun : " << distanceToSun << std::endl;
		std::cout << "Radius : " << radius << std::endl;
		std::cout << "Mass : " << mass << std::endl;
		
	}

	double neededSeconds() {
		return distanceToSun / 299792;
	}

};

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

unsigned biggestDiameter(Planet* arr, unsigned size) {
	Planet biggestDiam;
	double result = 0;
	for (unsigned i = 0; i < size; i++) {
		if (arr[i].radius * 2 > result) {
			biggestDiam = arr[i];
			result = arr[i].radius * 2;
		}
	}
	
	biggestDiam.print();
	return result;
}