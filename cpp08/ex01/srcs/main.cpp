/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:26:29 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/24 18:17:47 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main( void )
{
	try
	{
		Span span(3);
		span.addNumber(1);
		span.addNumber(2);

		Span spancopy(span);
		std::cout << "Span spancopy(span)" << std::endl;
		span.printTab();
		spancopy.printTab();
		std::cout << "span     lenght: " << span.getLenght() << std::endl; 
		std::cout << "spancopy lenght: " << spancopy.getLenght() << std::endl; 
		span.addNumber(3);
		std::cout << "span.addNumber(3)" << std::endl;
		span.printTab();
		spancopy.printTab();
	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------------------" << std::endl;
	
	try
	{
		Span span(3);
		span.addNumber(1);
		span.addNumber(2);

		Span spanegal(0);
		std::cout << "Span spanegal(0)" << std::endl;
		span.printTab();
		spanegal.printTab();

		spanegal = span;
		std::cout << "spanegal = span" << std::endl;
		span.printTab();
		spanegal.printTab();
		
		std::cout << "span     lenght: " << span.getLenght() << std::endl; 
		std::cout << "spanegal lenght: " << spanegal.getLenght() << std::endl; 
		span.addNumber(3);
		std::cout << "span.addNumber(3)" << std::endl;
		span.printTab();
		spanegal.printTab();
	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------------------" << std::endl;

	try
	{
		Span span(3);
		span.addNumber(1);
		span.printTab();
		span.addNumber(2);
		span.printTab();
		span.addNumber(3);
		span.printTab();
		span.addNumber(4);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------------------" << std::endl;

	try
	{
		Span span(5);
		span.addNumber(2);
		span.addNumber(-10);
		span.addNumber(10);
		span.addNumber(6);
		span.addNumber(-1);
		span.printTab();
		std::cout << span.longestSpan() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
