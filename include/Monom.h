#pragma once
#include <string>

class Monom {
public:
	double coef;
	int degree, sum;
	//example: 2*x^3*y^7*z^9 coef=2 degree=379
	Monom() :coef(1), degree(0) {};
	Monom(double coef = 1, int degree = 0) :coef(coef), degree(degree) { sum = degree % 10 + degree / 100 + degree / 10 % 10; };

	Monom operator+(const Monom& other);
	Monom operator*(const Monom& other);
	bool operator==(const Monom& other) const { return degree == other.degree; }
	bool operator<(const Monom& other) { return degree < other.degree; }

	friend std::ostream& operator<<(std::ostream& out, const Monom& monom)
	{
		out << (monom.coef>0? std::string("+") : std::string("")) << monom.coef << "x^" << monom.degree/100 << "y^" << monom.degree / 10 % 10 << "z^" << monom.degree% 10;
		return out;
	}

};

Monom Monom::operator+(const Monom& other){
	if (degree != other.degree)
		throw "coefs not equal";
	return Monom(coef+other.coef, degree);
}

Monom Monom::operator*(const Monom& other) {
	if (degree % 10 + other.degree % 10 > 9 || degree / 100 + other.degree / 100 > 9 || degree / 10 % 10 + other.degree / 10 % 10 > 9)
		throw "degree in variable very big";
	return Monom(coef * other.coef, degree + other.degree);
}