#include "./PhoneBook.hpp"
#include "./ex01.hpp"


PhoneBook::PhoneBook(void)
{
    PhoneBook::nb_contact = 0;
    return ;
}

PhoneBook::~PhoneBook(void)
{}

void	PhoneBook::ft_add()
{
	std::string input;
	std::cout << "Firstname: ";
	std::getline(std::cin, input);
	if (ft_is_aplha(input))
		this->contact[this->nb_contact].fname = input;
	else
		return (false);
}