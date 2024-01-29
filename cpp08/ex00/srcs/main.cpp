/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:26:29 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/29 11:38:01 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

int main( void )
{
	std::cout << "--------------------vector--------------------" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	try
	{
		int index = easyfind(vec, 10);
		std::cout << "OK index: " << index << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "--------------------deque--------------------" << std::endl;

	std::deque<int> deque;
	deque.push_back(10);
	deque.push_back(20);
	deque.push_back(30);
	deque.push_back(40);
	deque.push_back(50);
	deque.push_back(60);
	deque.push_back(100);

	try
	{
		int index = easyfind(deque, 40);
		std::cout << "OK index: " << index << std::endl;

		index = easyfind(deque, 110);
		std::cout << "OK index: " << index << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------list--------------------" << std::endl;

 	std::list<int> list;

    list.push_back(42);
    list.push_back(123);
    list.push_back(1254);

	try
	{
		int index = easyfind(list, 123);
		std::cout << "OK index: " << index << std::endl;

		index = easyfind(list, 1212);
		std::cout << "OK index: " << index << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
