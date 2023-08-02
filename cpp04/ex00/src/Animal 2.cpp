#include "../Include/Animal.hpp"

Animal::Animal()
{
	this->type = "*NO TYPE*";
	this->sound = "*NO SOUND*";
	std::cout << "Animal life" << std::endl;
	return ;
}
Animal::Animal(Animal const &cpy)
{
	this->type = cpy.type;
	this->sound = cpy.sound;
	std::cout << "Animal cpy life" << std::endl;
	return ;
}
Animal	&Animal::operator=(const Animal &src)
{
	this->type = src.type;
	this->sound = src.sound;
	std::cout << "Animal = op" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal dead" << std::endl;
	return ;
}

std::string Animal::getType() const
{
	return (this->type);
}
void Animal::makeSound() const
{
	std::cout << this->sound << std::endl;
}
