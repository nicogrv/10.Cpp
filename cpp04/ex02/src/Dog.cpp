#include "../Include/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->type = "Dog";
	std::cout << "Dog life (Dog)" << std::endl;
	this->cerv = new Brain();
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
	delete this->cerv;
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

void		Dog::makeSound() const
{
	std::cout << "Wouaf !" << std::endl;
}

std::string Dog::getIdeas() const
{	
	return (this->cerv->getIdeas());
}
void		Dog::setIdeas(std::string Ideas)
{
	this->cerv->setIdeas(Ideas);
}