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
	this->cerv = new Brain();
	std::cout << "Cat life copy (" << this->type << ")" << std::endl;
}
Cat	&Cat::operator=(const Cat &src)
{
	std::cout << "Cat = opperator" << std::endl;
	if (!this->cerv)
		this->cerv = new Brain();
	this->type = src.type;
	*(this->cerv) = *(src.cerv);
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

std::string Cat::getIdeas() const
{	
	return (this->cerv->getIdeas());
}
void		Cat::setIdeas(std::string Ideas)
{
	this->cerv->setIdeas(Ideas);
}