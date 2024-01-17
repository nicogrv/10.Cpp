/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:03:29 by nicolasgriv       #+#    #+#             */
/*   Updated: 2024/01/16 18:51:08 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/RobotomyRequestForm.hpp"
#include <fstream>



RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "home")
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getGardeForSign(), copy.getGradeForExecute(), copy.getTarget())
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	return *this;
}

/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target)
{}

/* ************************************************************************** */

void 		RobotomyRequestForm::executeContract(const Bureaucrat &executor) const
{
	srand((unsigned) time(NULL));
	if(std::rand()%2)
		std::cout << executor.getName() << " execute " << this->getName() << ": OK " << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << executor.getName() << " execute " << this->getName() << ": KO " << this->getTarget() << " has not been robotomized" << std::endl;
}
