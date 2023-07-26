#ifndef BRAIN_HPP
	#define BRAIN_HPP
	#include <iostream>
class Brain
{
	public:
		Brain();
		Brain(const Brain &src);
		Brain	&operator=(const Brain &src);
		virtual ~Brain();

	protected: 
		std::string ideas[100];
};

#endif
