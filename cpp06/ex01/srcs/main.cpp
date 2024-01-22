/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:26:29 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/22 13:48:10 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Serializer.hpp"

int main()
{
	// Serializer test;
	Data data;
	Data *returnData;
	uintptr_t ptr;

	data.id = 40;
	data.name = "Titou";

	ptr = Serializer::serialize(&data);
	
	
	returnData = Serializer::deserialize(ptr);

	std::cout << "Name: " << returnData->name << std::endl;
	std::cout << "Id: " << returnData->id << std::endl << std::endl;

	std::cout << "&ReturnData: " << returnData << std::endl;
	std::cout << "&data:       " << &data << std::endl;
	std::cout << "&ptr:        " << &ptr << std::endl;
	

}
