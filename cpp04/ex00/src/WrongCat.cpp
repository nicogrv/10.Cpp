#include "../Include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat life (WrongCat)" << std::endl;
	this->type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &src) : WrongAnimal("WrongCat")
{
	*this = src;
	std::cout << "WrongCat life copy (" << this->type << ")" << std::endl;
}
WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	this->type = src.type;
	std::cout << "WrongCat = opperator" << std::endl;
	return (*this);

}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat dead (" << type << ")" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "*WRONG CAT SOUND*" << std::endl;
}