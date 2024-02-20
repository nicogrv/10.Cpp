/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:47:48 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/20 16:29:14 by ngriveau         ###   ########.fr       */
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


int	pmergeMe(char **str);


template <typename T>
void printVec(std::vector<T> &vec);

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

template <typename T>
int binarySort(std::vector<T> &vec, T *element)
{
	int min = 0;
	int max = vec.size();
	int split = -1;
	while (1 < max - min)
	{
		if (*element < vec[0])
		{
			split = 0; 
			break ;
		}
		std::cout << RED << min << " " << split << " " << max << NC <<  std::endl;
		split = ((max - min) / 2)+min;
		std::cout << ORANGE <<  min << " " << split << " " << max << NC <<  std::endl;
		std::cout << "Check: " << *element << " " << vec[split] << NC <<  std::endl;
		if (*element < vec[split])
		{
			max = split;
			
			std::cout << PURPLE <<  "max = " << split << std::endl;
		}
		else
		{
			min = split;
			std::cout << PURPLE << "min = " << split << std::endl;
		}
		std::cout << GREEN << min << " " << split << " " << max << NC <<  std::endl;
	}
	if (vec[split] < *element)
		split++;
	if (element)
	std::cout << LIGHTBLUE << "Insert index: " << split << NC <<  std::endl;
	return split;
}

template <typename T>
std::vector<T> insertPairs(std::vector<Pair<T> > &vec, T *impair)
{
    std::vector<T> newVec;
	int index;
    newVec.push_back(vec[0].getB());
    newVec.push_back(vec[0].getA());
    typename std::vector<Pair<T> >::iterator it;
    
    for (it = vec.begin()+1; it != vec.end(); it++)
	{
    	std::cout << std::endl<< LIGHTPURPLE <<  "Insert: " << (*it).getA() << std::endl;
        newVec.push_back((*it).getA());
	}
	if (impair)
	{
		newVec.insert(newVec.begin() + binarySort(newVec, impair), *impair);
	}
    printVec(newVec);
	for (it = vec.begin()+1; it != vec.end(); it++)
	{
    	std::cout << std::endl<< LIGHTPURPLE <<  "Insert: " << (*it).getB() << std::endl;
		index = binarySort(newVec, &((*it).getB()));
		newVec.insert(newVec.begin() + index, (*it).getB());
		printVec(newVec);
	
	}
	std::cout << DARKGRAY << "Fi print newVec: " << std::endl;
    printVec(newVec);
	// for (it = vec.begin()+1; it != vec.end(); it++)
        // newVec.insert(binarySort(newVec, ));
	// binarySort(newVec, impair);
    return newVec;
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
        std::cout << LIGHTRED << "\t\t---IMPAIR---" << NC <<  std::endl;
    }
    else
    {
        impair = NULL;
        std::cout << LIGHTGREEN << "\t\t---PAIR---" << NC <<  std::endl;
    }
	// std::cout << GREEN << "Impair: " << impair << " " << &impair << std::endl;
    std::vector<Pair<T> > newVec = makePair(vec);
    printVec(newVec);
	std::cout << DARKGRAY << "\t----PMERGEME: " << N-1 << "----" << std::endl;
    PmergeMe<N-1>::pmergeMeSort(newVec);
	std::cout << DARKGRAY << "\t---INSERTPAIR: " << N << "---" << std::endl;

    vec = insertPairs(newVec, impair);
    
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
