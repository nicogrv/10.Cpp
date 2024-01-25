/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:00:03 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/25 16:41:54 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <deque>
# include <list>
# include <iostream>


template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		~MutantStack() {}
		MutantStack(MutantStack &copy) : std::stack<T>(copy) {};
		MutantStack operator=(MutantStack &copy)
		{
			*this = copy;
			return this;
		}
		
		class iterator;

		iterator begin()
		{
			return iterator(this->c.begin());
		}
		
		iterator end()
		{
			return iterator(this->c.end());
		}
};

template <typename T>
class MutantStack<T>::iterator : public std::deque<T>::iterator
{
	public:
		iterator(typename std::deque<T>::iterator it) : std::deque<T>::iterator(it) {}
};

#endif