/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:50:01 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/25 15:36:06 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iterator> 
# include <vector>
# include <list>
# include <deque>
# include <iostream>

template <typename T>

unsigned int easyfind(T find, int number)
{
	unsigned int			i;
	typename T::iterator	it;

	i = 0;
	for (it = find.begin(); it != find.end(); it++)
	{
		i++;
		if (*it == number)
			return (i);
	}
	throw std::runtime_error("no occurrence");
}

#endif