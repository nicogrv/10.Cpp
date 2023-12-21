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

AForm *Intern::makeForm(std::string cible,std::string name)
{
	std::string listForm[] = {"robotomy request", "presidential pardon", "shrubbery creationForm"};
	AForm		*(*Instance[])(std::string)	= {&ShrubberyCreationForm::NewForm, &RobotomyRequestForm::NewForm, &PresidentialPardonForm::NewForm};
	AForm	*form;

	for (unsigned long i = 0; i < sizeof(listForm) / sizeof(listForm[0]); i++)
	{
		// std::cout << cible << "\t" << listForm[i] << std::endl; 
		if (cible == listForm[i])
		{
			form = Instance[i](name);
			if (!form)
				return (NULL);
			else
				return (form);
		}
	}
	return (NULL);
}