
#ifndef PHONEBOOK_HPP
	#define PHONEBOOK_HPP
	#include "./Contact.hpp"

	class PhoneBook
	{
		public:
			PhoneBook(void);
			~PhoneBook(void);
			Contact contact[8];
			void ft_add();
			int nb_contact;
	};
#endif