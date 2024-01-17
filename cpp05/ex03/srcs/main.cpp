/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:24:14 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/17 14:39:43 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main(void)
{
	try
	{
		Bureaucrat tim("tim", 1);
		Intern someRandomIntern;
		AForm* rrf;

		std::cout << "---------------------------------------------------" << std::endl ;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Titou");
		rrf->beSigned(tim);
		tim.executeForm(*rrf);
		delete rrf;
		
		std::cout << "---------------------------------------------------" << std::endl ;
		rrf = someRandomIntern.makeForm("presidential pardon", "Pierre");
		tim.signForm(*rrf);
		tim.executeForm(*rrf);
		delete rrf;
		
		std::cout << "---------------------------------------------------" << std::endl ;
		rrf = someRandomIntern.makeForm("robotomy request", "Victor");
		tim.signForm(*rrf);
		tim.executeForm(*rrf);
		delete rrf;

		std::cout << "---------------------------------------------------" << std::endl ;
		rrf = someRandomIntern.makeForm("NULL", "Tim");
		delete rrf;
		
		std::cout << "---------------------------------------------------" << std::endl ;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
