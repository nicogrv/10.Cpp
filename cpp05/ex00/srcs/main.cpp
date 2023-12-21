/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:24:14 by ngriveau          #+#    #+#             */
/*   Updated: 2023/12/21 17:09:26 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
	
	Bureaucrat nothing;
	Bureaucrat justName("Alain");
	Bureaucrat justGrade(9);
	Bureaucrat everything("Benoit", 29);
	
	Bureaucrat equal;
	equal = everything;
	Bureaucrat copy(everything);
	

	std::cout << "nothing = \t" << nothing;
	std::cout << "justName = \t" << justName;
	std::cout << "justGrade = \t" << justGrade;
	std::cout << "everything = \t" << everything;

	std::cout << "---------------------------------------------------" << std::endl;
	
	std::cout << "equal = everything\t" << equal;
	std::cout << "copy(everything)\t" << copy;

	std::cout << "---------------------------------------------------" << std::endl;
	
	std::cout << "everything.getName() = " << everything.getName() << std::endl;
	std::cout << "everything.getGrade() = " << everything.getGrade() << std::endl;

	std::cout << "---------------------------------------------------" << std::endl;


	Bureaucrat Low(149);

	try 
	{
		std::cout << Low.getGrade() << std::endl;
		Low.decrement();
		std::cout << Low.getGrade() << std::endl;
		Low.decrement();
	} 
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << Low.getGrade() << std::endl;

	std::cout << "---------------------------------------------------" << std::endl;

	Bureaucrat High(2);

	try 
	{
		std::cout << High.getGrade() << std::endl;
		High.increment();
		std::cout << High.getGrade() << std::endl;
		High.increment();
	} 
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << High.getGrade() << std::endl;

	return 0;
}
