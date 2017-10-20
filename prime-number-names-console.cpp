// prime-number-names-console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

bool IsPrime(unsigned int number, unsigned int &divisor);

int main()
{
	std::string name;
	unsigned int total = 0;

	std::cout << "Enter name: ";
	std::getline(std::cin, name);
	std::cout << std::endl;

	for (unsigned int i = 0; i < name.length(); i++) {
		char this_char = name[i];
		std::cout << this_char;

		// If letter, make lower case. If not, skip
		if (this_char >= 'A' && this_char <= 'Z') {
			this_char += 32;
		}
		if (this_char < 'a' || this_char > 'z') {
			std::cout << "(ignored)" << std::endl;
			continue;
		}

		unsigned int letter_value = this_char - ('a' - 1);

		std::cout << "(" << letter_value << ")" << std::endl;
		total += letter_value;
	}

	std::cout << std::endl << "Total = " << total << " ";

	unsigned int divisor;
	if (IsPrime(total, divisor)) {
		std::cout << "(PRIME!)";
	}
	else {
		std::cout << "(not prime: divides by " << divisor << ")";
	}
	std::cout << std::endl;

	return 0;
}

bool IsPrime(unsigned int number, unsigned int &divisor)
{
	for (unsigned int i = 2; i <= (number / 2); i++) {
		if (number % i == 0) {
			divisor = i;
			return false;
		}
	}

	return true;
}