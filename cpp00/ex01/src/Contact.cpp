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
		std::getline(std::cin, input);
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
		std::getline(std::cin, input);
		if (ft_is_aplha(input))
		{
			this->lname = input;
			break;
		}
		std::cout << "Incorrect LastName." << std::endl;
	}
	std::cout << "Contact NickName: ";
	std::getline(std::cin, input);
	this->nname = input;
	while (1)
	{
		std::cout << "Contact PhoneNumber: ";
		std::getline(std::cin, input);
		if (ft_is_PhoneNumber(input))
		{
			this->phone = input;
			break ;
		}
		std::cout << "Incorrect PhoneNumber." << std::endl;
	}
	std::cout << "Contact DarkestSecret: ";
	std::getline(std::cin, input);
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