#include "./PhoneBook.hpp"
#include "./ex01.hpp"


PhoneBook::PhoneBook(void)
{
    PhoneBook::nb_contact = 0;
    return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::ft_add()
{
	std::string input;
	std::cout << "Contact FirstName: ";
	std::getline(std::cin, input);
	if (ft_is_aplha(input))
		this->contact[this->nb_contact].fname = input;
	else
		return ;
	std::cout << "Contact LastName: ";
	std::getline(std::cin, input);
	if (ft_is_aplha(input))
		this->contact[this->nb_contact].lname = input;
	else
		return ;
	std::cout << "Contact NickName: ";
	std::getline(std::cin, input);
	if (ft_is_aplha(input))
		this->contact[this->nb_contact].nname = input;
	else
		return ;

	std::cout << "Contact PhoneNumber: ";
	std::getline(std::cin, input);
	if (ft_is_PhoneNumber(input))
		this->contact[this->nb_contact].nname = input;
	else
		return ;
	std::cout << "Le contact \"" << this->contact->lname << " " << this->contact->fname << "\" a ete cree a la position: " << this->nb_contact;
	this->nb_contact++;
	
}