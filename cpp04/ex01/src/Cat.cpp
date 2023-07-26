#include "../Include/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat life (Cat)" << std::endl;
	this->type = "Cat";
	this->cerv = new Brain();
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
	delete this->cerv;
	std::cout << "Cat dead (" << type << ")" << std::endl;
}

std::string Cat::getType() const
{
	return (this->type);
}
void		Cat::setType(std::string type)
{
	this->type = type;
	return ;
}

void		Cat::makeSound() const
{
	std::cout << "Miaou !" << std::endl;
}