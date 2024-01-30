/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:26:29 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/30 14:34:46 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"


template <typename T>

void exec()
{
	
}




int main( void )
{
	std::cout << "--------------------deque--------------------" << std::endl << std::endl;
	{

	std::deque<int> deque;
	deque.push_back(10);
	deque.push_back(20);
	deque.push_back(30);
	deque.push_back(40);
	deque.push_back(50);
	deque.push_back(60);
	deque.push_back(40);
	deque.push_back(100);

	try
	{

		std::deque<int>::iterator index = easyfind(deque, 40);
		std::cout << "OK index: " << &(*index) << std::endl;
		printTab(deque);

		index = easyfind(deque, 110);
		std::cout << "OK index: " << &(*index) << std::endl;
		printTab(deque);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	}

	std::cout << "--------------------vector--------------------" << std::endl << std::endl;
	{

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	try
	{
		printTab(vec);
		std::vector<int>::iterator index = easyfind(vec, 6);
		std::cout << "OK index: " << &(*index) << std::endl;
		*index = 12;
		std::cout << &(*index) << " index = 12 " << std::endl;
		
		printTab(vec);
		
		std::vector<int>::iterator index2 = easyfind(vec, 12);
		std::cout << "OK index: " << &(*index2) << std::endl;
		printTab(vec);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	}
	

	std::cout << "--------------------list--------------------" << std::endl << std::endl;

 	std::list<int> list;

    list.push_back(42);
    list.push_back(123);
    list.push_back(42);

	try
	{
		std::list<int>::iterator index = easyfind(list, 42);
		std::cout << "OK index: " << &(*index) << std::endl;
		printTab(list);

		std::list<int>::iterator index2 = easyfind(list, 153);
		std::cout << "OK index: " << &(*index2) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
