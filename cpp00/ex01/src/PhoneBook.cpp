#include "./PhoneBook.hpp"
#include "./ex01.hpp"


PhoneBook::PhoneBook(void)
{
    this->_index_contact = 0;
	this->_book_full = 0;
    return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

bool ft_is_num(std::string str)
{
	int i = 0;
	int ok = 0;

	while (str[i])
	{
		if (isdigit(str[i]))
		{
			ok = 1;
			i++;
		}
		else
			return (false);
	}
	if (ok)
		return (true);
	else
		return (false);
}

bool ft_is_aplha(std::string str)
{
	int i = 0;
	int ok = 0;

	while (str[i])
	{
		if (isalpha(str[i]))
		{
			ok = 1;
			i++;
		}
		else
			return (false);
	}
	if (ok)
		return (true);
	else
		return (false);
}

bool ft_is_PhoneNumber(std::string str)
{
	int i = 0;
	int ok = 0;
	if (!str[0])
		return (false);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (isdigit(str[i]))
		{
			i++;
			ok = 1;
		}
		else
			return(false);
	}
	if (ok)
		return (true);
	else
		return (false);
}

void	PhoneBook::ft_add()
{
	this->contact[_index_contact].ft_add();
	std::cout << "Le contact \"" << this->contact[_index_contact].ft_get_lname() << " " << this->contact[_index_contact].ft_get_fname() << "\" a ete cree a la position: " << this->_index_contact << std::endl;
	if (this->_index_contact == 7)
	{
		this->_index_contact = 0;
		this->_book_full = 1;
	}
	else
		this->_index_contact++;
}

void PhoneBook::ft_search()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int len = 0;
	std::string str;

	std::cout << std::endl << "|     Index| FirstName|  LastName|  NickName|" << std::endl << "---------------------------------------------" << std::endl ;
	while (i < 8)
	{
		if (i < this->_index_contact || this->_book_full)
		{
			std::cout << "|         " << i << "|";
			len = this->contact[i].ft_get_fname().length();
			j = 0;
			str = this->contact[i].ft_get_fname();
			if (10 < len)
			{
				while  (j < 9)
					std::cout << str[j++];
				std::cout << ".|";
			}
			else
			{
				while (j++ < 10 - len)
					std::cout << " ";
				k = 0;
				while (j++ <= 10)
					std::cout << str[k++];
				std::cout << "|";
			}
			len = this->contact[i].ft_get_lname().length();
			j = 0;
			str = this->contact[i].ft_get_lname();
			if (10 < len)
			{
				while  (j < 9)
					std::cout << str[j++];
				std::cout << ".|";
			}
			else
			{
				while (j++ < 10 - len)
					std::cout << " ";
				k = 0;
				while (j++ <= 10)
					std::cout << str[k++];
				std::cout << "|";
			}
			len = this->contact[i].ft_get_nname().length();
			j = 0;
			str = this->contact[i].ft_get_nname();
			if (10 < len)
			{
				while  (j < 9)
					std::cout << str[j++];
				std::cout << ".|";
			}
			else
			{
				while (j++ < 10 - len)
					std::cout << " ";
				k = 0;
				while (j++ <= 10)
					std::cout << str[k++];
				std::cout << "|";
			}
		}
		else
			std::cout << "|          |          |          |          |";
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl << "For more information type index: ";
	std::string input;
	std::getline(std::cin, input);
	i = std::atoi(input.c_str());
	if (ft_is_num(input) && -1 < i && i < 8 && (i < this->_index_contact || this->_book_full))
	{
		std::cout << std::endl <<  "Prenom: " << this->contact[i].ft_get_fname() << std::endl;
		std::cout <<  "Nom: " << this->contact[i].ft_get_lname() << std::endl;
		std::cout <<  "Surnom: " << this->contact[i].ft_get_nname() << std::endl;
		std::cout <<  "Telephone: " << this->contact[i].ft_get_phone() << std::endl;
		std::cout <<  "Secret : " << this->contact[i].ft_get_darkestSecret() << std::endl << std::endl;
	}
	else
		std::cout << "Incorrect Index" << std::endl;
	
}