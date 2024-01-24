/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:20:32 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/23 17:18:20 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include <iostream>


int ft_addOne(int nb)
{
	nb += 1;
	return nb;
}

char ft_toUp(char c)
{
	return std::toupper(c);
}


int main()
{
	int arNb[5] = {0, 1, 2, 5, 10};
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
	for (int i = 0; i < 27; i++)
		std::cout << text[i];
	std::cout << std::endl;

	std::cout << "---------------------------------------------------" << std::endl;
}