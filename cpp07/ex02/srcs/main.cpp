/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:20:03 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/25 12:41:43 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"



template <typename T>

void displayArray(Array<T> array, Array<T> array2, std::string name1, std::string name2)
{
	std::cout << name1 <<": ";
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << i << ":" << array[i] << " ";
	std::cout << std::endl;
	std::cout << name2 << ": ";
	for (unsigned int i = 0; i < array2.size(); i++)
		std::cout << i << ":" << array2[i] << " ";
	std::cout << std::endl << std::endl;
}





int main()
{
	std::cout << std::endl << "------------------Array_int(0)-------------------" << std::endl;
	try
	{
		Array<int> Array_int;	
		std::cout << "Array_int size : " << Array_int.size() << std::endl;
		std::cout << "Array_int[0]: " << Array_int[0] << std::endl;
		std::cout << "Array_int[0] = 15"  << std::endl;
		Array_int[0] = 15;
		std::cout << "Array_int[0]: " << Array_int[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "------------------Array_int(1)-------------------" << std::endl;
	
	try
	{
		Array<int> Array_int(1);	
		std::cout << "Array_int size : " << Array_int.size() << std::endl;
		std::cout << "Array_int[0]: " << Array_int[0] << std::endl;
		std::cout << "Array_int[0] = 15"  << std::endl;
		Array_int[0] = 15;
		std::cout << "Array_int[0]: " << Array_int[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "------------------Array_string(1)-------------------" << std::endl ;

	try
	{
		Array<std::string> Array_string(1) ;
		std::cout << "Array_string size : " << Array_string.size() << std::endl;
		std::cout << "Array_string[0]: " << Array_string[0] << std::endl;
		std::cout << "Array_string[0] = Bonjour les amis"  << std::endl;
		Array_string[0] = "Bonjour les amis";
		std::cout << "Array_string[0]: " << Array_string[0] << std::endl;
	}	
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "------------------EgalArray-------------------" << std::endl ;



	try
	{
		Array<std::string> array(5);
		Array<std::string> egalArray(10);
		std::cout << "array size    : " << array.size() << std::endl;
		std::cout << "egalArray size: " << egalArray.size() << std::endl;
		std::cout << std::endl;

		array[0] = "|Bonjour|";
		array[2] = "|Ca va ?|";
		std::cout << "array[0] = |Bonjour| && array[2] = |Ca va ?|" << std::endl << std::endl;

		displayArray(array, egalArray, "array", "egalArray");

		egalArray = array;
		std::cout << "egalArray = array" << std::endl << std::endl;
		
		displayArray(array, egalArray, "array", "egalArray");

		std::cout << "array size    : " << array.size() << std::endl;
		std::cout << "egalArray size: " << egalArray.size() << std::endl << std::endl;;
		array[4] = "|Bien|";
		std::cout << "array[4] = |Bien|" << std::endl << std::endl;

		displayArray(array, egalArray, "array", "egalArray");

		Array<std::string> copyArray(array);
		
		std::cout << std::endl << "------------------CopyArray-------------------" << std::endl ;

		
		displayArray(array, copyArray, "array", "copyArray");
		
		array[1] = "|Test|";
		std::cout << "array[1] = |Test|" << std::endl << std::endl;
		
		displayArray(array, copyArray, "array", "copyArray");

		std::cout << "array size    : " << array.size() << std::endl;
		std::cout << "copyArray size: " << copyArray.size() << std::endl;
		std::cout << std::endl;

		
	}	
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "------------------CopyArray-------------------" << std::endl ;

	Array<std::string> array(10);
	std::cout << "New array(10)" << std::endl;
	try
	{
		std::cout << "try array[0]: ";
		array[0];
		std::cout << "OK" << std::endl;
		std::cout << "try array[-1]: ";
		array[-1];
	}	
	catch (std::exception &e)
	{
		std::cout << "Error exception: " << e.what() << std::endl << std::endl;
	}
	try
	{
		std::cout << "try array[9]: ";
		array[9];
		std::cout << "OK" << std::endl;
		std::cout << "try array[10]: ";
		array[10];
	}	
	catch (std::exception &e)
	{
		std::cout << "Error exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------int(5)-------------------" << std::endl ;

	try
	{
		Array<int> array(5);
		
		std::cout << "Int (null): ";
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << array[i] << ", ";
		std::cout << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

		std::cout << std::endl << "------------------Char(5)-------------------" << std::endl ;

	try
	{
		Array<char> array(5);
		
		std::cout << "Char (null): ";
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << array[i] << ", ";
		std::cout << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}