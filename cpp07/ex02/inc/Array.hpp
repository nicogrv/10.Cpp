/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:20:26 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/23 15:38:09 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>

class Array
{
	public:
		Array()
		{
			this->lenght = 1;
			this->tab = new T[1]();
		}

		~Array()
		{
			delete [] this->tab;
		}

		Array(Array &copy)
		{
			this->tab = new T[copy.lenght]();
			this->lenght = copy.lenght;
			for (unsigned int i = 0; i < copy.lenght; i++)
				this->tab[i] = copy.tab[i];
		}

		Array &operator=(Array &copy)
		{
			delete [] this->tab;
			this->lenght = copy.lenght;
			this->tab = new T[this->lenght]();
			for (unsigned int i = 0; i < copy.lenght; i++)
				this->tab[i] = copy.tab[i];
			return (*this);
		}

		Array(unsigned int N)
		{
			this->lenght = N;
			this->tab = new T[N]();
		}

		T& operator [](unsigned int idx)
		{
			if (0 <= idx && idx < this->lenght)
				return this->tab[idx];
			throw std::runtime_error("Out of range");
		}


		unsigned int size()
		{	return (this->lenght);}

	private:
		T *tab;
		unsigned int lenght;
		
};


#endif