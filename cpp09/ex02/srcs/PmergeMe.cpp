/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:55:11 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/20 19:27:55 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/* ************************************************************************** */



/* ************************************************************************** */


template <typename T>
void printVec(std::vector<T> &vec, bool print)
{
    if (!print)
        return ;
    std::string color[6] = {LIGHTRED, YELLOW, LIGHTGREEN, LIGHTCYAN, LIGHTBLUE, LIGHTPURPLE};
	typename std::vector<T>::iterator it;

    int i = 0;
    std::cout << color[i%(sizeof(color)/sizeof(color[0]))];
	for (it = vec.begin(); it != vec.end(); it++)
	{
            i++;
		std::cout << *it;
		if (it + 1 != vec.end())
        {
			std::cout << NC << '|' << color[i%(sizeof(color)/sizeof(color[0]))];
        }
        
	}
	std::cout << NC << std::endl;
}

template <typename T>
void printDeq(std::deque<T> &deq, bool print)
{
    if (!print)
        return ;
    std::string color[6] = {LIGHTRED, YELLOW, LIGHTGREEN, LIGHTCYAN, LIGHTBLUE, LIGHTPURPLE};
	typename std::deque<T>::iterator it;

    int i = 0;
    std::cout << color[i%(sizeof(color)/sizeof(color[0]))];
	for (it = deq.begin(); it != deq.end(); it++)
	{
            i++;
		std::cout << *it;
		if (it + 1 != deq.end())
        {
			std::cout << NC << '|' << color[i%(sizeof(color)/sizeof(color[0]))];
        }
        
	}
	std::cout << NC << std::endl;
}



int to_int(char *s)
{
     if ( s == NULL || *s == '\0' )
        throw std::invalid_argument("null or empty string argument");

     bool negate = (s[0] == '-');
     if ( *s == '+' || *s == '-' ) 
         ++s;

     if ( *s == '\0')
        throw std::invalid_argument("sign character only.");

     int result = 0;
     while(*s)
     {
          if ( *s < '0' || *s > '9' )
            throw std::invalid_argument("invalid input string");
          result = result * 10  - (*s - '0');
          ++s;
     }
     return negate ? result : -result;
}



bool parsingDeq(char **str, std::deque<int> &deq)
{
    int i = 0;
    int nb;
    while (str[++i])
    {
        try
        {
            nb = to_int(str[i]);
            deq.push_back(nb);
        }
        catch(const std::exception& e)
        {
            std::cout << LIGHTRED << e.what() << NC << std::endl;
            return true;
        }
    }
    std::cout << std::endl << std::endl;
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
    {
        for (std::deque<int>::iterator iti = it+1; iti != deq.end(); iti++)
        {
            if (*it == *iti)
            {
                std::cout << "Number of duplicates: " << *it << std::endl;
                return true;
            }
        }
        if (*it < 0)
        {
            std::cout << "Negative number: " << *it << std::endl;
            return true;
        }
    }
    return false;
}

bool parsingVec(char **str, std::vector<int> &vec)
{
    int i = 0;
    int nb;
    while (str[++i])
    {
        try
        {
            nb = to_int(str[i]);
            vec.push_back(nb);
        }
        catch(const std::exception& e)
        {
            std::cout << LIGHTRED << e.what() << NC << std::endl;
            return true;
        }
    }
    std::cout << std::endl << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        for (std::vector<int>::iterator iti = it+1; iti != vec.end(); iti++)
        {
            if (*it == *iti)
            {
                std::cout << "Number of duplicates: " << *it << std::endl;
                return true;
            }
        }
        if (*it < 0)
        {
            std::cout << "Negative number: " << *it << std::endl;
            return true;
        }
    }
    return false;
}


int checkSortVec(std::vector<int> &vec)
{
    std::vector<int>::iterator it;

    for (it = vec.begin(); it+1 != vec.end(); it++)
    {
        if (*(it+1)<=*it)
            return 1;
    }
    return 0;
}

int checkSortDeq(std::deque<int> &deq)
{
    std::deque<int>::iterator it;

    for (it = deq.begin(); it+1 != deq.end(); it++)
    {
        if (*(it+1)<=*it)
            return 1;
    }
    return 0;
}


int	pmergeMe(int c, char **str)
{
    bool print = true;
    struct timeval				tv;
	size_t						start;
	size_t						inter;
	size_t						end;
    std::vector<int>            vec;
    std::deque<int>             deq;
    
/* ************************************************************************** */
    gettimeofday(&tv, 0);
	start = 1000000 * tv.tv_sec + tv.tv_usec;
    if (parsingVec(str, vec))
        return 1;
    std::cout << "Input: " << std::endl;
    printVec(vec, print);
    PmergeMe<20>::pmergeMeSortVec(vec);
    std::cout << "Vec sort: " << std::endl;
    printVec(vec, print);
    gettimeofday(&tv, 0);
	inter = 1000000 * tv.tv_sec + tv.tv_usec;
/* ************************************************************************** */
    if (parsingDeq(str, deq))
        return 1;
    PmergeMe<20>::pmergeMeSortDeq(deq);
    std::cout << "Deq sort: " << std::endl;
    printDeq(deq, print);
    gettimeofday(&tv, 0);
	end = 1000000 * tv.tv_sec + tv.tv_usec;
/* ************************************************************************** */
    // deq.push_back(13);
    std::cout << "Time to process a range of "<< c-1 << " elements with std::Vector : " << inter-start << " us" << std::endl;
    std::cout << "Time to process a range of "<< c-1 << " elements with std::Deque  : " << end-inter << " us" << std::endl;
    if (checkSortVec(vec) || checkSortDeq(deq))
        return 1;
    else 
        return 0;
}