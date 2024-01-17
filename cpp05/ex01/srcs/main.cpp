/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:24:14 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/17 15:18:19 by ngriveau         ###   ########.fr       */
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

	std::cout << "1 ---------------------------------------------------" << std::endl;


		Form customForm("Doc", 42, 12);
		std::cout << "customForm" << customForm << std::endl;
		Form copyForm(customForm);
		std::cout << "copyForm" << copyForm << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "2 ---------------------------------------------------" << std::endl;
	
	try 
	{
		// Bureaucrat Boss(8);
		Bureaucrat Boss("boss", 12);
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
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "3 ---------------------------------------------------" << std::endl;

	try 
	{
		// Bureaucrat Boss("boss",8);
		Bureaucrat Boss("boss", 12);
		Form Interim("Interim", 20, 15);
		Form Stage("Stage", 10, 5);

		std::cout << Boss;
		std::cout << Interim << std::endl;
		std::cout << Stage << std::endl << std::endl;
		
		Boss.signForm(Interim);		
		std::cout << Interim << std::endl << std::endl;
		Boss.signForm(Stage);	
		std::cout << Stage << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "4 ---------------------------------------------------" << std::endl;

	try 
	{
		Bureaucrat Boss("boss", 12);
		Form Interim("Interim", 20, 15);
		Form EgalInterim("EgalInterim", 11, 19);

		std::cout << Boss;
		std::cout << Interim << std::endl;
		std::cout << EgalInterim << std::endl << std::endl;
		
		Boss.signForm(Interim);		
		std::cout << Interim << std::endl;
		std::cout << EgalInterim << std::endl << std::endl;

		EgalInterim = Interim;
		std::cout << "EgalInterim = Interim" << std::endl << std::endl; 		

		std::cout << Interim << std::endl;
		std::cout << EgalInterim << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
