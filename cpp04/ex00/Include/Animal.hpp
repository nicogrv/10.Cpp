#ifndef ANIMAL_HPP
	#define ANIMAL_HPP
	#include <iostream>


class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &src);
		Animal	&operator=(const Animal &src);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType(void) const;

	protected:
		std::string type;
};

#endif