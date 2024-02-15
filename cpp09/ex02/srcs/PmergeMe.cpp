/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:55:11 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/15 19:13:05 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/* ************************************************************************** */



/* ************************************************************************** */


void printVec(std::vector<int> &vec)
{
	std::vector<int>::iterator it;

	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != vec.end())
			std::cout << '|';
	}
	std::cout << std::endl;
}


int parsing(std::string str, std::vector<int> &vec)
{
    std::string tmp;
    for (unsigned long i = 0; i <= str.size(); i++)
    {
        if (std::isdigit(str[i]) || ((str[i] == '-' || str[i] == '+') && ((0 < i && str[i-1] == ' ') || i == 0) && std::isdigit(str[i+1])))
            tmp += str[i];
        else if ((str[i] == ' ' || i == str.size()) && tmp.size() != 0)
        {
            vec.push_back(std::atoi(tmp.c_str()));
            tmp = "";
        }
        else 
            return 1;
    }
    return 0;
}

int	pmergeMeSort(std::string str)
{
    std::vector<int> vec;
    // vec.push_back(8);
	// vec.push_back(16);
	// vec.push_back(4);
	// vec.push_back(62);
	// vec.push_back(42);
	// vec.push_back(183);
	// vec.push_back(19);
	// vec.push_back(23);
	// vec.push_back(15);
	// vec.push_back(37);
    if (parsing(str, vec))
    {
        std::cout << "Error: bad input" << std::endl;
        return 1;
    }
    printVec(vec);
    return 1;
}