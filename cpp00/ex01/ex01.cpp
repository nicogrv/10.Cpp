#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

bool ft_is_aplha(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (isalpha(str[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

bool ft_is_PhoneNumber(std::string str)
{
	int i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (isdigit(str[i]))
			i++;
		else
			return(false);
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
		if(input.compare("ADD") == 0)
			book.ft_add();
		else
			std::cout << "PhoneBook: ";
	}

	return 0;
}

