/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:55:11 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/20 17:53:09 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/* ************************************************************************** */



/* ************************************************************************** */


template <typename T>
void printVec(std::vector<T> &vec)
{
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



bool parsing(char **str, std::vector<int> &vec)
{
    int i = 0;
    while (str[++i])
    {
        try
        {
            std::cout << LIGHTRED << str[i] << NC << " ";
            vec.push_back(to_int(str[i]));
        }
        catch(const std::exception& e)
        {
            std::cout << LIGHTRED << e.what() << NC << std::endl;
            return true;
        }
    }
    std::cout << std::endl << std::endl;
    return false;
}


int checkSort(std::vector<int> &vec)
{
    std::vector<int>::iterator it;

    for (it = vec.begin(); it+1 != vec.end(); it++)
    {
        // std::cout << RED << *(it+1) << " " << *it << NC << std::endl;
        if (*(it+1)<=*it)
            return 1;
        // std::cout << GREEN << *(it+1) << " " << *it << NC << std::endl;

        
    }
    return 0;
}


int	pmergeMe(char **str)
{
    struct timeval				tv;
	size_t						start;
	size_t						end;
    std::vector<int> vec;
    if (parsing(str, vec))
        return 1;

    gettimeofday(&tv, 0);
	start = 1000000 * tv.tv_sec + tv.tv_usec;
    PmergeMe<20>::pmergeMeSort(vec);
    gettimeofday(&tv, 0);
	end = 1000000 * tv.tv_sec + tv.tv_usec;
    printVec(vec);
    std::cout << "Time taken: " << end-start << " seconds" << std::endl;
    return (checkSort(vec));
}