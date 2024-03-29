/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:38:38 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/22 13:41:21 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include <iostream>

struct Data
{
	int id;
	std::string name;
};


class Serializer
{
	public:
		

		static	uintptr_t serialize(Data* ptr);
		static	Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer &copy);
		Serializer operator=(Serializer &copy);
};


#endif