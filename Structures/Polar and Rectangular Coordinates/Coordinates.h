#pragma once
#include <iostream>
#include <cmath>

const double PI = 3.14159265;

	struct Polar {
		double r;
		double degree;

		void init() {
			std::cin >> r >> degree;
		}

		void print() {
			std::cout << "(" << r << "," << degree << ")" << std::endl;
		}
};

	struct Rect {
		double x;
		double y;

		void init() {
			std::cin >> x >> y;
		}

		void print() {
			std::cout << "(" << x << "," << y << ")" << std::endl;
		}
	};

	Rect polarToRect( Polar p) {
		Rect temp;
		temp.x = p.r * cos(p.degree * PI / 180.0);
		temp.y = p.r * sin(p.degree * PI / 180.0);

		return temp;

	}

	Polar rectToPolar(Rect q) {
		Polar temp;
		temp.r = sqrt(q.x * q.x + q.y * q.y);
		temp.degree = acos(q.x / temp.r) * 180 / PI;

		return temp;
	}
