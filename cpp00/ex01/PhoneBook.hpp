
#ifndef PHONEBOOK_HPP
	#define PHONEBOOK_HPP
	#include "./Contact.hpp"

	class PhoneBook
	{
		PhoneBook(void);
		~PhoneBook(void);
		Contact contact[8];
		int nb_contact;
	};
#endif