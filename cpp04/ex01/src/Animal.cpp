#include "../Include/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal life (NULL)" << std::endl;
	this->type = "NULL";
}

Animal::Animal(std::string type)
{
	std::cout << "Animal life (" << type << ")" << std::endl;
	this->type = type;
}


Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Animal life copy (" << this->type << ")" << std::endl;
}

Animal	&Animal::operator=(const Animal &src)
{
	this->type = src.type;
	std::cout << "Animal = opperator" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal dead (" << type << ")" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "*NO SOUND*" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}
