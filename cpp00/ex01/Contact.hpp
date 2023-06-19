#ifndef CONTACT_HPP
	#define CONTACT_HPP
	#include <iostream>
	class Contact
	{
		public:	
			Contact(void);
			~Contact(void);
			std::string fname;
			std::string lname;
			std::string nname;
			std::string phone;
			std::string darkestSecret;
	};
#endif