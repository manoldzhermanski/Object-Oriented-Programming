#include "Rational.h"

Rational::Rational()
{
	setNumerator(1);
	setDenominator(1);
}

Rational::Rational(int numerator, int denominator)
{
	setNumerator(numerator);
	setDenominator(denominator);
}

Rational& Rational::operator=(const Rational& other)
{
	setNumerator(other.getNumerator());
	setDenominator(other.getDenominator());
	return *this;
}

void Rational::setNumerator(int numerator)
{
	assert(numerator != 0);
	this->numerator = numerator;
}

void Rational::setDenominator(int denominator)
{
	assert(denominator != 0);
	this->denominator = denominator;
}

int Rational::getNumerator() const
{
	return this->numerator;
}

int Rational::getDenominator() const
{
	return this->denominator;
}

Rational Rational::operator+(const Rational& other)
{
	Rational temp;
	temp.setNumerator(this->numerator * other.denominator + other.numerator * this->denominator);
	temp.setDenominator(this->denominator * other.denominator);
	return temp;
}

Rational Rational::operator-(const Rational& other)
{
	Rational temp;
	temp.setNumerator(this->numerator * other.denominator - other.numerator * this->denominator);
	temp.setDenominator(this->denominator * other.denominator);
	return temp;
}

Rational Rational::operator*(const Rational& other)
{
	Rational temp;
	temp.setNumerator(this->numerator * other.numerator);
	temp.setDenominator(this->denominator * other.denominator);
	return temp;
}

Rational Rational::operator/(const Rational& other)
{
	Rational temp;
	temp.setNumerator(this->numerator * other.denominator);
	temp.setDenominator(this->denominator * other.numerator);
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Rational& number)
{
	out << number.numerator << "/" << number.denominator;
	return out;
}

Rational Rational::operator+=(const Rational& other)
{
	*this = *this + other;
	return *this;
}

Rational Rational::operator-=(const Rational& other)
{
	*this = *this - other;
	return *this;
}

Rational Rational::operator*=(const Rational& other)
{
	*this = *this * other;
	return *this;
}

Rational Rational::operator/=(const Rational& other)
{
	*this = *this / other;
	return *this;
}

bool Rational::operator==(const Rational& other)
{
	return this->numerator == other.numerator && this->denominator == other.denominator;
}

bool Rational::operator!=(const Rational& other)
{
	return !(*this == other);
}

bool Rational::operator>=(const Rational& other)
{
	return this->numerator >= other.numerator && this->denominator < other.denominator;
}

bool Rational::operator<=(const Rational& other)
{
	return this->numerator <= other.denominator && this->denominator > other.denominator;
}

bool Rational::operator>(const Rational& other)
{
	return this->numerator > other.numerator && this->denominator < other.denominator;
}

bool Rational::operator<(const Rational& other)
{
	return this->numerator < other.denominator && this->denominator > other.denominator;
}
