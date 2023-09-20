#include "../Include/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat life (Cat)" << std::endl;
	this->type = "Cat";
}
Cat::Cat(const Cat &src) : Animal("Cat")
{
	*this = src;
	std::cout << "Cat life copy (" << this->type << ")" << std::endl;
}
Cat	&Cat::operator=(const Cat &src)
{
	this->type = src.type;
	std::cout << "Cat = opperator" << std::endl;
	return (*this);

}
Cat::~Cat()
{
	std::cout << "Cat dead (" << type << ")" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MIAOU" << std::endl;
}