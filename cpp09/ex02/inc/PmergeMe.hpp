/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:47:48 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/15 18:52:45 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
	#define PMERGEME_HPP
	#include <vector>
	#include <iostream>
	#include "./Pair.hpp"

/* ************************************************************************** */

int	pmergeMeSort(std::string str);
void printVec(std::vector<int> &vec);

template <typename T>
std::vector<Pair<T> > makePair(std::vector<T> &vec)
{
	std::vector<Pair<T> > pairVec;
	typename std::vector<T>::iterator it;
	if (vec.size() < 2)
		return pairVec;
	for(it = vec.begin(); it != vec.end() && it+1 != vec.end(); it += 2)
	{
			pairVec.push_back(Pair<T>(*it, *(it+1)));
			(pairVec.end()-1)->sortDisorder();
	}
	return pairVec;

		
}

template <typename T>
int pmergeMeSort(std::vector<T> &vec, int iter)
{
	(void) vec;
	(void) iter;
	return 1;
	if (vec.size() < 2 && iter)
		return 0;
	T *impair;
	if (vec.size() % 2)
	{	
		impair = &vec[vec.size()-1];
		std::cout << "IMPAIR" << std::endl;
	}
	else
	{
		impair = NULL;
		std::cout << "PAIR" << std::endl;
	}
	std::vector<Pair<T> > newVec = makePair(vec);
	
	return 1;
}





#endif