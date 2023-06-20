#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	std::cout << "PhoneBook: ";
	std::string input;
	book.contact[0].fname = "wlkwoeqweqweqefbwf";
	book.contact[0].lname = "wlkwof1111111111bwf";
	book.contact[0].nname = "wlkwqeqweqeqeqweqofbwf";
	book.contact[0].phone = "1651651";
	book.contact[1].fname = "Fest";
	book.contact[1].lname = "Lest";
	book.contact[1].nname = "Nest";
	book.contact[1].phone = "51651";
	book.contact[2].fname = "123456789";
	book.contact[2].lname = "1234567891";
	book.contact[2].nname = "12345678912";
	book.contact[2].phone = "51651";
	book.contact[3].fname = "1";
	book.contact[3].lname = "2";
	book.contact[3].nname = "3";
	book.contact[3].phone = "4";
	book.contact[4].fname = "a";
	book.contact[4].lname = "b";
	book.contact[4].nname = "c";
	book.contact[4].phone = "d";
	book.contact[5].fname = "1111111111111111";
	book.contact[5].lname = "22222222222222";
	book.contact[5].nname = "3333333333333";
	book.contact[5].phone = "44444444444444";
	book.contact[6].fname = "f";
	book.contact[6].lname = "l";
	book.contact[6].nname = "n";
	book.contact[6].phone = "p";
	book.contact[6].fname = "h";
	book.contact[6].lname = "h";
	book.contact[6].nname = "h";
	book.contact[6].phone = "h";

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

	return 1;
}

