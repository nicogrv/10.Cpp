#include "../Include/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->type = "Dog";
	std::cout << "Dog life (Dog)" << std::endl;
}
Dog::Dog(const Dog &src) : Animal("Dog")
{
	*this = src;
	std::cout << "Dog life copy (Dog)" << std::endl;
}
Dog	&Dog::operator=(const Dog &src)
{
	this->type = src.type;
	std::cout << "Dog = opperator" << std::endl;
	return (*this);
}
Dog::~Dog()
{
	std::cout << "Dog dead (" << type << ")" << std::endl;
}

std::string Dog::getType() const
{
	return (this->type);
}
void		Dog::setType(std::string type)
{
	this->type = type;
	return ;
}

void		Animal::makeSound() const 
{
	std::cout << "Miaou !" << std::endl;
}