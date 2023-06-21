
#ifndef PHONEBOOK_HPP
	#define PHONEBOOK_HPP
	#include "./Contact.hpp"
	#include <cstdlib>

	class PhoneBook
	{
		public:
			PhoneBook(void);
			~PhoneBook(void);
			void ft_add();
			void ft_search();
		private:
			Contact contact[8];
			int _index_contact;
			int _book_full;

	};

#endif