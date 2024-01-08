/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:24:14 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/08 17:41:58 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(void)
{
	try 
	{
		Form form;
		std::cout << form << std::endl;

	std::cout << "---------------------------------------------------" << std::endl;


		Form customForm("Doc", 42, 12);
		std::cout << customForm << std::endl;
		Form copyForm(customForm);
		std::cout << copyForm << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "---------------------------------------------------" << std::endl;
	
	try 
	{
		// Bureaucrat Boss(8);
		Bureaucrat Boss(12);
		Form cdd("CDD", 20, 15);
		Form cdi("CDI", 10, 5);

		std::cout << Boss << std::endl;
		std::cout << cdd << std::endl;
		std::cout << cdi << std::endl;
		

		cdd.beSigned(Boss);
		// cdd.beSigned(Boss);
		cdi.beSigned(Boss);
		// cdi.beSigned(Boss);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------------------------------------" << std::endl;

	try 
	{
		// Bureaucrat Boss(8);
		Bureaucrat Boss(12);
		Form Interim("Interim", 20, 15);
		Form Stage("Stage", 10, 5);

		std::cout << Boss;
		std::cout << Interim << std::endl;
		std::cout << Stage << std::endl << std::endl;
		
		Boss.signForm(Interim);		
		std::cout << Interim << std::endl << std::endl;
		Boss.signForm(Stage);		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
