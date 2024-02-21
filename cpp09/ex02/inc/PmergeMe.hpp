/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:47:48 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/21 16:19:32 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
	#define PMERGEME_HPP
	#include <vector>
	#include <deque>
	#include <iostream>
	#include "./Pair.hpp"
	#include <iostream>
	#include <cstdlib>
	#include <sys/time.h>
	#include <algorithm>
/* ************************************************************************** */


template <unsigned int N>
class PmergeMe
{
	public:
		virtual ~PmergeMe() = 0;

		template <typename T>
		static int pmergeMeSortVec(std::vector<T> &vec);

		template <typename T>
		static int pmergeMeSortDeq(std::deque<T> &deq);

		static int	jacobsthal(int n1, int n2);
	private:
};

template <unsigned int N>
int	PmergeMe<N>::jacobsthal(int n1, int n2)
{
	return (n1 + 2 * n2);
}


int	pmergeMe(int c, char **str);


template <typename T>
void printVec(std::vector<T> &vec, bool print);

template <typename T>
std::vector<Pair<T> > makePairVec(std::vector<T> &vec)
{
	std::vector<Pair<T> >				pairVec;
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



template <typename T>
typename std::vector<T>::iterator	binarySearchVec(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last, T &toFind)
{
	size_t								distance;
	typename std::vector<T>::iterator	mid;

	distance = std::distance(first, last);
	if (distance < 2)
	{
		if (*first >= toFind)
		{
			std::cout << LIGHTCYAN << "1\n";
			return first;
		}
		else if (distance == 0 || (distance == 1 && *(first + 1) >= toFind))
		{
			std::cout << LIGHTCYAN << "2\n";	
			return first + 1;
		}
		else
		{
			std::cout << LIGHTCYAN << "3\n";
			return first + 2;
		}
	}

	mid = first + distance / 2;
	
	std::cout << ORANGE << toFind << " " << *first << " " << *mid << " " << NC << std::endl; 
	if (toFind == *mid)
		return mid;
	else if (toFind < *mid)
	{
		return binarySearchVec(first, mid, toFind);
	}
	else
	{
		return binarySearchVec(mid + 1, last, toFind);
		
	}
}

template <typename T>
std::vector<T> insertPairsVec(std::vector<Pair<T> > &vec, T *impair)
{
    std::vector<T> newVec;
	// int index;
    newVec.push_back(vec[0].getB());
    newVec.push_back(vec[0].getA());
    typename std::vector<Pair<T> >::iterator it;
    
    for (it = vec.begin()+1; it != vec.end(); it++)
	{
		printVec(newVec, true);
    	std::cout << std::endl<< LIGHTPURPLE <<  "Insert: " << (*it).getA() << std::endl;
        newVec.push_back((*it).getA());
		printVec(newVec, true);
	}
	if (impair)
	{
		std::cout << BLUE << "Insert: " << *impair << std::endl;
		newVec.insert(binarySearchVec(newVec.begin(), newVec.end(), *impair), *impair);
	}

	int j_lower	= 1;
	int j_upper	= 1;
	int tmp		= 1;
	typename std::vector<T>::iterator itlast;
	while (j_upper < static_cast<int>(vec.size()))
	{
		tmp = j_lower;
		j_lower = j_upper;
		j_upper = std::min(PmergeMe<42>::jacobsthal(j_lower, tmp), static_cast<int>(vec.size()));
		for (int i = j_upper - 1; i >= j_lower; i--)
		{
			if (j_upper == static_cast<int>(vec.size()))
				itlast = newVec.end();
			else
				itlast = newVec.begin() + j_upper + j_lower - 1;
			printVec(newVec, true);
			std::cout << BLUE << "Insert: " << vec[i].getB() << std::endl;
			newVec.insert(binarySearchVec(newVec.begin(), itlast, vec[i].getB()), vec[i].getB());
			printVec(newVec, true);
		}
	}
	
    // // printVec(newVec);
	// for (it = vec.begin()+1; it != vec.end(); it++)
	// {
    // 	// std::cout << std::endl<< LIGHTPURPLE <<  "Insert: " << (*it).getB() << std::endl;
	// 	index = binarySortVec(newVec, &((*it).getB()));
	// 	newVec.insert(newVec.begin() + index, (*it).getB());
	// 	// printVec(newVec);
	
	// }
	// std::cout << DARKGRAY << "Fi print newVec: " << std::endl;
    // printVec(newVec);
	// for (it = vec.begin()+1; it != vec.end(); it++)
        // newVec.insert(binarySort(newVec, ));
	// binarySort(newVec, impair);
    return newVec;
}

template <unsigned int N>
template <typename T>
int PmergeMe<N>::pmergeMeSortVec(std::vector<T> &vec)
{
    if (vec.size() < 2)
        return 0;
    T *impair;
    if (vec.size() % 2)
    {   
        impair = &vec[vec.size()-1];
        // std::cout << LIGHTRED << "\t\t---IMPAIR---" << NC <<  std::endl;
    }
    else
    {
        impair = NULL;
        // std::cout << LIGHTGREEN << "\t\t---PAIR---" << NC <<  std::endl;
    }
	// std::cout << GREEN << "Impair: " << impair << " " << &impair << std::endl;
    std::vector<Pair<T> > newVec = makePairVec(vec);
    // printVec(newVec);
	// std::cout << DARKGRAY << "\t----PMERGEME: " << N-1 << "----" << std::endl;
    PmergeMe<N-1>::pmergeMeSortVec(newVec);
	// std::cout << DARKGRAY << "\t---INSERTPAIR: " << N << "---" << std::endl;

    vec = insertPairsVec(newVec, impair);
    
    return 1;
}



























template <typename T>
std::deque<Pair<T> > makePairDeq(std::deque<T> &deq)
{
	std::deque<Pair<T> >				pairVec;
	typename std::deque<T>::iterator	it;
	if (deq.size() < 2)
		return pairVec;
	for(it = deq.begin(); it != deq.end() && it+1 != deq.end(); it += 2)
	{
			pairVec.push_back(Pair<T>(&(*it), &(*(it+1))));
			(pairVec.end()-1)->sortDisorder();
	}
	return pairVec;

		
}

template <typename T>
typename std::deque<T>::iterator	binarySearchDeq(typename std::deque<T>::iterator first, typename std::deque<T>::iterator last, T &toFind)
{
	size_t								distance;
	typename std::deque<T>::iterator	mid;

	distance = std::distance(first, last);
	if (distance < 2)
	{
		if (*first >= toFind)
			return first;
		else if (distance == 0 || (distance == 1 && *(first + 1) >= toFind))
		{
			return first + 1;
		}
		else
			return first + 2;
	}

	mid = first + distance / 2;
	if (toFind == *mid)
		return mid;
	else if (toFind < *mid)
		return binarySearchDeq(first, mid, toFind);
	else
		return binarySearchDeq(mid + 1, last, toFind);
}

template <typename T>
std::deque<T> insertPairsDeq(std::deque<Pair<T> > &deque, T *impair)
{
    std::deque<T> newdeque;
	// int index;
    newdeque.push_back(deque[0].getB());
    newdeque.push_back(deque[0].getA());
    typename std::deque<Pair<T> >::iterator it;
    
    for (it = deque.begin()+1; it != deque.end(); it++)
	{
    	// std::cout << std::endl<< LIGHTPURPLE <<  "Insert: " << (*it).getA() << std::endl;
        newdeque.push_back((*it).getA());
	}
	if (impair)
	{
		newdeque.insert(binarySearchDeq(newdeque.begin(), newdeque.end(), *impair), *impair);
	}
    // printdeque(newdeque);
	int j_lower	= 1;
	int j_upper	= 1;
	int tmp		= 1;
	typename std::deque<T>::iterator itlast;
	while (j_upper < static_cast<int>(deque.size()))
	{
		tmp = j_lower;
		j_lower = j_upper;
		j_upper = std::min(PmergeMe<42>::jacobsthal(j_lower, tmp), static_cast<int>(deque.size()));
		for (int i = j_upper - 1; i >= j_lower; i--)
		{
			if (j_upper == static_cast<int>(deque.size()))
				itlast = newdeque.end();
			else
				itlast = newdeque.begin() + j_upper + j_lower - 1;
			newdeque.insert(binarySearchDeq(newdeque.begin(), itlast, deque[i].getB()), deque[i].getB());
		}
	}
	// for (it = deque.begin()+1; it != deque.end(); it++)
	// {
    // 	// std::cout << std::endl<< LIGHTPURPLE <<  "Insert: " << (*it).getB() << std::endl;
	// 	index = binarySortDeq(newdeque, &((*it).getB()));
	// 	newdeque.insert(newdeque.begin() + index, (*it).getB());
	// 	// printVec(newVec);
	
	// }
	// std::cout << DARKGRAY << "Fi print newVec: " << std::endl;
    // printVec(newVec);
	// for (it = vec.begin()+1; it != vec.end(); it++)
        // newVec.insert(binarySort(newVec, ));
	// binarySort(newVec, impair);
    return newdeque;
}

template <unsigned int N>
template <typename T>
int PmergeMe<N>::pmergeMeSortDeq(std::deque<T> &deq)
{
    if (deq.size() < 2)
        return 0;
    T *impair;
    if (deq.size() % 2)
    {   
        impair = &deq[deq.size()-1];
        // std::cout << LIGHTRED << "\t\t---IMPAIR---" << NC <<  std::endl;
    }
    else
    {
        impair = NULL;
        // std::cout << LIGHTGREEN << "\t\t---PAIR---" << NC <<  std::endl;
    }
	// std::cout << GREEN << "Impair: " << impair << " " << &impair << std::endl;
    std::deque<Pair<T> > newdeq = makePairDeq(deq);
    // printdeq(newdeq);
	// std::cout << DARKGRAY << "\t----PMERGEME: " << N-1 << "----" << std::endl;
    PmergeMe<N-1>::pmergeMeSortDeq(newdeq);
	// std::cout << DARKGRAY << "\t---INSERTPAIR: " << N << "---" << std::endl;

    deq = insertPairsDeq(newdeq, impair);
    
    return 1;
}
























template <>
struct PmergeMe<1>
{
public:
	template <typename T>
	static int	pmergeMeSortVec(std::vector<T> &vec)
	{
		(void)	vec;
		return 0;
	}

	template <typename T>
	static int	pmergeMeSortDeq(std::deque<T> &deq)
	{
		(void)	deq;
		return 0;
	}
};

#endif
