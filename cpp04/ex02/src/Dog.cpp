#include "../Include/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog life (Dog)" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}
Dog::Dog(const Dog &src) : Animal("Dog")
{
	this->type = src.type;
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->ideas[i] = src.brain->ideas[i];
	std::cout << "Dog life copy (" << this->type << ")" << std::endl;
}
Dog	&Dog::operator=(const Dog &src)
{
	this->type = src.type;
	for (int i = 0; i < 100; i++)
		this->brain->ideas[i] = src.brain->ideas[i];
	std::cout << "Dog = opperator" << std::endl;
	return (*this);

}
Dog::~Dog()
{
	// std::cout << this->brain->ideas[0] << std::endl;
	if (this->brain)
		delete this->brain;
	std::cout << "Dog dead (" << type << ")" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "MIAOU" << std::endl;
}

void Dog::setBrain(std::string Ideas, int index)
{
	// std::cout << Ideas << "\t" << this->brain->indexOfIdeas << std::endl; 
	if (0 <= index && index <= 99)
	{
		this->brain->ideas[index] = Ideas;
		return ;
	}
	std::cout << "Bad Index" << std::endl;

}
std::string Dog::getBrain(int index) const
{
	if (0 <= index && index <= 99)
		return this->brain->ideas[index];
	std::cout << "Bad Index" << std::endl;
	return NULL;
}