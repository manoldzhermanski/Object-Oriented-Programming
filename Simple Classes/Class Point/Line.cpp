#include "Line.h"
#include <iostream>

bool Line::areParallel(const Point& A, const Point& B, const Point& C, const Point& D) {
	double a1 = B.y - A.y;
	double b1 = A.x - B.x;
	double c1 = a1 * (A.x) + b1 * (A.y);

	double a2 = D.y - C.y;
	double b2 = C.x - D.x;
	double c2 = a2 * (C.x) + b2 * (C.y);

	return  a1 * b2 - a2 * b1 == 0;
}

bool Line::isOnLine(const Point& A, const Point& B, const Point& C) {
	return (C.x - A.x) / (B.x - A.x) == (C.y - A.y) / (B.y - A.y);
}

void Line::intersection(const Point& A, const Point& B, const Point& C, const Point& D) {
	if (areParallel(A, B, C, D) == true) {
		std::cout << "Error: Parallel lines" << std::endl;
	}
	else {
		double a1 = B.y - A.y;
		double b1 = A.x - B.x;
		double c1 = a1 * (A.x) + b1 * (A.y);

		double a2 = D.y - C.y;
		double b2 = C.x - D.x;
		double c2 = a2 * (C.x) + b2 * (C.y);

		double x = (b2 * c1 - b1 * c2) / (a1 * b2 - a2 * b1);
		double y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);

		std::cout << "(" << x << "," << y << ")" << std::endl;
	}
}

