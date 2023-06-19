#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	std::cout << "PhoneBook: ";
	std::string input;
	while (std::getline(std::cin, input))
	{
		std::cout << "PhoneBook: ";
		if(input.compare("ADD") == 0)
		{
			std::cout << "PhoneBook: ";
			std::getline(std::cin, input);
			input >> [PhoneBook::nb_contact];;
			
		}

	}

	return 0;
}

