
#ifndef PHONEBOOK_HPP
	#define PHONEBOOK_HPP
	#include "./Contact.hpp"
	#include <cstdlib>

	class PhoneBook
	{
		public:
			PhoneBook(void);
			~PhoneBook(void);
			Contact contact[8];
			void ft_add();
			void ft_search();
		private:
			int _index_contact;
			int _book_full;

	};

#endif