/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:50:01 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/30 15:09:13 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iterator> 
# include <vector>
# include <list>
# include <deque>
# include <iostream>
# include <algorithm>

template <typename T>

typename T::iterator	easyfind(T &find, int number)
{
	typename T::iterator it =  std::find(find.begin(), find.end(), number);
	if (it != find.end())
		return (it);
	throw std::runtime_error("NO");
}

	
template <typename T>

void printTab(T &tab)
{
	typename T::iterator	it = --tab.begin();

	std::cout << "----==PrintTab==----" << std::endl;
	while (++it != tab.end())
		std::cout << &(*it) << ": " << *it << std::endl;
	std::cout << "-----==------==-----" << std::endl << std::endl;

}

#endif