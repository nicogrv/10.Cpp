/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:03:29 by nicolasgriv       #+#    #+#             */
/*   Updated: 2024/01/17 14:31:52 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/PresidentialPardonForm.hpp"
#include <fstream>



PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "home")
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getName(), copy.getGardeForSign(), copy.getGradeForExecute(), copy.getTarget())
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm   &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	return *this;
}

/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, target)
{}

/* ************************************************************************** */

void 		PresidentialPardonForm::executeContract(const Bureaucrat &executor) const
{
	std::cout << executor.getName() << " execute " << this->getName() << ": " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm *PresidentialPardonForm::createForm(std::string target)
{
	AForm *form;
	
	form = new PresidentialPardonForm(target);
	std::cout << "New form: " << *form << std::endl;
	return form;
}