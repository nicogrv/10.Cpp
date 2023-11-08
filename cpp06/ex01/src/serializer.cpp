/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:27:42 by ngriveau          #+#    #+#             */
/*   Updated: 2023/11/08 15:18:35 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

Serializer::Serializer()
{
	return ;
}

Serializer::Serializer(const Serializer &mySerialize)
{
	*this = mySerialize;
	return ;
}

Serializer::~Serializer()
{
	return ;
}

Serializer	&	Serializer::operator=(const Serializer & mySerialize)
{
	(void)mySerialize;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}

