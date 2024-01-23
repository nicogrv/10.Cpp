/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:16:05 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/23 16:31:23 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate()
{
    clock_t currentTime = clock();
	int nb = currentTime % 3;
	Base *tmp;

	tmp = NULL;
	if (nb == 0)
	{
		std::cout  << "A -> ";
		tmp = new A;
	}
	else if (nb == 1)
	{
		tmp = new B;
		std::cout  << "B -> ";
	}
	else 
	{
		tmp = new C;
		std::cout << "C -> ";
	}
	return tmp;
}


void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
			std::cout << "ptr A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "ptr B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "ptr C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "ref A" <<std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "ref B" <<std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "ref C" <<std::endl;
	} 
	catch (std::exception &e)
	{}
}

int main()
{
	Base *base;
	for (int i = 0; i < 10; i++)
	{
		base = generate();
		if (i%2)
			identify(base);
		else
			identify(*base);
		std::cout << "------" << std::endl;
		delete base;
		
	}

	return 0;
}