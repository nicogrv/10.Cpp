/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:47:48 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/19 15:53:01 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
	#define PMERGEME_HPP
	#include <vector>
	#include <iostream>
	#include "./Pair.hpp"
	#include <iostream>
	#include <cstdlib>

/* ************************************************************************** */


template <unsigned int N>
class PmergeMe
{
	public:
		virtual ~PmergeMe() = 0;

		template <typename T>
		static int pmergeMeSort(std::vector<T> &vec);
	private:
};


int	pmergeMe(std::string str);
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
			pairVec.push_back(Pair<T>(&(*it), &(*(it+1))));
			(pairVec.end()-1)->sortDisorder();
	}
	return pairVec;

		
}
template <unsigned int N>
template <typename T>
int PmergeMe<N>::pmergeMeSort(std::vector<T> &vec)
{
	if (vec.size() < 2)
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
	PmergeMe<N-1>::pmergeMeSort(newVec);
	
	return 1;
}



template <>
struct PmergeMe<1>
{
public:
	template <typename T>
	static int	pmergeMeSort(std::vector<T> &vec)
	{
		(void)	vec;
		return 0;
	}
};

#endif