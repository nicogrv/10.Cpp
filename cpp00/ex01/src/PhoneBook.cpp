#include "./PhoneBook.hpp"
#include "./ex01.hpp"


PhoneBook::PhoneBook(void)
{
    this->_index_contact = 7;
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
	std::string input;
	while (1)
	{
		std::cout << "Contact FirstName: ";
		std::getline(std::cin, input);
		if (ft_is_aplha(input))
		{
			this->contact[this->_index_contact].fname = input;
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
			this->contact[this->_index_contact].lname = input;
			break;
		}
		std::cout << "Incorrect LastName." << std::endl;
	}
	std::cout << "Contact NickName: ";
	std::getline(std::cin, input);
	this->contact[this->_index_contact].nname = input;
	while (1)
	{
		std::cout << "Contact PhoneNumber: ";
		std::getline(std::cin, input);
		if (ft_is_PhoneNumber(input))
		{
			this->contact[this->_index_contact].phone = input;
			break ;
		}
		std::cout << "Incorrect PhoneNumber." << std::endl;
	}
	std::cout << "Contact DarkestSecret: ";
	std::getline(std::cin, input);
	this->contact[this->_index_contact].darkestSecret = input;
	std::cout << "Le contact \"" << this->contact[_index_contact].lname << " " << this->contact[_index_contact].fname << "\" a ete cree a la position: " << this->_index_contact << std::endl;
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

	std::cout << std::endl << "|     Index| FirstName|  LastName|  NickName|" << std::endl << "---------------------------------------------" << std::endl ;
	while (i < 8)
	{
		if (i < this->_index_contact || this->_book_full)
		{
			std::cout << "|         " << i << "|";
			len = this->contact[i].fname.length();
			j = 0;
			if (10 < len)
			{
				while  (j < 9)
					std::cout << this->contact[i].fname[j++];
				std::cout << ".|";
			}
			else
			{
				while (j++ < 10 - len)
					std::cout << " ";
				k = 0;
				while (j++ <= 10)
					std::cout << this->contact[i].fname[k++];
				std::cout << "|";
			}
			len = this->contact[i].lname.length();
			j = 0;
			if (10 < len)
			{
				while  (j < 9)
					std::cout << this->contact[i].lname[j++];
				std::cout << ".|";
			}
			else
			{
				while (j++ < 10 - len)
					std::cout << " ";
				k = 0;
				while (j++ <= 10)
					std::cout << this->contact[i].lname[k++];
				std::cout << "|";
			}
			len = this->contact[i].nname.length();
			j = 0;
			if (10 < len)
			{
				while  (j < 9)
					std::cout << this->contact[i].nname[j++];
				std::cout << ".|";
			}
			else
			{
				while (j++ < 10 - len)
					std::cout << " ";
				k = 0;
				while (j++ <= 10)
					std::cout << this->contact[i].nname[k++];
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
		std::cout << std::endl <<  "Prenom: " << this->contact[i].fname << std::endl;
		std::cout <<  "Nom: " << this->contact[i].lname << std::endl;
		std::cout <<  "Surnom: " << this->contact[i].nname << std::endl;
		std::cout <<  "Telephone: " << this->contact[i].phone << std::endl;
		std::cout <<  "Secret : " << this->contact[i].darkestSecret << std::endl << std::endl;
	}
	else
		std::cout << "Incorrect Index" << std::endl;
	
}