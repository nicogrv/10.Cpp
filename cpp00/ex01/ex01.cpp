#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

bool ft_is_aplha(std::string str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (!isalpha(str[i]))
			return (false);
		else
			i++;
	}
	return (true);
}

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
			book.ft_add();

				
		}

	}

	return 0;
}

