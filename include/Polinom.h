#pragma once
#include "..\include\Monom.h"
#include "..\include\list.h"
#include <string>

class Polinom {
public:
	List<Monom> monoms;
	int countMonoms = 0;
	Polinom(const List<Monom> &list) : monoms(list) { monoms.sort(); adjust(); };
	Polinom(const Polinom &polinom) : monoms(polinom.monoms) {};
	Polinom() {
		std::cout << "Enter each monomial separately.\n";
		std::cout << "Input rules: coefficient and powers of a monom are written with a space,\n the degree of the variable can be from 0 to 9\n";
		std::cout << "Enter 0 to end input the expression\n";
		std::cout << "Example: -2 6 7 0 it`s -2x^6y^7z^0\n\n";
		double coef = 1;
		int x, y, z;

		while (coef != 0) {
			std::cin >> coef;
			if (coef == 0) break;
			std::cin >> x >> y >> z;
			if (x > 9 || x < 0 || y > 9 || y < 0 || z > 9 || z < 0) {
				std::cout << "Error: very big degree variable!\n";
				continue;
			}
			monoms.addNode(Monom(coef, x*100+y*10+z));
			countMonoms++;
		}
		monoms.sort();
	};
	
	/*Polinom(string str) {

	}; */
	Polinom& operator=(const Polinom& other);
	Polinom operator*(const Polinom& other) const;
	Polinom operator*(const double mnoj) const;
	Polinom operator+(const Polinom& other) const;
	Polinom operator-(const Polinom& other) const;
	

	void adjust();

	friend std::ostream& operator<<(std::ostream& out, const Polinom& polinom)
	{
		out << polinom.monoms << std::endl;
		return out;
	}

};

void Polinom::adjust() {
	auto node1 = monoms.head;
	while (node1->next != nullptr) {
		if (node1->value == node1->next->value) {
			node1->value = node1->value + node1->next->value;
			node1->next = node1->next->next;
			continue;
		}else if (node1->next->value.coef == 0) {
			node1->next = node1->next->next;
			continue;
		}
		node1 = node1->next;
	}
}

Polinom& Polinom::operator=(const Polinom& other) {
	monoms = other.monoms;
	return *this;
}

Polinom Polinom::operator+(const Polinom& other) const {
	List<Monom> result;
	auto node1 = monoms.head;
	auto node2 = other.monoms.head;
	if (countMonoms > other.countMonoms) {
		node2 = monoms.head;
		node1 = other.monoms.head;
	}
	

	while (node1 != nullptr) {
		while (node2 != nullptr) {
			
			if (node1 == nullptr) {
				result.addNode(node2->value);
				node2 = node2->next;
			}else if (node1->value == node2->value) {
				result.addNode(Monom(node1->value.coef + node2->value.coef, node1->value.degree));
				node1 = node1->next;
				node2 = node2->next;
			}
			else if (node1->value < node2->value) {
				result.addNode(node2->value);
				node2 = node2->next;
			}
			else {
				result.addNode(node1->value);
				node1 = node1->next;
			}
		}
		if (node1 != nullptr) {
			result.addNode(node1->value);
			node1 = node1->next;
		}
	}
	return Polinom(result);
}

Polinom Polinom::operator*(const Polinom& other) const {
	List<Monom> result;
	auto node1 = monoms.head;
	auto node2 = other.monoms.head;
	while (node1 != nullptr) {
		node2 = other.monoms.head;
		while (node2 != nullptr) {
			result.addNode(node1->value*node2->value);
			node2 = node2->next;
		}
		node1 = node1->next;
	}

	return Polinom(result);
}

Polinom Polinom::operator*(double mnoj) const {
	List<Monom> result;
	auto node1 = monoms.head;
	while (node1 != nullptr) {
		result.addNode(Monom(node1->value.coef * mnoj, node1->value.degree));
	}
	return Polinom(result);
}

Polinom Polinom::operator-(const Polinom& other) const {
	//other = other * -1.0;
	return operator+(other * -1.0);
}