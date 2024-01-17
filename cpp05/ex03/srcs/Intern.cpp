/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:05:19 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/17 13:00:28 by ngriveau         ###   ########.fr       */
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

AForm	*Intern::makeForm(std::string nameOfTheFrom, std::string target)
{
	std::string listForm[] = {"test", "go", "pizza"};
	for (unsigned int i = 0; i < listForm->size() - 1; i++)
		std::cout << listForm[i] << std::endl;
	std::cout << nameOfTheFrom << " " << target << std::endl;

	ShrubberyCreationForm *test = new ShrubberyCreationForm(target);
	return (test);
} 
