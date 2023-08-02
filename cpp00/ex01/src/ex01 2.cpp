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
		if(input.compare("ADD") == 0)
			book.ft_add();
		else if (input.compare("SEARCH") == 0)
			book.ft_search();
		else if (input.compare("EXIT") == 0)
			return (0);
		std::cout << "PhoneBook: ";
	}
	return (1);
}

