/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:20:32 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/25 12:43:49 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include <iostream>


void ft_addOne(int &nb)
{
	nb += 1;
}

void ft_toUp(char &c)
{
	c = std::toupper(c);
}

void ft_print(char c)
{
	std::cout << c;
}


int main()
{
	int arNb[5] = {0, 10, 222, 543, 1000};
	for (int i = 0; i < 5; i++)
		std::cout << arNb[i] << ", ";
	std::cout << std::endl << "(iter)" << std::endl;
	
	iter(arNb, 5, ft_addOne);
	for (int i = 0; i < 5; i++)
		std::cout << arNb[i] << ", ";
	std::cout << std::endl;

	std::cout << "---------------------------------------------------" << std::endl;

	char text[27] = "le texte est petit de base";

	std::cout << text << std::endl << "(iter)" << std::endl;

	iter(text, 27, ft_toUp);
	iter(text, 27, ft_print);
	std::cout << std::endl;

	std::cout << "---------------------------------------------------" << std::endl;
}
