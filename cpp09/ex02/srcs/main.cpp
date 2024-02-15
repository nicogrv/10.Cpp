/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:26:29 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/15 17:12:41 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/* ************************************************************************** */

int main(void)
{
	std::vector<int> vec;
	vec.push_back(8);
	vec.push_back(16);
	vec.push_back(4);
	vec.push_back(62);
	vec.push_back(42);
	vec.push_back(183);
	vec.push_back(19);
	vec.push_back(23);
	vec.push_back(15);
	vec.push_back(37);
	printVec(vec);
	pmergeMe<int>(vec, 2);
	return 0;
}

/* ************************************************************************** */
