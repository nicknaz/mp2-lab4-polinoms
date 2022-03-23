#include <iostream>
#include "..\include\list.h"
#include "..\include\Polinom.h"

int main()
{
	std::cout << "Hi! Welcome in Polinom`s program\n";
	std::cout << "Input first polinom:\n";
	Polinom polinom1;
	std::cout << "Polinom1: " << polinom1;
	std::cout << "Input second polinom:\n";
	Polinom polinom2;
	std::cout << "Polinom2: " << polinom2;

	int choose = 0;
	double number = 1;
	std::cout << "What you want?\n";
	std::cout << "1 - polinom1 + polinom2\n";
	std::cout << "2 - polinom1 * polinom2\n";
	std::cout << "3 - polinom1 - polinom2\n";
	std::cout << "4 - polinom1 * number\n";
	std::cin >> choose;
	switch (choose)
	{
	case 1:
		std::cout << "polinom1 + polinom2 = " << polinom1 + polinom2 << std::endl;
		break;
	case 2:
		std::cout << "polinom1 * polinom2 = " << polinom1 * polinom2 << std::endl;
		break;
	case 3:
		std::cout << "polinom1 - polinom2 = " << polinom1 - polinom2 << std::endl;
		break;
	case 4:
		std::cout << "Enter number: \n";
		std::cin >> number;
		std::cout << "polinom1 * number = " << polinom1 * number << std::endl;
		break;
	default:
		break;
	}

	std::cout << "Good Bye!\n";
}

