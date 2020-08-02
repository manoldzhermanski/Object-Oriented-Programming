#pragma once
#include <iostream>
class Time
{
private:
	int hour;
	int minutes;
public:
	void setHour(unsigned h);
	int getHour()const;
	void setMin(unsigned m);
	int getMin()const;
	void addMin(unsigned m);
	bool operator< (const Time& t);
	Time operator+(const Time& t);
	Time operator-(const Time& t);
	Time operator*(const Time& t);
	Time operator*(const int t);
	friend std::ostream& operator<< (std::ostream& out, const Time& t);
};
