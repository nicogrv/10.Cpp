/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:24:14 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/16 18:54:47 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat boss(1);
		ShrubberyCreationForm ShrubberyForm("titou");
		RobotomyRequestForm RobotomyForm("pierre");
		PresidentialPardonForm PresidentialForm("victor");
		std::cout << boss;
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << ShrubberyForm << std::endl;
		std::cout << RobotomyForm << std::endl;
		std::cout << PresidentialForm << std::endl;

		std::cout << "---------------------------------------------------" << std::endl;

		boss.signForm(ShrubberyForm);
		ShrubberyForm.execute(boss);

		std::cout << "---------------------------------------------------" << std::endl;
		
		boss.signForm(RobotomyForm);
		RobotomyForm.execute(boss);

		std::cout << "---------------------------------------------------" << std::endl;
		
		boss.signForm(PresidentialForm);
		PresidentialForm.execute(boss);

		std::cout << "---------------------------------------------------" << std::endl;

		boss.executeForm(ShrubberyForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
