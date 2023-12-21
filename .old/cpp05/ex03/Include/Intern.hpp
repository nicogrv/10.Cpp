#ifndef INTERN_HPP
	#define INTERN_HPP
	#include "../Include/Bureaucrat.hpp"
	#include "../Include/AForm.hpp"
	#include "../Include/ShrubberyCreationForm.hpp"
	#include "../Include/RobotomyRequestForm.hpp"
	#include "../Include/PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern &cpy);
		~Intern();
        Intern &operator=(Bureaucrat &cpy);

		AForm *makeForm(std::string name,std::string cible);
};


#endif