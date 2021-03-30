#pragma once
#include <cassert>
#include <iostream>

class Rational
{
public:
	Rational();
	Rational(int numerator, int denominator);
	Rational& operator= (const Rational& other);

	void setNumerator(int numerator);
	void setDenominator(int denominator);

	int getNumerator()const;
	int getDenominator()const;

	Rational operator+ (const Rational& other);
	Rational operator- (const Rational& other);
	Rational operator* (const Rational& other);
	Rational operator/ (const Rational& other);

	Rational operator+= (const Rational& other);
	Rational operator-= (const Rational& other);
	Rational operator*= (const Rational& other);
	Rational operator/= (const Rational& other);

	bool operator== (const Rational& other);
	bool operator!= (const Rational& other);
	bool operator>= (const Rational& other);
	bool operator<= (const Rational& other);
	bool operator> (const Rational& other);
	bool operator< (const Rational& other);

	friend std::ostream& operator<< (std::ostream& out, const Rational& number);

private:
	int numerator;
	int denominator;
};

