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

bool ft_is_aplha(std::string str)
{
	int i = 0;

	if (!str[0])
		return (false);
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
	if (!str[0])
		return (false);
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
			this->contact[this->_index_contact].nname = input;
			break ;
		}
		std::cout << "Incorrect PhoneNumber." << std::endl;
	}
	std::cout << "Le contact \"" << this->contact[_index_contact].lname << " " << this->contact[_index_contact].fname << "\" a ete cree a la position: " << this->_index_contact;
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

	std::cout << "|     Index| FirstName|  LastName|  NickName|" << std::endl << "---------------------------------------------" << std::endl ;
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
	
}