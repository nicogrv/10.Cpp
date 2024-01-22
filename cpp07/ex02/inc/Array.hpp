/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:20:26 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/22 17:53:54 by ngriveau         ###   ########.fr       */
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
			this->tab = new T;
		}
		~Array()
		{
			std::cout << "DELETE" << std::endl;
			// if (this->tab)
			delete [] this->tab;
		}
		Array(Array &copy)
		{
			this->tab = new T[copy.lenght];
			this->lenght = copy.lenght;
		}
		Array &operator=(Array &copy)
		{
			delete [] this->tab;
			this->lenght = copy.lenght;
			std::cout << copy.lenght << std::endl;
			for (unsigned int i = 0; i < copy.lenght; i++)
				std::cout << "COPY" << std::endl;
			return (*this);
		}

		Array(unsigned int N)
		{
			this->lenght = N;
			this->tab = new T[N];
		}
	
	private:
		T *tab;
		unsigned int lenght;
		
};


#endif