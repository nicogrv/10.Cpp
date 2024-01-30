/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:26:29 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/30 18:45:56 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main( void )
{
	try
	{
		Span span;
		span.addNumber(1);
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "------------------------------------------" << std::endl;
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
	{

	Span span(3);
	try
	{
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
		span.printTab();
	}
	}

	std::cout << std::endl << "------------------------------------------" << std::endl;

	try
	{
		Span span(192);
		span.addNumber(2);
		span.addNumber(-10);
		span.addNumber(10);
		span.addNumber(6);
		span.addNumber(-2);
		span.printTab();
		std::cout << std::endl;
		std::cout << "longestSpan:  " << span.longestSpan() << std::endl;
		std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------------------" << std::endl;
	try
	{
		Span span(100000);
		for (int i = 0; i < 100000; i++)
			span.addNumber(i+12*i*i+43);
		// span.printTab();
		std::cout << std::endl;
		std::cout << "longestSpan:  " << span.longestSpan() << std::endl;
		std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	{

	std::cout << std::endl << "------------------------------------------" << std::endl;
	Span span(8);
	try
	{
		span.addNumber(42);
		span.addNumber(12);
		span.addNumber(124);
		span.printTab();
		unsigned int tab[] = {1, 18};
    	std::vector<unsigned int> vec1(tab, tab + sizeof(tab) / sizeof(tab[0]));
		span.addNumbers<std::vector<unsigned int> >(vec1.begin(), vec1.end());
		span.printTab();

		unsigned int tab2[] = {1, 2, 3, 4};
    	std::vector<unsigned int> vec2(tab2, tab2 + sizeof(tab2) / sizeof(tab2[0]));
		span.addNumbers<std::vector<unsigned int> >(vec2.begin(), vec2.end());
		span.printTab();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error " << e.what() << '\n';
		span.printTab();
	}
	}
	
	std::cout << std::endl << "------------------------------------------" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
