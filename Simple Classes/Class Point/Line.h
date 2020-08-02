#pragma once

struct Point {
	double x;
	double y;
};

class Line
{
public:
	bool areParallel(const Point& A, const Point& B, const Point& C, const Point& D);
	bool isOnLine(const Point& A, const Point& B, const Point& C);
	void intersection(const Point& A, const Point& B, const Point& C, const Point& D);
};

