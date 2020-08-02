#include "Time.h"

void Time::setHour(unsigned h) {
	hour = h;
	while (hour > 24) {
		hour -= 24;;
	}
}
int Time::getHour() const {
	return hour;
}

void Time::setMin(unsigned m) {
	minutes = m;
	while (minutes > 60) {
		minutes -= 60;
		hour++;
	}
}

int Time::getMin() const {
	return minutes;
}

void Time::addMin(unsigned m) {
	minutes += m;
	setMin(minutes);
}

bool Time::operator<(const Time& t)
{
	if (hour < t.hour) {
		return true;
	}
	else if (hour == t.hour && minutes < t.minutes) {
		return true;
	}

	return false;

}

Time Time::operator+(const Time& t)
{
	int total = t.hour * 60 + t.minutes ;
	setMin(minutes + total);
	return Time();
}

Time Time::operator-(const Time& t)
{
	
	int total = hour * 60 + minutes - t.hour * 60 - t.minutes;
	hour = total / 60;
	minutes = total % 60;
	
	return Time();
}

Time Time::operator*(const Time& t)
{
	int total = (hour * 60 + minutes) * (t.hour * 60 + minutes);
	hour = (total / 60) % 24;
	minutes = total % 60;
	return Time();
}

Time Time::operator*(int t)
{
	int total = (hour * 60 + minutes) * t;
	setMin(total % 60);
	setHour(total / 60);
	return Time();
}

std::ostream& operator<<(std::ostream& out, const Time& t)
{
	out << t.hour << " : " << t.minutes << std::endl;
	return out;
}
