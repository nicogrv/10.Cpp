/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:22:36 by ngriveau          #+#    #+#             */
/*   Updated: 2023/11/08 15:23:24 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

int	main(void)
{
	Data *myData = new Data;
	Serializer 	s;
		
	myData->nbr = 1;
	myData->str = "Nico";
	
	std::cout << "int : " << s.serialize(myData) << std::endl;
	std::cout << "int : " << s.deserialize(s.serialize(myData))->nbr << std::endl;
	std::cout << "str : " << s.deserialize(s.serialize(myData))->str << std::endl;
	
	delete myData;
	
	return (0);
}
