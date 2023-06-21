#ifndef CONTACT_HPP
	#define CONTACT_HPP
	#include <iostream>
	#include <iomanip>
	class Contact
	{
		public:
			std::string ft_get_fname() const;
			std::string ft_get_lname() const;
			std::string ft_get_nname() const;
			std::string ft_get_phone() const;
			std::string ft_get_darkestSecret() const;
			void ft_add(void);

			Contact(void);
			~Contact(void);

		private:
			std::string fname;
			std::string lname;
			std::string nname;
			std::string phone;
			std::string darkestSecret;
	};
#endif