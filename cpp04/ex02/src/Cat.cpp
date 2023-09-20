#include "../Include/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat life (Cat)" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}
Cat::Cat(const Cat &src) : Animal("Cat")
{
	this->type = src.type;
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->ideas[i] = src.brain->ideas[i];
	std::cout << "Cat life copy (" << this->type << ")" << std::endl;
}
Cat	&Cat::operator=(const Cat &src)
{
	this->type = src.type;
	for (int i = 0; i < 100; i++)
		this->brain->ideas[i] = src.brain->ideas[i];
	std::cout << "Cat = opperator" << std::endl;
	return (*this);

}
Cat::~Cat()
{
	// std::cout << this->brain->ideas[0] << std::endl;
	if (this->brain)
		delete this->brain;
	std::cout << "Cat dead (" << type << ")" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MIAOU" << std::endl;
}

void Cat::setBrain(std::string Ideas, int index)
{
	// std::cout << Ideas << "\t" << this->brain->indexOfIdeas << std::endl; 
	if (0 <= index && index <= 99)
	{
		this->brain->ideas[index] = Ideas;
		return ;
	}
	std::cout << "Bad Index" << std::endl;

}
std::string Cat::getBrain(int index) const
{
	if (0 <= index && index <= 99)
		return this->brain->ideas[index];
	std::cout << "Bad Index" << std::endl;
	return NULL;
}