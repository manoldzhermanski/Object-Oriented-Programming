#pragma once
#include <iostream>
struct Point {
	double x;
	double y;
};

void initPoint(Point* arr, unsigned size) {
	
	for (unsigned i = 0; i < size; i++) {
		std::cin >> arr[i].x >> arr[i].y;
	}
}

bool compare(int fst, int snd) {
	char fstarr[15];
	int i = 0;
	while (fst) {
		fstarr[i++] = fst % 10;
		fst /= 10;
	}
	char sndarr[15];
	int j = 0;
	while (snd) {
		sndarr[j++] = snd % 10;
		snd /= 10;
	}
	bool are_sorted = true;
	for (unsigned i = 0; i < 15; i++) {
		if (fstarr[i] > sndarr[i]) {
			are_sorted = false;
		}
	}
	return are_sorted;
}

void sortPoints(Point* arr, unsigned size) {
	for (unsigned i = 0; i < size - 1; i++) {
		if ( compare(arr[i].x,arr[i+1].x) == false && compare(arr[i].y,arr[i+1].y)== false) {
			Point temp;
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}
}

void printPoint(Point* arr, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		std::cout << "( " << arr[i].x << " , " << arr[i].y << " )" << std::endl;
	}
}


