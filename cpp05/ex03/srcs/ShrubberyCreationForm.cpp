/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:03:29 by nicolasgriv       #+#    #+#             */
/*   Updated: 2024/01/17 14:31:52 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>



ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, "home")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getGardeForSign(), copy.getGradeForExecute(), copy.getTarget())
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	return *this;
}

/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, target)
{}

/* ************************************************************************** */

AForm *ShrubberyCreationForm::createForm(std::string target)
{
	AForm *form;
	
	form = new ShrubberyCreationForm(target);
	std::cout << "New form: " << *form << std::endl;
	return form;
}

void 		ShrubberyCreationForm::executeContract(const Bureaucrat &executor) const 
{
	std::string nameFile = this->getTarget() + "_Shrubbery";
	std::ofstream fichier(nameFile.c_str());
	if (fichier.is_open()) 
	{
		fichier << "    *    " << std::endl;
		fichier << "   { }   " << std::endl;
		fichier << "  {   }  " << std::endl;
		fichier << " {_   _} " << std::endl;
		fichier << "   |_|   " << std::endl;
		fichier.close();
		std::cout << executor.getName() << " excute " << this->getName() << ": File \"" << nameFile << "\" created "<< std::endl;
	}
	else 
		throw std::runtime_error("File not open");
}
