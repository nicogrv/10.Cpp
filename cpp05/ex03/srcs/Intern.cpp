/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:05:19 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/17 16:09:27 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}

Intern::~Intern()
{}

Intern	&Intern::operator=(const Intern &copy)
{
	(void) copy;
	return (*this);
}

/* ************************************************************************** */

struct sFonction
{
    const char *nameOfTheFrom;
    AForm *(*fonction)(std::string);
};

AForm *Intern::makeForm(std::string nameOfTheForm, std::string target)
{
	sFonction fonction[] = {
		{"shrubbery creation", ShrubberyCreationForm::createForm},
		{"robotomy request", RobotomyRequestForm::createForm},
		{"presidential pardon", PresidentialPardonForm::createForm}
	};
	
	for (unsigned int i = 0; i < sizeof(fonction) / sizeof(fonction[0]); i++)
	{
		if (fonction[i].nameOfTheFrom == nameOfTheForm) {
			std::cout << "\"" << nameOfTheForm << "\"" << " created" << std::endl;
			return (fonction[i].fonction(target));
		}
	}
	std::cout << "\"" << nameOfTheForm << "\"" << " is not good form" << std::endl;
	return (NULL);
	
} 
