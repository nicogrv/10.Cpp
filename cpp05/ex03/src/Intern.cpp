#include "../Include/Bureaucrat.hpp"
#include "../Include/Intern.hpp"
#include "../Include/ShrubberyCreationForm.hpp"
#include "../Include/RobotomyRequestForm.hpp"
#include "../Include/PresidentialPardonForm.hpp"
#include "../Include/AForm.hpp"



Intern::Intern()
{
	std::cout << "New intern" << std::endl;
}
Intern::Intern(Intern &cpy)
{
	*this = cpy;
	std::cout << "New intern cpy" << std::endl;
}
Intern::~Intern()
{
	std::cout << "Destruction intern" << std::endl;
}
Intern &Intern::operator=(Bureaucrat &cpy)
{
	(void) cpy;
	std::cout << "intern = " << std::endl;
	return (*this);
}

AForm *Intern::makeForm(std::string name,std::string cible)
{
	std::string listForm[] = {"robotomy request", "presidential pardon", "shrubbery creationForm"};

	for (unsigned long i = 0; i < sizeof(listForm) / sizeof(listForm[0]); i++)
	{
		if (name == listForm[i])
		{
			try
			{
					
			}
		}
	}
	(void) cible;

	return (NULL);
}