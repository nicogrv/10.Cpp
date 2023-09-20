#include "../Include/Brain.hpp"

Brain::Brain()
{
	std::cout << "New brain" << std::endl;
}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	std::cout << "New CPY brain" << std::endl;
}

Brain	&Brain::operator=(const Brain &src)
{
	
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	std::cout << "New CPY brain" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Delete Brain" << std::endl;
}


