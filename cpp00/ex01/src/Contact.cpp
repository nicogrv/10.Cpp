#include "./PhoneBook.hpp"
#include "./ex01.hpp"
#include "./Contact.hpp"


std::string Contact::ft_get_fname() const
{return (this->fname);}

std::string Contact::ft_get_lname() const
{return (this->lname);}

std::string Contact::ft_get_nname() const
{return (this->nname);}

std::string Contact::ft_get_phone() const
{return (this->phone);}

std::string Contact::ft_get_darkestSecret() const
{return (this->darkestSecret);}

void Contact::ft_add(void)
{
    	std::string input;
	while (1)
	{
		std::cout << "Contact FirstName: ";
		if (!std::getline(std::cin, input))
			exit(0);
		if (ft_is_aplha(input))
		{
			this->fname = input;
			break;
		}
		std::cout << "Incorrect FirstName." << std::endl;
	}
	while (1)
	{
		std::cout << "Contact LastName: ";
		if (!std::getline(std::cin, input))
			exit(0);
		if (ft_is_aplha(input))
		{
			this->lname = input;
			break;
		}
		std::cout << "Incorrect LastName." << std::endl;
	}
	std::cout << "Contact NickName: ";
	if (!std::getline(std::cin, input))
		exit(0);
	this->nname = input;
	while (1)
	{
		std::cout << "Contact PhoneNumber: ";
		if (!std::getline(std::cin, input))
			exit(0);
		if (ft_is_PhoneNumber(input))
		{
			this->phone = input;
			break ;
		}
		std::cout << "Incorrect PhoneNumber." << std::endl;
	}
	std::cout << "Contact DarkestSecret: ";
	if (!std::getline(std::cin, input))
		exit(0);
	this->darkestSecret = input;
}

Contact::Contact(void)
{
    this->nname = "";
    this->fname = "";
    this->lname = "";
    this->phone = "";
    this->darkestSecret = "";
    return ;
}

Contact::~Contact(void)
{
    return ;
}