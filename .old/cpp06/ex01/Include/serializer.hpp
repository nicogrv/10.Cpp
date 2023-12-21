/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:27:46 by ngriveau          #+#    #+#             */
/*   Updated: 2023/11/08 15:28:13 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <iostream>

struct Data
{
	int			nbr;
	std::string	str;
};

class Serializer
{
	public :

		Serializer(void);
		Serializer(const Serializer &cpy);
		~Serializer();
		Serializer	&operator=(const Serializer &cpy);

		uintptr_t serialize(Data *data);
		Data* deserialize(uintptr_t raw);
		
};

#endif