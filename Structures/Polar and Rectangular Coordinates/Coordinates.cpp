#include "Coordinates.h"
#include <iostream>
#include <cmath>
int main() {
	
	Polar p, p1;
	Rect q, q1;
	p.init();

	q1 = polarToRect(p);
	q1.print();

	q.init();
	p1 = rectToPolar(q);
	p1.print();

}

