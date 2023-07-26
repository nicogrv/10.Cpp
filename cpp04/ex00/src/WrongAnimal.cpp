#include "../Include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal life (NULL)" << std::endl;
	this->type = "NULL";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal life (" << type << ")" << std::endl;
	this->type = type;
}


WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << "WrongAnimal life copy (" << this->type << ")" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	this->type = src.type;
	std::cout << "WrongAnimal = opperator" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal dead (" << type << ")" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
void		WrongAnimal::setType(std::string type)
{
	this->type = type;
	return ;
}

void		WrongAnimal::makeSound() const
{
	std::cout << "Wrong NO SOUND " << std::endl;
}
