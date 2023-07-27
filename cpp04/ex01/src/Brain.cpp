#include "../Include/Brain.hpp"


Brain::Brain()
{
	std::cout << "New Brain" << std::endl;
}

Brain::Brain(const Brain &src)
{
	*this = src;
	std::cout << "New Copy Brain" << std::endl;
}

Brain	&Brain::operator=(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	std::cout << "New = Brain |||" << std::endl;
	return (*this);

}

Brain::~Brain()
{
	std::cout << "Delete Brain" << std::endl;

}

std::string Brain::getIdeas() const
{	
	return (*this->ideas);
}
void		Brain::setIdeas(std::string Ideas)
{
	*this->ideas = Ideas;
}